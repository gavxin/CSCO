#include "NotObfusIdTable.h"


NotObfusIdTable::NotObfusIdTable(void)
{
	idList = vector<string>();

	this->AddId("main");
}


NotObfusIdTable::~NotObfusIdTable(void)
{
}

void NotObfusIdTable::AddId(string name)
{
	idList.push_back(name);
}

bool NotObfusIdTable::hasId(string name)
{
	vector<string>::iterator it;
	for ( it = idList.begin() ; it != idList.end() ; it++ ) {
		if ( (*it) == name ) {
			return true;
		}
	}
	return false;
}

bool NotObfusIdTable::InputNotObfusIdFile(string path)
{
	ifstream infile(path);
	if ( !infile ) {
		cerr << "NotObfusIdTable::InputNotObfusIdFile Can't open file: \"" << path << "\"" << endl;
		return false;
	}
	string word;
	while ( infile >> word ) {
		AddId(word);
	}
	return true;
}