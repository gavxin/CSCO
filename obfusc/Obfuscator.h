#pragma once
#include "pre.h"

#include "IObfusNode.h"
#include "CodeFile.h"
#include "NotObfusIdTable.h"
#include "RecordTable.h"
/**
 * Obfuscator will operate the AST tree(Tree).
 * It will obfuscate the name. the SymbolTable will be the reference.
 **/
class Obfuscator
{
private:
	Tree *currentTree;
	SymbolTable *currentSymbolTable;
	NotObfusIdTable *currentNotObfusIdTable;
	RecordTable recordTable;

	// left traversal
	void Traversal(Node *node);
	// ObfusNode list;
	vector<IObfusNode *> onList;
	// do something to node. call the IObfusNode::Action.
	void ObfuscateNode(Node *);
public:
	~Obfuscator(void);

	// create Obfuscator instance with CodeFile.
	Obfuscator(CodeFile &file, NotObfusIdTable *t);

	// main function.
	void Obfuscate();
	
	// add ObfuscNode
	void Register(IObfusNode *node);

	string PrintObfuscRecordTable(bool needLocation)
	{
		return recordTable.PrintRecordTable(needLocation);
	}
};

