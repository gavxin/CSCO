#include "CodeFile.h"


//CodeFile::CodeFile(void)
//{
//	symbolTable = new SymbolTable();
//}


CodeFile::~CodeFile(void)
{
}

CodeFile::CodeFile(string name, string out, bool isRemoveTypeset) :
	isError(false),
	filename(name),
	outputfilename(out),
	isRemoveTypeset(isRemoveTypeset)
{
	// open file.
	errno_t err;
	if ( (err=fopen_s(&file, name.c_str(), "r") ) != 0 ) {
		cout << "can't open file:" << name << endl;
		isError = true;
	}

	symbolTable = new SymbolTable();
}

string CodeFile::Output()
{
	return tree->ToSourceCode(isRemoveTypeset) + "\n";
}