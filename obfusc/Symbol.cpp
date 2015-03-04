#include "Symbol.h"


Symbol::Symbol(void)
{
}


Symbol::~Symbol(void)
{
}

Symbol::Symbol(string name) :
	name(name),type(Symbol::IDENTIFIER),isDeclared(false),isObfusced(false)
{

}

Symbol::Symbol(string name, SymbolType type) :
	name(name),type(type),isDeclared(false),isObfusced(false)
{

}
// addLocation
void Symbol::addLocation(int first_line, int first_column, int last_line, int last_column)
{
	SymbolLocation l;
	l.first_line = first_line;
	l.first_column = first_column;
	l.last_column = last_column;
	l.last_line = last_line;
	appearedLocation.push_back(l);
}
// returrn Appeared time
int Symbol::AppearedTime()
{
	return (int)appearedLocation.size();
}