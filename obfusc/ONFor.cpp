#include "ONFor.h"


ONFor::ONFor(bool isRemoveTypeset) :
	isRemoveTypeset(isRemoveTypeset)
{
}


ONFor::~ONFor(void)
{
}

// see the node type if it is the type which this class to obfuscate.
bool ONFor::JudgeType(Node *node)
{
	if ( node->nodeType == Node::NODE 
		&& node->nodeTypeName == "iteration_statement"
		&& node->getChild(0)->nodeType == Node::TOKEN
		&& node->getChild(0)->tokenId == CParser::FOR )
	{
		return true;
	}
	return false;
}

// main function. Obufuscator will call this function
void ONFor::Action(Node *node)
{
	if ( !JudgeType(node) ) {
		return;
	}

	string l_loop = GenerateId();
	string l_continue = GenerateId();
	string l_instr = GenerateId();
	string l_break = GenerateId();

	string expr1,expr2,expr3,instr;
	expr1 = node->getChild(2)->ToSourceCode(isRemoveTypeset);
	Node *expression_statement = node->getChild(3);
	if ( expression_statement->childNodes.size() == 1 ) {
		expr2 = "1";
	} else {
		expr2 = expression_statement->getChild(0)->ToSourceCode(isRemoveTypeset);
	}
	
	if ( node->childNodes.size() == 6 ) {
		expr3 = "";
		instr = node->getChild(5)->ToSourceCode(isRemoveTypeset);
	} else {
		expr3 = node->getChild(4)->ToSourceCode(isRemoveTypeset);
		expr3 += ";";
		instr = node->getChild(6)->ToSourceCode(isRemoveTypeset);
	}
	
	stringstream ss;
	ss << expr1;
	ss << l_loop << ":";
	ss << "if(!(" << expr2 << "))";
	ss << "goto " << l_break << ";";
	ss << "goto " << l_instr << ";";
	ss << l_continue << ":";
	ss << expr3;
	ss << "goto " << l_loop << ";";
	ss << l_instr << ":";
	ss << instr;
	ss << "goto " << l_continue << ";";
	ss << l_break << ":;";
	
	string code = ss.str();

	node->isObfuscated = true;
	node->obfuscatedTokenString = code;
}