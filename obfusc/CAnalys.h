#pragma once
#include "pre.h"

#include "CLexer.h"
#include "CParser.h"
#include "Tree.h"
#include "Node.h"
#include "CodeFile.h"
#include "Symbol.h"
#include "SymbolTable.h"

#define TAB_COLUMN 4
// class define
class CAnalys : public CLexer, public CParser
{
	private:
		Tree** currentTree;
		SymbolTable *currentSymbolTable;
	protected:
		int Scan();
	public:
		void SetDebug(int d);
		void PrintError(char *s );
		int check_type(TokenValue &theValue);

		void FindTPYEDEFDeclaration(Node *);
		void ParsedDeclaration(Node * node);
		void ParsedFunctionDefinition(Node *functionNode, Node *declaratorNode);

		Tree * getCurrentTree(void) { return *currentTree; };
		void setCurrentTree(Tree *value) { *currentTree = value; };
		//void setCurrentTree(Tree *value) { currentTree = value; };
		SymbolTable * getCurrentSymbolTable(void) { return currentSymbolTable;};
		//void setCurrentSymbolTable(SymbolTable *value) { currentSymbolTable = value; };

		void setCurrentCodeFile(CodeFile &file);

		CAnalys();
		~CAnalys();
		
		
		void AddToSymbolTable(int t,TokenLocation l);

		// when Only do the Lex,
		// no Tree, Only Symbol Table will be created.
		// SymbolTable not have detail information of Symbols.
		void OnlyLexer();
};