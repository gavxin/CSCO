#include "ONBlockItemList.h"
#include "IdentifierGenerator.h"
#include "ONConstant.h"
#include "NumberExpGenerator.h"

ONBlockItemList::ONBlockItemList(bool isRemoveTypeset, bool isObfuscateConstant):
	isRemoveTypeset(isRemoveTypeset),
	isObfuscateConstant(isObfuscateConstant)
{
	srand((unsigned int)time(0));
}


ONBlockItemList::~ONBlockItemList(void)
{
}


bool ONBlockItemList::JudgeType(Node *node)
{
	if ( node->nodeType == Node::NODE
		&& node->nodeTypeName == "block_item_list" 
		&& !node->hasGotoStatement() ) {
			return true;
	}
	return false;
}
void ONBlockItemList::Action(Node *node)
{
	if ( !JudgeType(node) ) {
		return;
	}
	// calculate num of statements.
	vector<Node *> statements;
	vector<Node *> declarations;
	int numStatements = 0;
	int numBlocks = 0;
	bool flag = false;
	list<Node*>::iterator it;
	for ( it = node->childNodes.begin() ; it != node->childNodes.end() ; it++ )	{
		if ( flag == true ) {
			if ( !isStatement((*it)) ) {
				return;
			}
			numStatements++;
			statements.push_back(*it);
		} else {
			if ( isStatement((*it)) ) {
				flag = true;
				numStatements++;
				statements.push_back(*it);
			} else {
				declarations.push_back(*it);
			}
		}
	}
	// if statements > 5 will Obfuscate.
	if ( numStatements < 6 ) {
		return;
	}

	// get the statements. (some is declaration)
	// pop the childNodes.
	
	//for ( int i = 0; i < numStatements; i ++ ) {
	//	Node *tmp = node->childNodes.back();
	//	cout << tmp->ToSourceCode(false) << endl;
	//	if ( tmp && isStatement(tmp) ) {
	//		node->childNodes.pop_back();
	//		statements.push_back(tmp);
	//	} else {
	//		break;
	//	}
	//}
	assert((int)statements.size()==numStatements);

	// generate blocks count
	int minBlocks = 5;
	int maxBlocks = (numStatements>100)?100:numStatements;
	numBlocks = rand()%(maxBlocks - minBlocks) + minBlocks;

	// generate a random sequence.
	GenerateRandomSequence(this->sequence,numBlocks);

	vector<string> statementBlocks;
	GenerateRandomStatementBlocks(statementBlocks,numBlocks,numStatements,statements);
	/*
	tmp=sw;sw=1;
	START:
		switch (sw) {
			case 1:
				A;
				sw = 3;
				goto START;
			case 2:
				C;
				goto END;
			case 3:
				B;
				sw = 2;
				goto START;
		}
	END:sw=tmp;
	*/
	// front
	stringstream ss;
	// generate start lable and end lable
	startLable = GenerateId();
	endLable = GenerateId();
	// codeFront & codeEnd;
	ss << tmpGlobleVar << "=" << globleVar << ";";
	ss << globleVar << "=" << findIndexOfSequence(0) << ";";
	ss << startLable << ":switch(" << globleVar << "){";
	string codeFront = ss.str();
	string codeEnd = "}" + endLable + ":" + globleVar + "=" + tmpGlobleVar +  ";" ;
	//case 1:
	//	A;
	//	sw = 3;
	//	goto START;
	vector<string> bodys;
	string body;
	for ( int i = 0; i < numBlocks; i++ ) {
		ss.str("");
		if ( isObfuscateConstant ) {
			ss << "case" << NumberExpGenerator::get().Generate((double)i) << ":";
		} else {
			ss << "case " << i << ":";
		}
		//ss << statements[numBlocks-1-sequence[i]]->ToSourceCode(isRemoveTypeset);
		ss << statementBlocks[sequence[i]] ;

		if ( sequence[i]+1 != numBlocks ) {
			if ( isObfuscateConstant ) {
				ss << globleVar << "=" << NumberExpGenerator::get().Generate((double)findIndexOfSequence(sequence[i]+1)) << ";";
			} else {
				ss << globleVar << "=" << findIndexOfSequence(sequence[i]+1) << ";";
			}
			ss << "goto " << startLable << ";";
		} else {
			ss << "goto " << endLable << ";";
		}
		//body += ss.str();
		bodys.push_back(ss.str());
	}
	// random 
	vector<int> seq;
	GenerateRandomSequence(seq,numBlocks);
	for ( int i = 0; i < numBlocks; i++ ) {
		body += bodys[seq[i]];
	}

	string code = codeFront + body + codeEnd;
	// add All to the Node
	//node->childNodes.push_back(CreateNodeTOKEN(code));

	string declaration;
	vector<Node*>::iterator it2;
	for ( it2 = declarations.begin(); it2 != declarations.end(); it2++ ) {
		declaration += (*it2)->ToSourceCode(isRemoveTypeset);
	}
	node->isObfuscated = true;
	node->obfuscatedTokenString = declaration + code;
}

void ONBlockItemList::InitAction()
{
	// Add globle var
	AddGlobleVar();
}

bool ONBlockItemList::isStatement(Node *node)
{
	if ( node->nodeType == Node::NODE
		&& node->nodeTypeName == "statement")
		return true;
	return false;
}

void ONBlockItemList::AddGlobleVar()
{
	globleVar = GenerateId();
	tmpGlobleVar = GenerateId();
	string str = "int " + globleVar + "," + tmpGlobleVar + ";\n";

	Node *create = new Node("UseInObfuscate",1,CreateNodeTOKEN(str));

	root->childNodes.push_front(create);
}

void ONBlockItemList::GenerateRandomSequence(vector<int> &seq, int size)
{
	seq.clear();
	int i;
	for ( i = 0; i < size; i++ ) {
		seq.push_back(i);
	}

	for ( i = 0; i < size ; i++ )
	{
		int j = rand()%size;
		// swap i, j
		int tmp = seq[i];
		seq[i] = seq[j];
		seq[j] = tmp;
	}
}

void ONBlockItemList::GenerateRandomStatementBlocks(vector<string> &statementBlock, int blocksize, int numStatement, vector<Node *> statements)
{
	int i;
	statementBlock.clear();
	vector<bool> tmp;
	for ( i= 0; i < numStatement-1;i++) {
		tmp.push_back(false);
	}

	for ( i = 0; i < blocksize-1; i++ ) {
		while (1) {
			int i = rand()%(numStatement-1);
			if ( tmp[i] == false ) {
				tmp[i] = true;
				break;
			}
		}
	}
	int lasti = 0;
	statementBlock.push_back("");
	for (i = 0; i < numStatement-1; i++) {
		statementBlock[statementBlock.size()-1] += statements[i]->ToSourceCode(isRemoveTypeset);
		if ( tmp[i] == true ) {
			statementBlock.push_back("");
		}
	}
	statementBlock[statementBlock.size()-1]
+= statements[numStatement-1]->ToSourceCode(isRemoveTypeset);

	assert(statementBlock.size() == blocksize);
}


int ONBlockItemList::findIndexOfSequence(int value)
{
	int size = (int)sequence.size();
	for (int i=0 ; i < size; i++ ) {
		if ( value == sequence[i] ) {
			return i;
		}
	}
	return -1;
}


