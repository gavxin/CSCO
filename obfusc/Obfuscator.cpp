#include "Obfuscator.h"
#include "Node.h"

Obfuscator::~Obfuscator(void)
{
	
}

Obfuscator::Obfuscator(CodeFile &file,NotObfusIdTable *t)
{
	currentTree = file.tree;
	currentSymbolTable = file.symbolTable;
	currentNotObfusIdTable = t;
}
// main function.
void Obfuscator::Obfuscate()
{
	Traversal(currentTree);
}
// left traversal
void Obfuscator::Traversal(Node *node)
{
	if ( node == NULL ) {
		cerr << "Node::Traversal Node NULL" << endl;
		return ;
	}
	
	if ( node->nodeType == Node::TOKEN ) {
		ObfuscateNode(node);
	} else {
		list<Node *>::iterator it;
		for ( it = node->childNodes.begin() ; it != node->childNodes.end() ; it++) {
			Traversal((*it));
		}
		ObfuscateNode(node);
	}
	return ;
}
// do action to Node
void Obfuscator::ObfuscateNode(Node *node)
{
	//cout << node->nodeTypeName << endl;
	//node->preString = "123";
	vector<IObfusNode *>::iterator it;
	for( it = onList.begin() ; it != onList.end() ; it++) {
		(*it)->Action(node);
	}
}
// register ObfuscNode classes
void Obfuscator::Register(IObfusNode *on)
{
	on->symbolTable = currentSymbolTable;
	on->notObfusIdTable = currentNotObfusIdTable;
	on->recordTable = &recordTable;
	on->root = currentTree;
	onList.push_back(on);
	on->InitAction();
}
