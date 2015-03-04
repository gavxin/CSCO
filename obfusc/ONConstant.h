#pragma once
#include "pre.h"

#include "iobfusnode.h"


// this class will obfuscate the CONSTANT node.

class ONConstant :
	public IObfusNode
{
public:
	ONConstant(void);
	~ONConstant(void);
	bool JudgeType(Node *node);
	void Action(Node *node);
	bool getConstantValue(string str,double *value);
	//static string Contant2String(double constant);
};

