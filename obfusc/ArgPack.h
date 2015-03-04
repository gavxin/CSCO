#pragma once
#include "pre.h"

#include "IdentifierGenerator.h"

using namespace std;
class ArgPack
{
public:
	ArgPack(int argc, char *const argv []);
	~ArgPack(void);
	bool isError;

	// input file.
	string input;
	// out file.
	string output;

	// before-after obfuscated table file
	bool isOutputBAfile;
	string baFile;

	// Not obfuscate table.
	bool isNotObfuscateFile;
	string noFile;

	bool isObfuscateConstant;
	bool isObfuscateString;
	bool isObfuscateIdentifier;
	// custom identifier charactor table.
	string custom;
	bool isRemoveTypeset;

	bool isObfuscateLoopStatement;
	bool isObfuscateControlFlow;

	// TYPE_NAME;
	bool isTYPE_NAMEFile;
	string typeNameFile;

	void useage(char *proc);
};

