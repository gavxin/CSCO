#include "RecordTable.h"


RecordTable::RecordTable(void)
{
}


RecordTable::~RecordTable(void)
{
}

void RecordTable::AddRecord(string name, string afterName, 
	int first_line, int first_column,
	int last_line, int last_column)
{
	Record r(name,afterName,first_line,first_column,last_line,last_column);
	list.push_back(r);
}

string RecordTable::PrintRecordTable(bool hasLocation)
{
	string result;
	stringstream ss("");
	vector<Record>::iterator it;
	for ( it=list.begin() ; it!=list.end() ; it++) {
		ss << it->name + "\t";
		ss << it->afterName + "\t";
		if ( hasLocation ) {
			ss << "(" << it->first_line << "," << it->first_column << "-"
				<< it->last_line << "," << it->last_column << ")";
		}
		ss << endl;
	}
	result = ss.str();
	return result;
}