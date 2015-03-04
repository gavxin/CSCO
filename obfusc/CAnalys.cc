#include "CAnalys.h"
using namespace std;

CAnalys::CAnalys()
{
	debugFlag=0;
};
CAnalys::~CAnalys()
{
};

void CAnalys::setCurrentCodeFile(CodeFile &file)
{
	currentTree = &file.tree;
	currentSymbolTable = file.symbolTable;
	yyin = file.file;
}


//set the debug mode of parser
void CAnalys::SetDebug(int d) 
{
	debugFlag=d;
	fprintf(stderr,"DEBUG MODE =%d\n",debugFlag);
};
// Check the token in the Symbol Table, if it is a TYPE_NAME.
int CAnalys::check_type(TokenValue &theValue)
{
	string str = (char *)theText;
	if ( currentSymbolTable->isExistType(str) ) {
		return TYPE_NAME;
	}
	return IDENTIFIER;
}

//instead of the true Lex ScanValue
int CAnalys::Scan()
{
	theTokenLocation.first_line=theLine;
	theTokenLocation.first_column=theColumn;
	int t=CLexer::ScanValue(theTokenValue);
	theTokenLocation.last_line=theLine;
	theTokenLocation.last_column=theColumn;
	theTokenLocation.text=(char *)theText;
	// custom property
	theTokenLocation.tokenId = t;
	theTokenLocation.theText = (char *)theText;
	//theTokenLocation.preString = notValueText;
	//notValueText = ""
	prestring2exstr();
	theTokenLocation.extraString = exstr;
	exstr = NULL;

	// Add to Symbol Table
	AddToSymbolTable(t,theTokenLocation);
	
	
	if(debugFlag)
	{
		fprintf(stderr,"TOKEN %d (l%d,c%d-l%d,c%d)=(%d)\"%*.*s\"\n",t,
			theTokenLocation.first_line,
			theTokenLocation.first_column,
			theTokenLocation.last_line,
			theTokenLocation.last_column,
			theTextLength,theTextLength,
			theTextLength,theTokenLocation.text);
    }
	return t;
};
// parser error...
void CAnalys::PrintError(char *s )
{
	
	fprintf(stderr,"%s\n",s);
	fprintf(stderr,"Stopped at or near token (line %d ,column %d -line %d ,column %d):\"%s\"\n",
				theTokenLocation.first_line, theTokenLocation.first_column,
				theTokenLocation.last_line, theTokenLocation.last_column,
				theTokenLocation.text);
};

// Add to Symbol Table.
void CAnalys::AddToSymbolTable(int t,TokenLocation l)
{
	switch (t) {
		case CParser::IDENTIFIER:

		//case CParser::CONST:

		//case CParser::STRING_LITERAL:

		//case CParser::TYPE_NAME:
			currentSymbolTable->ScanedIdentifier(t,l);
			break;
	}
}

void CAnalys::OnlyLexer()
{
	int t;
	while ( (t = Scan()) != 0 ) {
	}
}
// If found a typedef declaration. like:
// typedef int a;
// typedef (*a)(int);
// Will set symbol a as a TYPE_NAME.
void CAnalys::FindTPYEDEFDeclaration(Node *node)
{
	if ( !node->hasTypedefToken() ) {
		return;
	}

	vector<Node *> founds = vector<Node*>();

	Node *typedefName;
	// declaration_specifiers ';'
	if ( node->childNodes.size() == 2 ) {
		typedefName = node->getChild(0);
	// declaration_specifiers init_declarator_list ';'
	} else if ( node->childNodes.size() == 3 ) {
		typedefName = node->getChild(1);
	}
	typedefName->findIdentifierChildren(founds);

	vector<Node *>::iterator it;
	for( it = founds.begin() ; it != founds.end() ; it++) {
		// set the Node.
		(*it)->tokenId = CParser::TYPE_NAME;
		// tell SymbolTable that is a TYPE_NAME
		currentSymbolTable->ConvertIdentifier2TYPE_NAME((*it)->tokenString);
		currentSymbolTable->SetIdentifierDeclared((*it)->tokenString);
		// do more ??
	}
}

// Parser found a declaration.
void CAnalys::ParsedDeclaration(Node * node)
{
	// find TYPEDEF.
	FindTPYEDEFDeclaration(node);

	//cout << "found a declaration!" << endl;
	// find all identifier.
	vector<Node *> founds = vector<Node*>();
	node->findIdentifierChildren(founds);
	
	//cout << "found :" << founds.size() << endl;
	// set every identifier  declared.
	vector<Node *>::iterator it;
	for( it = founds.begin() ; it != founds.end() ; it++) {
		currentSymbolTable->SetIdentifierDeclared((*it)->tokenString);
		// do more ??
	}
	// 
	//declaration_specifiers
	Node *desp = node->getChild(0);
	
	if ( desp->hasExternToken() ) {
		//cout << "Extern !!" << endl;
	}
}
// Parser found a function definition.
void CAnalys::ParsedFunctionDefinition(Node *functionNode, Node *declaratorNode)
{
	// find the function name identifier.
	vector<Node *> founds = vector<Node*>();
	declaratorNode->findIdentifierChildren(founds);

	//cout << "found :" << founds.size() << endl;
	
	//assert(founds.size() == 1);
	if ( founds.size() == 0 ) {
		cerr << "Error, not found function name in function Node" << endl;
		return;
	}
	
	currentSymbolTable->SetIdentifierDeclared(founds[0] -> tokenString);
	for ( int i=1 ;i < (int)founds.size(); i++ ) {
		currentSymbolTable->SetIdentifierDeclared(founds[i] -> tokenString);
	}
	// do more ??
}