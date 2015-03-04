#pragma once
#include "pre.h"

#include "iobfusnode.h"
class ONString :
	public IObfusNode
{
private:
	// convert string like this
	// "\x64\x69\x66\x66\x73\x74\x61\x74\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x25\x73"
	string Convert2HexStyle(string str);
public:
	ONString(void);
	~ONString(void);
	bool JudgeType(Node *node);
	void Action(Node *node);
};

