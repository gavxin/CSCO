#pragma once
#include "pre.h"
#include "ExtraString.h"

using namespace std;

typedef struct {
	int first_line,last_line,first_column,last_column;
	char *text;
	// store the TOKEN type;
	int tokenId;
	// the Text String of the TOKEN
	string theText;
	// the String before the Text. usually spaces & tab & \n.
	string preString;
	// advanced preString.
	ExtraString *extraString;
} TokenLocation;

typedef struct {
	int first_line,last_line,first_column,last_column;
} SymbolLocation;