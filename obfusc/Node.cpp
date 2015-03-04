
#include "Node.h"
#include "CParser.h"

Node::Node(void)
{
}
Node::~Node(void)
{
}

// create node with location
Node::Node(TokenLocation l) : isObfuscated(false)
{
	nodeType = TOKEN;
	tokenId = l.tokenId;
	tokenString = l.theText;
	nodeTypeName = "";
	preString = l.preString;
	extraString = l.extraString;

	// set Location
	first_line = l.first_line;
	first_column = l.first_column;
	last_line = l.last_line;
	last_column = l.last_column;
}
// create node with typename;
Node::Node(string typeName,int num,...) : isObfuscated(false)
{
	// set the NodeType to NODE
	nodeType = Node::NODE;
	nodeTypeName = typeName;

	// add child nodes;
	Node *n;
	va_list arg_ptr;
	va_start(arg_ptr,num);
	for ( int i=0 ; i < num ; i++ ) {
		n = va_arg(arg_ptr, Node *);
		this->AddChildNode(n);
		n->parent = this;
		// 4debug
		//cout << n->nodeIndex << endl;
	}
	va_end(arg_ptr);

}

// add Child node. will push to childNodesList, and set the location.
void Node::AddChildNode(Node *n)
{
	// childNodes push
	childNodes.push_back(n);

	// setLocation
	if ( (int)childNodes.size() == 1 ) {
		first_line = n->first_line;
		first_column = n->first_column;
	}

	last_line = n->last_line;
	last_column = n->last_column;
}

void Node::AddChildNode(int num, ...)
{
	// add child nodes;
	Node *n;
	va_list arg_ptr;
	va_start(arg_ptr,num);
	for ( int i=0 ; i < num ; i++ ) {
		n = va_arg(arg_ptr, Node *);
		this->AddChildNode(n);
		// 4debug
		//cout << n->nodeIndex << endl;
	}
	va_end(arg_ptr);
}

string Node::ToSourceCode(bool isRemoveTypeset)
{
	string result = "";
	if ( this == NULL ) {
		cerr << "Node::ToCodeCall Node NULL" << endl;
		return result;
	}
	// TOKEN.
	if ( this->nodeType == TOKEN ) {
		if ( isRemoveTypeset ) {
			result += this->extraString->toShortString();
		} else {
			result += this->extraString->toString();
		}
		if ( this->isObfuscated == true ) {
			result +=  this->obfuscatedTokenString;
		} else {
			result += this->tokenString;
		}
	// A Node.
	} else {
		if ( this->isObfuscated ) {
			result += this->obfuscatedTokenString;
		} else {
			list<Node *>::iterator it;
			for ( it = this->childNodes.begin() ; it != this->childNodes.end() ; it++) {
				//result += (*it)->ToSourceCode(isRemoveTypeset);
				string str = (*it)->ToSourceCode(isRemoveTypeset);
				// determine if should add a space.
				if ( isRemoveTypeset && !result.empty() && !str.empty() ) {
					char c = result[result.length()-1];
					char d = str[0];
					if ( isLetter(c) && isLetter(d) ) {
						result += " ";
					}
				}
				result += str;
			}
		}
	}
	return result;
}
bool Node::isLetter(char c)
{
	if ( ( c >= 'a' && c<='z' )
			|| ( c >= 'A' && c<= 'Z' )
			|| ( c == '_' ) 
			|| ( c >= '0' && c<= '9' )) 
	{
		return true;
	}
	return false;
}

// To Code
string Node::ToCode()
{
	string result = "";
	if ( this == NULL ) {
		cerr << "Node::ToCodeCall Node NULL" << endl;
		return result;
	}
	if ( this->nodeType == TOKEN ) {
		// 
		result += this->extraString->toString();

		if ( this->isObfuscated == true ) {
			result +=  this->obfuscatedTokenString;
		} else {
			result += this->tokenString;
		}
	} else {
		list<Node *>::iterator it;
		for ( it = this->childNodes.begin() ; it != this->childNodes.end() ; it++) {
			result += (*it)->ToCode();
		}
	}
	return result;
}


// print the Tree;
string Node::ToCodeTree()
{
	return this->ToCodeTreeCall(0);
}
// print the Tree;
string Node::ToCodeTreeCall(int level)
{
	string result = "";

	if ( this == NULL ) {
		cerr << "Node::ToCodeTreeCall Node NULL" << endl;
		return result;
	}

	for ( int i = 0 ; i < level ; i++ ) {
		result += "  ";
	}

	if ( this->nodeType == TOKEN ) {
		char tokenIdChar[5];
		sprintf(tokenIdChar,"%d",this->tokenId);
		result += "TOKEN:(" + this->tokenString + ")  typeID:"+ tokenIdChar +"\n";
	} else {
		result += this->nodeTypeName + "\n";
		list<Node *>::iterator it;
		for ( it = this->childNodes.begin() ; it != this->childNodes.end() ; it++) {
			result += (*it)->ToCodeTreeCall(level + 1);
		}
	}
	return result;
}


// find all identifier children. called by parser.
void Node::findIdentifierChildren(vector<Node *> &found)
{
	if ( this == NULL ) {
		cerr << "Node::findIdentifierChildrenCall Node NULL" << endl;
		return ;
	}
	
	if ( this->nodeType == TOKEN ) {
		if ( this->tokenId == CParser::IDENTIFIER ) {
			found.push_back(this);
		}
	} else {
		list<Node *>::iterator it;
		for ( it = this->childNodes.begin() ; it != this->childNodes.end() ; it++) {
			(*it)->findIdentifierChildren(found);
		}
	}
	return ;
}

Node * Node::getChild(int index)
{
	list<Node *>::iterator it = this->childNodes.begin();
	for ( int i = 0 ; i < index; i ++ ) {
		it ++;
	}
	return (*it);
}

bool Node::hasTypedefToken()
{
	Node::iterator it;
	for ( it = this->begin() ; it != this->end() ; it++)
	{
		if ( (*it)->isToken(CParser::TYPEDEF) ) {
			return true;
		}
	}
	return false;
}
// has Extern token
bool Node::hasExternToken()
{
	Node::iterator it;
	for ( it = this->begin() ; it != this->end() ; it++)
	{
		if ( (*it)->isToken(CParser::EXTERN) ) {
			return true;
		}
	}

	return false;
}

// has
bool Node::hasGotoStatement()
{
	Node::iterator it;
	for ( it = this->begin(); it != this->end(); it++ ) {
		if ( (*it)->isToken(CParser::GOTO) ) {
			return true;
		}
	}
	return false;
}

bool Node::isToken(int tokenId)
{
	if ( this->nodeType == Node::TOKEN	&& this->tokenId == tokenId ) {
		return true;
	}
	return false;
}

bool Node::isNode(string nodeTypeName)
{
	if ( this->nodeType == Node::NODE && this->nodeTypeName == nodeTypeName ) {
		return true;
	}
	return false;
}

//void Node::Traversal(void (*func)())
//{
//	if ( this == NULL ) {
//		cerr << "Node::Traversal Node NULL" << endl;
//		return ;
//	}
//	
//	if ( this->nodeType == TOKEN ) {
//		func();
//	} else {
//		list<Node *>::iterator it;
//		for ( it = this->childNodes.begin() ; it != this->childNodes.end() ; it++) {
//			(*it)->Traversal(func);
//		}
//		func();
//	}
//	return ;
//}

void Node::TraversalAllNode(list<Node *> &l)
{
	if ( this == NULL ) {
		cerr << "Node::Traversal Node NULL" << endl;
		return ;
	}
	
	if ( this->nodeType == TOKEN ) {
		l.push_back(this);
	} else {
		list<Node *>::iterator it;
		for ( it = this->childNodes.begin() ; it != this->childNodes.end() ; it++) {
			(*it)->TraversalAllNode(l);
		}
		l.push_back(this);
	}
	return ;
}

list<Node*>::iterator Node::begin()
{
	traversaledList = list<Node*>();
	TraversalAllNode(traversaledList);
	return traversaledList.begin();
}

list<Node*>::iterator Node::end()
{
	return traversaledList.end();
}