#pragma once
#include "pre.h"
using namespace std;

class NumberExpGenerator;
class NumberExpGenerator
{
private:
	static NumberExpGenerator instance;
	
	string int2hexStr(int value);
	string int2octStr(int value);
	
public:
	NumberExpGenerator(void);
	~NumberExpGenerator(void);

	static NumberExpGenerator& get()
	{
		return instance;
	};

	string Generate(double num);
	
};

