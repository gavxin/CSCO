#include "IdentifierGenerator.h"

IdentifierGenerator IdentifierGenerator::instance;

IdentifierGenerator::IdentifierGenerator(void)
{
	srand((unsigned int)time(0));
	idLength = ID_MIN_LEN;
}


IdentifierGenerator::~IdentifierGenerator(void)
{
}


// generate a Identifier string.
string IdentifierGenerator::Generate()
{
	//char firtable[]="_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//char digTable[] = "0123456789";
	char table[] = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	char O0Table[] = "O0";
	char l1Table[] = "l1";
	char *p;
	char firstChar = 'x';

	// Pick a character table.
	if ( idLookLike == LL_NORMAL ) {
		p = table;
	} else if ( idLookLike == LL_l1 ) {
		firstChar = 'l';
		p = l1Table;
	} else if ( idLookLike == LL_O0 ) {
		firstChar = 'O';
		p = O0Table;
	} else if ( idLookLike == LL_CUSTOM ) {
		char t[100];
		strncpy(t,custom.c_str(),100);
		p = t;
	}

	string result = "";
	int r;
	for (int i = 0 ;i < idLength; i++ ) {
		if ( i == 0 ) {
			//r = rand() % strlen(firtable);
			//result += firtable[r];
			result += firstChar;
		} else {
			r = rand() % strlen(p);
			result += *(p+r);
		}
	}

	return result;
}

void IdentifierGenerator::SetSymbolNum(int num)
{
	char table[] = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ12345678901234567890123456789012345678901234567890";
	char O0Table[] = "O0";
	char l1Table[] = "l1";
	
	int len;
	// Pick a character table.
	if ( idLookLike == LL_NORMAL ) {
		len = strlen(table);
	} else if ( idLookLike == LL_l1 ) {
		len = strlen(l1Table);
	} else if ( idLookLike == LL_O0 ) {
		len = strlen(O0Table);
	} else if ( idLookLike == LL_CUSTOM ) {
		len = custom.size();
	}

	assert(len > 1);

	double f = log((double)num * 20)/log((double)len);
	int intf = (int)f + 1;
	if ( intf < ID_MIN_LEN ) {
		idLength = ID_MIN_LEN;
	} else {
		idLength = intf;
	}
}