#pragma once
#include "pre.h"

#include "TokenTypes.h"
using namespace std;
/**
 * the Symbol Class store the name which we need to obfuscate.
 * 
 * It's include variables, functions
 * It also has a Obfuscated name property.
 *
 * CONST , like number and string, will NOT be added to Symbol.
 **/
class Symbol
{
public:
	Symbol(void);
	~Symbol(void);


	// the name of the Symbol
	string name;
	// type of Symbol
	enum SymbolType { IDENTIFIER, VAR, FUNC, TYPE_NAME } type;
	//enum SymbolType { IDENTIFIER, CONST, STRING_LITERAL, TYPE_NAME } type;



	Symbol(string name);
	Symbol(string name, SymbolType type);

	// appeared location
	vector<SymbolLocation> appearedLocation;
	void addLocation(int first_line, int first_column, int last_line, int last_column);
	int AppearedTime();

/*****************************
 * IDENTIFIER
 ****************************/
	//enum IdentifierType { VAR, FUNC } idType;
/*****************************
 * VAR (IDENTIFIER)
 ****************************/
	// storage type of Symbol, such as "int []"
	string storeType;
	// If declared.
	bool isDeclared;
	
	// var scope
	enum SymbolScope { GLOBAL, LOCAL } scope;
	
	// If LOCAL
	string funcName;
/*****************************
 * FUNCTION (IDENTIFIER)
 ****************************/
	// full function define statement.
	string defineString;

/*****************************
 * TYPE_NAME
 ****************************/

/*****************************
 * Obfusc
 ****************************/
	bool isObfusced;
	string nameAfterObfusc;
};
