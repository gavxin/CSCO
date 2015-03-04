#pragma once
#include "iobfusnode.h"
class ONBlockItemList :
	public IObfusNode
{
private:
	string globleVar;
	string tmpGlobleVar;
	string startLable;
	string endLable;
	vector<int> sequence;
	bool isRemoveTypeset;
	bool isObfuscateConstant;
	int findIndexOfSequence(int value);
public:
	ONBlockItemList(bool isRemoveTypeset,bool);
	~ONBlockItemList(void);

	bool JudgeType(Node *node);
	void Action(Node *node);

	// if is a statement
	bool isStatement(Node *node);

	void AddGlobleVar();

	void InitAction();
	void GenerateRandomSequence(vector<int> &sequence, int size);
	void GenerateRandomStatementBlocks(vector<string> &sn, int blocksize, int numStatement, vector<Node *> statements);

};

