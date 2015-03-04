#include "ONString.h"

ONString::ONString(void)
{
}


ONString::~ONString(void)
{
}

bool ONString::JudgeType(Node *node)
{
	// first of all. must sure that it's a CONSTANT.
	if ( !( node->nodeType == Node::TOKEN 
		&& node->tokenId == CParser::STRING_LITERAL ) ) {
		return false;
	}
	return true;
}
// convert string like this
// "\x64\x69\x66\x66\x73\x74\x61\x74\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x25\x73"
string ONString::Convert2HexStyle(string str)
{
	stringstream strm;
	string after;
	char cur;
	for ( int i = 0 ; i < (int)str.length() ; i ++ ) {
		if ( i == 0 ) {
			after += '\"';
		} else if ( i == str.length() -1 ) {
			after += '\"';
		} else {
			cur = str[i];
			// if found a type cast \;
			if ( cur == '\\' ) {
				after += cur;
				after += str[i+1];
				i++;
			// else will convert to \xFF;
			} else {
				// get hex
				int value = (int)cur;
				string strValue;
				strm.setf(ios::uppercase);
				strm<< std::hex << value;
				strm >> strValue;
				strm.clear();

				after += "\\x";
				after += strValue;
			}
		}
	}

	return after;
}

void ONString::Action(Node *node)
{
	if ( !JudgeType(node) ) {
		return;
	}
	
	if ( node->tokenString.length() < 2 ) {
		cerr << "error token string_literal length smaller than 2" << endl;
		return ;
	}

	// convert to hex style
	beforeObfuscate = node->tokenString;
	afterObfuscated = Convert2HexStyle(node->tokenString);

	// set obfuscated
	node->isObfuscated = true;
	node->obfuscatedTokenString = afterObfuscated;
	
	//save the changes.
	recordTable->AddRecord(beforeObfuscate, afterObfuscated,
		node->first_line, node->first_column,
		node->last_line, node->last_column);
}
