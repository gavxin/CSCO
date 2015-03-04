#include "ONConstant.h"
#include "Node.h"
#include "NumberExpGenerator.h"

ONConstant::ONConstant(void)
{
	srand((unsigned int)time(0));
}


ONConstant::~ONConstant(void)
{
}

bool ONConstant::JudgeType(Node *node)
{
	// first of all. must sure that it's a CONSTANT.
	if ( !( node->nodeType == Node::TOKEN 
		&& node->tokenId == CParser::CONSTANT ) ) {
		return false;
	}
	return true;
}

//do action to the node.
void ONConstant::Action(Node *node)
{
	if ( !JudgeType(node) ) {
		return;
	}

	// do not obfuscate constant char 'x'
	if ( node->tokenString[0] == '\'' && node->tokenString.length() != 3 ) {
		return ;
	}

	// get Ture value. If fail do not obfusc.
	double trueValue;
	if ( !getConstantValue(node->tokenString,&trueValue) ) {
		return ;
	}

	// do Obfuscate To Node.
	beforeObfuscate = node->tokenString;
	afterObfuscated = NumberExpGenerator::get().Generate(trueValue); 

	// set value to the node.
	node->obfuscatedTokenString = afterObfuscated;
	node->isObfuscated = true;
	
	// will save the changes.
	recordTable->AddRecord(beforeObfuscate,afterObfuscated,
		node->first_line,node->first_column,
		node->last_line,node->last_column);
}
/*
string ONConstant::Contant2String(double constant)
{

	stringstream strm;
	// generate a random int
	int randInt = rand() % 0xFFFF;
	string randStr;
	strm.setf(stringstream::showbase | stringstream::uppercase);
	strm << std::hex << randInt << endl;
	strm >> randStr;
	strm.clear();
	// bug 0x1E-13.
	if ( randStr[randStr.size()-1] == 'E' ) {
		randStr[randStr.size()-1] = 'F';
		randInt++;
	}

	// calculate adjust value;
	double adjust = constant - randInt;

	// after obfuscated
	stringstream strm2;
	if ( adjust < 0 ) {
		strm2 << "(" << randStr << adjust << ")";
	} else {
		strm2 << "(" << randStr << "+" << adjust << ")";
	}

	return strm2.str();
}*/

bool ONConstant::getConstantValue(string str,double *value)
{
	char *end; // strtod()
	double result;
	// char
	if ( str.length()==3 && str[0] == '\'' ) {
		result = str[1];
	// 0xFFF
	} else if ( str.length() >= 2 && str[0] == '0' 
			&& (str[1] == 'x'||str[1]=='X') ) {
		long l = strtol(str.c_str(),&end,0);
		if ( *end ) {
			cerr << "Can't find true value in ONConstant::getConstantValue str:" << str << endl;
			return false;
		}
		result = l;
	} else if ( str.length() >= 2 && str[0] == '0' ) {
		long l = strtol(str.c_str(),&end,8);
		if ( *end ) {
			cerr << "Can't find true value in ONConstant::getConstantValue str:" << str << endl;
			return false;
		}
		result = l;
	} else {
		char *end;
		result = strtod(str.c_str(),&end);
		if ( *end ) {
			cerr << "Can't find true value in ONConstant::getConstantValue str:" << str << endl;
			return false;
		}
	}
	*value = result;
	return true;
}