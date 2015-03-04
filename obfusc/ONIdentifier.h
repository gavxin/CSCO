#pragma once
#include "pre.h"
#include "IObfusNode.h"
#include "NotObfusIdTable.h"

class ONIdentifier :
	public IObfusNode
{
public:
	ONIdentifier(void);
	~ONIdentifier(void);

	static const int ID_LEN=8;
	// see the node type if it is the type which this class to obfuscate.
	bool JudgeType(Node *node);
	// main function. Obufuscator will call this function
	void Action(Node *node);
	
	string GenerateIdentifier();
};

