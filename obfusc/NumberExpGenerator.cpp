#include "NumberExpGenerator.h"

NumberExpGenerator NumberExpGenerator::instance;
NumberExpGenerator::NumberExpGenerator(void)
{
}


NumberExpGenerator::~NumberExpGenerator(void)
{
}

string NumberExpGenerator::int2hexStr(int value)
{
	string result;
	stringstream strm;
	strm.setf(stringstream::showbase | stringstream::uppercase);
	strm << std::hex << value << endl;
	strm >> result;
	strm.clear();
	return result;
}

string NumberExpGenerator::int2octStr(int value)
{
	string result;
	stringstream strm;
	strm.setf(stringstream::showbase | stringstream::uppercase);
	strm << std::oct << value << endl;
	strm >> result;
	strm.clear();
	return result;
}


string NumberExpGenerator::Generate(double constant)
{

	stringstream strm;
	// generate a random int
	int randInt = rand() % 0x7FFF;
	string randStr = int2hexStr(randInt);

	// bug 0x1E-13.
	if ( randStr[randStr.size()-1] == 'E' ) {
		randStr[randStr.size()-1] = 'F';
		randInt++;
	}

	// r1*r2
	int r1 = rand() % 077;
	string r1Str = int2octStr(r1);
	int r2 = rand() % 99 + 100;
	



	// calculate adjust value;
	double adjust = constant - randInt - r1*r2;

	// after obfuscated
	stringstream strm2;
	if ( adjust < 0 ) {
		strm2 << "(" << randStr << "+" << r1Str << "*" << r2 << adjust << ")";
	} else {
		strm2 << "(" << randStr << "+" << r1Str << "*" << r2 << "+" << adjust << ")";
	}

	return strm2.str();
}