#pragma once
#include "iobfusnode.h"


// before Obfuscated
/* 
	WHILE '(' expression ')' 
		statement
*/
// after Obfuscated
/*
	l_continue:
		if (!(expr))
			goto l_break;
		instr;
		goto l_continue;
	l_break:
*/
class ONWhile :
	public IObfusNode
{
private:
	bool isRemoveTypeset;
public:
	ONWhile(bool);
	~ONWhile(void);

	// see the node type if it is the type which this class to obfuscate.
	bool JudgeType(Node *node);
	// main function. Obufuscator will call this function
	void Action(Node *node);
};

