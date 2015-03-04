#pragma once
#include "iobfusnode.h"

// before Obfuscated
/* 
	do
		instr
	while (expr)
*/
// after Obfuscated
/*
	l_continue:
		instr;
		if (expr)
			goto l_continue;
	l_break:
*/
class ONDoWhile :
	public IObfusNode
{
private:
	bool isRemoveTypeset;
public:
	ONDoWhile(bool);
	~ONDoWhile(void);
	
	// see the node type if it is the type which this class to obfuscate.
	bool JudgeType(Node *node);
	// main function. Obufuscator will call this function
	void Action(Node *node);
};

