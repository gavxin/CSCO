#pragma once
#include "pre.h"

#include "Symbol.h"
#include "TokenTypes.h"
#include "CParser.h"

class SymbolTable
{
private:
	vector<Symbol *> symbolList;
public:
	SymbolTable(void);
	~SymbolTable(void);
	// print the symbol table 4debug.
	string PrintSymbolTable();

	// add Symbol;
	void AddToTable(Symbol *);
	void ScanedIdentifier(int t, TokenLocation l);

	// find Symbol;
	Symbol *findSymbol(string name);
	bool isExist(string name);
	bool isExistObfusc(string name);

	// find TYPE_NAME Symbol
	Symbol *SymbolTable::findTYPE_NAMESymbol(string name);
	bool isExistType(string name);
	
	// return num of symbols
	int GetSize();

	bool InputTYPE_NAMEFile(string path);
	void AddTYPE_NAME(string word);



/********************************
 * called by Parser
 *******************************/
	// Convert Symbol. 
	void ConvertIdentifier2TYPE_NAME(string name);

	void SetIdentifierDeclared(string name);

};

