
#pragma once
#include "pre.h"
#include "TokenTypes.h"
#include "ExtraString.h"
using namespace std;
class Node;
class NodeTraversal;

class Node
{
private:
	string ToCodeTreeCall(int level);
	// the begin(), end() function use this list.
	list<Node*> traversaledList;
	bool isLetter(char c);
public:
	Node(void);
	~Node(void);

	Node *parent;

	// NodeType will be a TOKEN or NODE contains TOKENs
	enum NodeType { TOKEN, NODE } nodeType;

	// childNodes	
	list<Node *> childNodes;
	Node *getChild(int index);

	// if Is a TOKEN, tokenId, tokenString.
	// we just intrested in IDENTIFIER, CONST, STIRNG...
	int tokenId;
	string tokenString;

	// if Obfuscated.
	bool isObfuscated;
	string obfuscatedTokenString;

	// If is a NODE , then set the nodeTypeName;
	string nodeTypeName;

	// store the notValue strs before the node;
	string preString;
	ExtraString *extraString;

	// Location
	int first_line,first_column;
	int last_line, last_column;

	

	// create Node
	Node(TokenLocation l);
	Node(string typeName,int num,...);

	// add Child Node
	void AddChildNode(Node *);
	void AddChildNode(int num, ...);

	// conver the Node to Source code.
	string ToCode();
	string ToSourceCode(bool isRemoveTypeset);
	// 4debug
	string ToCodeTree();

	// find identifier children.
	void findIdentifierChildren(vector<Node *> &found);

	// find typedef;
	bool hasTypedefToken();
	// find extern;
	bool hasExternToken();
	// find gotoStatement;
	bool hasGotoStatement();
	
	// Judge the type.
	bool isToken(int tokenId);
	bool isNode(string nodeTypeName);
	
	// left traveral
	//void Traversal(void (*func)());
	//void Traversal2(int tokenId, bool (*func)(int));

	// functions about traversal all node.
	typedef list<Node*>::iterator iterator;
	void TraversalAllNode(list<Node *> &l);
	list<Node*>::iterator begin();
	list<Node*>::iterator end();
};