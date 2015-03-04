#pragma once
#include "pre.h"
#include "Tree.h"
#include "SymbolTable.h"

class CodeFile
{
public:
	//CodeFile(void);
	CodeFile(string name, string out, bool isRemoveTypeset);
	~CodeFile(void);
	bool isError;
	// file name
	string filename;
	// output file name
	string outputfilename;

	// FILE *p
	FILE *file;

	Tree *tree;
	SymbolTable *symbolTable;
	// is remove typeset.
	bool isRemoveTypeset;

	string Output();
};

