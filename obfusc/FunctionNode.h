#pragma once
#include "pre.h"

#include "node.h"
class FunctionNode :
	public Node
{
public:
	//FunctionNode(void);
	~FunctionNode(void);

	// function name;
	string functionName;
	// full string with function type, args.
	string functionDefineString;


};