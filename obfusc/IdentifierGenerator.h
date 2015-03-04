#pragma once
#include "pre.h"
using namespace std;

class IdentifierGenerator;

class IdentifierGenerator
{
private:
	static IdentifierGenerator instance;
	static const int ID_MIN_LEN = 8;
public:
	IdentifierGenerator(void);
	~IdentifierGenerator(void);

	static IdentifierGenerator& get()
	{
		return instance;
	};

	// the identifier name length.
	int idLength;
	// 
	enum IdLookLike { LL_NORMAL, LL_O0, LL_l1, LL_CUSTOM } idLookLike;
	// custom char table.
	string custom;

	string Generate();

	void SetSymbolNum(int num);
};

