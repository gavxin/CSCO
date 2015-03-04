#include "SymbolTable.h"
#include "CParser.h"

SymbolTable::SymbolTable(void)
{
}


SymbolTable::~SymbolTable(void)
{
}
// find Symbol by name
Symbol *SymbolTable::findSymbol(string name)
{
	vector<Symbol *>::iterator it;
	for ( it = symbolList.begin() ; it != symbolList.end() ; it++ ) {
		if ( (*it)->name == name ) {
			return (*it);
		}
	}
	return NULL;
}
// find TYPE Symbol by name
Symbol *SymbolTable::findTYPE_NAMESymbol(string name)
{
	vector<Symbol *>::iterator it;
	for ( it = symbolList.begin() ; it != symbolList.end() ; it++ ) {
		if ( (*it)->type == Symbol::TYPE_NAME && (*it)->name == name ) {
			return (*it);
		}
	}
	return NULL;
}

bool SymbolTable::isExist(string name)
{
	if ( findSymbol(name) != NULL ) {
		return true;
	}
	else
		return false;
}

bool SymbolTable::isExistObfusc(string name)
{
	vector<Symbol *>::iterator it;
	for ( it = symbolList.begin() ; it != symbolList.end() ; it++ ) {
		Symbol *s = *it;
		if ( s->type == Symbol::IDENTIFIER ) {
			if ( s->isObfusced == false && s->name == name )  {
				return true;
			}
			if ( s->isObfusced == true && s->nameAfterObfusc == name) {
				return true;
			}
		} else {
			cout << s->name ;
		}
	}
	return false;
}

bool SymbolTable::isExistType(string name)
{
	if ( findTYPE_NAMESymbol(name) != NULL ) {
		return true;
	}
	else
		return false;
}

int SymbolTable::GetSize()
{
	return (int)symbolList.size();
}


// Lexer will call this.
// It will store the new Symbol and 
// log the location.
void SymbolTable::ScanedIdentifier(int t, TokenLocation l)
{
	/*cout << endl
		<< "-----------" << endl
		<< l.theText << endl
		<< "-----------" << endl;*/
	Symbol * s;

	switch (t) {
		case CParser::IDENTIFIER:
			if ( !isExist(l.theText) ) {
				s = new Symbol(l.theText);
				AddToTable(s);
			} else {
				s = findSymbol(l.theText);
				// ??
			}
			s->addLocation(l.first_line,l.first_column,l.last_line,l.last_column);
			break;
		case CParser::TYPE_NAME:
			assert( isExistType(l.theText) );
			s = findTYPE_NAMESymbol(l.theText);
			s->addLocation(l.first_line,l.first_column,l.last_line,l.last_column);
			break;
	}
}
// add to Symbol Table;
void SymbolTable::AddToTable(Symbol * symbol)
{
	symbolList.push_back(symbol);
}

// Convert to TYPE_NAME
void SymbolTable::ConvertIdentifier2TYPE_NAME(string name)
{
	Symbol *symbol = findSymbol(name);
	if ( symbol == NULL ) {
		cerr << "ConvertIdentifier2TYPE_NAME Symbol Not found" << endl;
		return;
	}

	symbol->type = Symbol::TYPE_NAME;
}
// set the identifier symbol 
void SymbolTable::SetIdentifierDeclared(string name)
{
	Symbol *symbol = findSymbol(name);
	if ( symbol == NULL ) {
		cerr << "SymbolTable::SetIdentifierDeclared Symbol Not found" << endl;
		return ;
	}

	symbol->isDeclared = true;
}

// print symbol table;
string SymbolTable::PrintSymbolTable()
{
	string result ="name\t\tisDecl\ttype\tObfu\n";

	vector<Symbol *>::iterator it;
	for( it = symbolList.begin() ; it != symbolList.end() ; it++ ) {
		Symbol *s = *it;
		result += s->name + ((s->name.length()<8)?"\t\t":"\t");
		result += ((s->isDeclared)?"true\t":"false\t");
		char *table[] = {"IDENTIFIER", "VAR", "FUNC", "TYPE_NAME"};
		result += table[(int)s->type];
		result += "\t";
		
		result += ((s->isObfusced)?s->nameAfterObfusc+"\t":"\t");
		
		result += "\n";
	}
	return result;
}


bool SymbolTable::InputTYPE_NAMEFile(string path)
{
	ifstream infile(path);
	if ( !infile ) {
		cerr << "SymbolTable::InputTYPE_NAMEFile Can't open file: \"" << path << "\"" << endl;
		return false;
	}
	string word;
	while ( infile >> word ) {
		AddTYPE_NAME(word);
	}
	return true;
}

void SymbolTable::AddTYPE_NAME(string word)
{
	Symbol *s = new Symbol(word, Symbol::TYPE_NAME);
	AddToTable(s);
}