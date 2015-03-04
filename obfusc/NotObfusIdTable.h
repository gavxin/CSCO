#pragma once
#include "pre.h"
using namespace std;

class NotObfusIdTable
{
public:
	NotObfusIdTable(void);
	~NotObfusIdTable(void);

	vector<string> idList;

	void AddId(string name);
	bool hasId(string name);
	bool InputNotObfusIdFile(string path);
};

