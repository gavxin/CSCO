#pragma once
#include "pre.h"

#include "Node.h"
#include "SymbolTable.h"
#include "NotObfusIdTable.h"
#include "RecordTable.h"
#include "IdentifierGenerator.h"

class IObfusNode
{
public:
	SymbolTable *symbolTable;
	NotObfusIdTable *notObfusIdTable;
	RecordTable *recordTable;
	Node *root;

	IObfusNode(void)
	{
	}

	string beforeObfuscate;
	string afterObfuscated;

	virtual ~IObfusNode(void)
	{
	}
	// see the node type if it is the type which this class to obfuscate.
	virtual bool JudgeType(Node *node)
	{
		return false;
	}
	// main function. Obufuscator will call this function
	virtual void Action(Node *node)
	{
	}

	// Init.
	virtual void InitAction(){};
	
	Node * CreateNodeTOKEN(string str)
	{
		TokenLocation tmp;
		tmp.tokenId = -1;
		tmp.theText = str;
		tmp.preString = "";
		tmp.extraString = new ExtraString();
		tmp.first_line = -1;
		tmp.first_column = -1;
		tmp.last_line = -1;
		tmp.last_column = -1;

		Node *re = new Node(tmp);

		return re;
	}

	string GenerateId() {
		string generated = IdentifierGenerator::get().Generate();
		while( symbolTable->isExistObfusc(generated) ) {
			generated = IdentifierGenerator::get().Generate();
		}
		symbolTable->AddToTable(new Symbol(generated));
		return generated;
	}
};

