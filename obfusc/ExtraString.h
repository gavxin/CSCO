#pragma once
#include "pre.h"
using namespace std;

class ExtraString;
class PreProcessElement;
class CommentElement;
class TypesetElement;
class IExtraStringElement;

class ExtraString
{
public:
	ExtraString(void);
	~ExtraString(void);

	enum ElementType { TYPESET, COMMENT, PREPROCESS } elmentType;

	IExtraStringElement *CreateElement(ElementType type, string t);
	void addString(ElementType type, string t);

	vector<IExtraStringElement *> list;

	string toString();
	string toShortString();
};

class IExtraStringElement
{
public:
	IExtraStringElement(){};
	virtual ~IExtraStringElement(){};
	ExtraString::ElementType type;
	string content;
};

class TypesetElement : public IExtraStringElement
{
public:
	TypesetElement(string t)  {type = ExtraString::TYPESET; content= t;};
	~TypesetElement(){};
};

class CommentElement : public IExtraStringElement
{
public:
	CommentElement(string t)  {type = ExtraString::COMMENT; content= t;};
	~CommentElement(){};
};

class PreProcessElement : public IExtraStringElement
{
public:
	PreProcessElement(string t)  {type = ExtraString::PREPROCESS; content= t;};
	~PreProcessElement(){};
};



