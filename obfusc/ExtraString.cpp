#include "ExtraString.h"


ExtraString::ExtraString(void)
{
	list = vector<IExtraStringElement*>();
}


ExtraString::~ExtraString(void)
{

}
// Create String.
void ExtraString::addString(ElementType type, string t)
{
	IExtraStringElement *iese;
	iese = CreateElement(type,t);
	list.push_back(iese);
}
// Create Element
IExtraStringElement *ExtraString::CreateElement(ElementType type, string t)
{
	IExtraStringElement *p;
	switch(type) {
		case TYPESET:
			p = new TypesetElement(t);
			break;
		case COMMENT:
			p = new CommentElement(t);
			break;
		case PREPROCESS:
			p = new PreProcessElement(t);
			break;
	}
	return p;
}

string ExtraString::toString()
{
	string result;
	vector<IExtraStringElement *>::iterator it;
	for ( it = list.begin() ; it != list.end() ; it++ ) {
		result += (*it)->content;
	}
	return result;
}

string ExtraString::toShortString()
{
	string result;
	vector<IExtraStringElement *>::iterator it;
	for ( it = list.begin() ; it != list.end() ; it++ ) {
		if ( (*it)->type == PREPROCESS ) {
			if ( result.empty()) {
				result += "\n";
			}
			result += (*it)->content;
		}
	}
	/*if ( result.empty() ) {
		result = " ";
	}*/
	return result;
}
