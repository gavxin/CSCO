#pragma once
#include "iobfusnode.h"

// before Obfuscated
/* 
	for (expr1; expr2; expr3)
		instr
*/
// after Obfuscated
/*
		expr1;
	l_loop:
		if (!(expr2))
			goto l_break;
		goto l_instr;
	l_continue:
		expr3;
		goto l_loop;
	l_instr:
		instr;
		goto l_continue;
	l_break:;
*/


class ONFor :
	public IObfusNode
{
private:
	bool isRemoveTypeset;
public:
	ONFor(bool);
	~ONFor(void);
		
	// see the node type if it is the type which this class to obfuscate.
	bool JudgeType(Node *node);
	// main function. Obufuscator will call this function
	void Action(Node *node);
};

