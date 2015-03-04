#include "ONDoWhile.h"


ONDoWhile::ONDoWhile(bool isRemoveTypeset) :
	isRemoveTypeset(isRemoveTypeset)
{
}


ONDoWhile::~ONDoWhile(void)
{
}
// see the node type if it is the type which this class to obfuscate.
bool ONDoWhile::JudgeType(Node *node)
{
	if ( node->nodeType == Node::NODE 
		&& node->nodeTypeName == "iteration_statement"
		&& node->childNodes.size() == 7
		&& node->getChild(0)->nodeType == Node::TOKEN
		&& node->getChild(0)->tokenId == CParser::DO )
	{
		return true;
	}
	return false;
}

// main function. Obufuscator will call this function
void ONDoWhile::Action(Node *node)
{
	if ( !JudgeType(node) ) {
		return;
	}

	string l_continue = GenerateId();
	string l_break = GenerateId();

	Node *expression = node->getChild(4);
	Node *statement = node->getChild(1);

	stringstream ss;
	ss << l_continue << ":";
	ss << statement->ToSourceCode(isRemoveTypeset) ;
	ss << "if(" << expression->ToSourceCode(isRemoveTypeset) << ")";
	ss << "goto " << l_continue << ";";
	ss << l_break << ":;";

	string code = ss.str();

	node->isObfuscated = true;
	node->obfuscatedTokenString = code;
}