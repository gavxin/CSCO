#pragma once
#include "pre.h"
#include "TokenTypes.h"
using namespace std;
class Record;
class RecordMap;

class Record
{
public:
	string name;
	string afterName;

	int first_line,first_column,last_line,last_column;

	// constructor
	Record(string name, string afterName,
		int first_line, int first_column,
		int last_line, int last_column) : name(name), afterName(afterName),
			first_line(first_line),first_column(first_column),
			last_line(last_line), last_column(last_column)
	{
	}
};

class RecordTable
{
private:
	vector<Record> list;
public:
	RecordTable(void);
	~RecordTable(void);

	void AddRecord(string name, string afterName, 
		int first_line, int first_column,
		int last_line, int last_column);
	
	string PrintRecordTable(bool hasLocation);
};

