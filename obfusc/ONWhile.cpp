#include "ONWhile.h"


ONWhile::ONWhile(bool isRemoveTypeset) :
	isRemoveTypeset(isRemoveTypeset)
{
}


ONWhile::~ONWhile(void)
{
}


// see the node type if it is the type which this class to obfuscate.
bool ONWhile::JudgeType(Node *node)
{
	if ( node->nodeType == Node::NODE 
		&& node->nodeTypeName == "iteration_statement"
		&& node->childNodes.size() == 5
		&& node->getChild(0)->nodeType == Node::TOKEN
		&& node->getChild(0)->tokenId == CParser::WHILE )
	{
		return true;
	}
	return false;
}
// main function. Obufuscator will call this function
void ONWhile::Action(Node *node)
{
	if ( !JudgeType(node) ) {
		return;
	}
// before Obfuscated
/* 
	WHILE '(' expression ')' 
		statement
*/
// after Obfuscated
/*
	l_continue:
		if (!(expression))
			goto l_break;
		statement;
		goto l_continue;
	l_break:;
*/
	string l_continue = GenerateId();
	string l_break = GenerateId();

	Node *expression = node->getChild(2);
	Node *statement = node->getChild(4);

	stringstream ss;
	ss << l_continue << ":";
	ss << "if(!(" << expression->ToSourceCode(isRemoveTypeset) << "))";
	ss << "goto " << l_break << ";";
	ss << statement->ToSourceCode(isRemoveTypeset) ;
	ss << "goto " << l_continue << ";";
	ss << l_break << ":;";

	string code = ss.str();

	node->isObfuscated = true;
	node->obfuscatedTokenString = code;
}