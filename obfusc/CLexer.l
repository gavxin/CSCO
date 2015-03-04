%name CLexer

%header{
#include "pre.h"

#include "CLexer.h"
#include "CParser.h"

#include "ExtraString.h"

#define TAB_COLUMN 4
#define YY_USER_ACTION BeginAction();
%}

%define INHERIT
%define LEX_RETURN int
%define LEX ScanValue
%define LEX_PARAM TokenValue &theValue
%define MEMBERS \
	protected: \
		int theLine,theColumn; \
		string notValueText; \
		ExtraString *exstr; \
		virtual int check_type(TokenValue &theValue); \
		void comment(); \
		void comment2(); \
		void BeginAction(); \
		void notValue(); \
		void preprocess(); \
		void SetColumnLine4Input(char c); \
		void prestring2exstr();
%define CONSTRUCTOR_PARAM void
%define CONSTRUCTOR_INIT : theLine(1),theColumn(1)
%define CONSTRUCTOR_CODE {exstr=NULL;};

%define TEXT theText
%define LENG theTextLength



D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
P           [Pp][+-]?{D}+
FS			(f|F|l|L)
IS          ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))



%%

^[ \t]*"#"[^\n]*		{ preprocess(); }
"/*"			{ comment(); }
"//"[^\n]*      { /* consume //-comment */comment2(); }


"auto"			{ return(CParser::AUTO); }
"_Bool"			{ return(CParser::BOOL); }
"break"			{ return(CParser::BREAK); }
"case"			{ return(CParser::CASE); }
"char"			{ return(CParser::CHAR); }
"_Complex"		{ return(CParser::COMPLEX); }
"const"			{ return(CParser::CONST); }
"continue"		{ return(CParser::CONTINUE); }
"default"		{ return(CParser::DEFAULT); }
"do"			{ return(CParser::DO); }
"double"		{ return(CParser::DOUBLE); }
"else"			{ return(CParser::ELSE); }
"enum"			{ return(CParser::ENUM); }
"extern"		{ return(CParser::EXTERN); }
"float"			{ return(CParser::FLOAT); }
"for"			{ return(CParser::FOR); }
"goto"			{ return(CParser::GOTO); }
"if"			{ return(CParser::IF); }
"_Imaginary"	{ return(CParser::IMAGINARY); }
"inline"		{ return(CParser::INLINE); }
"int"			{ return(CParser::INT); }
"long"			{ return(CParser::LONG); }
"register"		{ return(CParser::REGISTER); }
"restrict"		{ return(CParser::RESTRICT); }
"return"		{ return(CParser::RETURN); }
"short"			{ return(CParser::SHORT); }
"signed"		{ return(CParser::SIGNED); }
"sizeof"		{ return(CParser::SIZEOF); }
"static"		{ return(CParser::STATIC); }
"struct"		{ return(CParser::STRUCT); }
"switch"		{ return(CParser::SWITCH); }
"typedef"		{ return(CParser::TYPEDEF); }
"union"			{ return(CParser::UNION); }
"unsigned"		{ return(CParser::UNSIGNED); }
"void"			{ return(CParser::VOID); }
"volatile"		{ return(CParser::VOLATILE); }
"while"			{ return(CParser::WHILE); }

{L}({L}|{D})*	{ return(check_type(theValue)); }

0[xX]{H}+{IS}?	{ return(CParser::CONSTANT); }
0{D}+{IS}?		{ return(CParser::CONSTANT); }
{D}+{IS}?		{ return(CParser::CONSTANT); }
L?'(\\.|[^\\'\n])+'	{ return(CParser::CONSTANT); }

{D}+{E}{FS}?		{ return(CParser::CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ return(CParser::CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ return(CParser::CONSTANT); }
0[xX]{H}+{P}{FS}?               { return(CParser::CONSTANT); }
0[xX]{H}*"."{H}+({P})?{FS}?     { return(CParser::CONSTANT); }
0[xX]{H}+"."{H}*({P})?{FS}?     { return(CParser::CONSTANT); }


L?\"(\\.|[^\\"\n])*\"	{ return(CParser::STRING_LITERAL); }

"..."			{ return(CParser::ELLIPSIS); }
">>="			{ return(CParser::RIGHT_ASSIGN); }
"<<="			{ return(CParser::LEFT_ASSIGN); }
"+="			{ return(CParser::ADD_ASSIGN); }
"-="			{ return(CParser::SUB_ASSIGN); }
"*="			{ return(CParser::MUL_ASSIGN); }
"/="			{ return(CParser::DIV_ASSIGN); }
"%="			{ return(CParser::MOD_ASSIGN); }
"&="			{ return(CParser::AND_ASSIGN); }
"^="			{ return(CParser::XOR_ASSIGN); }
"|="			{ return(CParser::OR_ASSIGN); }
">>"			{ return(CParser::RIGHT_OP); }
"<<"			{ return(CParser::LEFT_OP); }
"++"			{ return(CParser::INC_OP); }
"--"			{ return(CParser::DEC_OP); }
"->"			{ return(CParser::PTR_OP); }
"&&"			{ return(CParser::AND_OP); }
"||"			{ return(CParser::OR_OP); }
"<="			{ return(CParser::LE_OP); }
">="			{ return(CParser::GE_OP); }
"=="			{ return(CParser::EQ_OP); }
"!="			{ return(CParser::NE_OP); }
";"				{ return(';'); }
("{"|"<%")		{ return('{'); }
("}"|"%>")		{ return('}'); }
","			{ return(','); }
":"			{ return(':'); }
"="			{ return('='); }
"("			{ return('('); }
")"			{ return(')'); }
("["|"<:")		{ return('['); }
("]"|":>")		{ return(']'); }
"."			{ return('.'); }
"&"			{ return('&'); }
"!"			{ return('!'); }
"~"			{ return('~'); }
"-"			{ return('-'); }
"+"			{ return('+'); }
"*"			{ return('*'); }
"/"			{ return('/'); }
"%"			{ return('%'); }
"<"			{ return('<'); }
">"			{ return('>'); }
"^"			{ return('^'); }
"|"			{ return('|'); }
"?"			{ return('?'); }

[ \t\v\n\f]		{ notValue(); }
.			{ /* Add code to complain about unmatched characters */ }

%%

void CLexer::notValue()
{
	notValueText += (char *)theText;
}

void CLexer::comment(void)
{
	prestring2exstr();

	char c, prev = 0;
	notValueText += "/*";
	while ((c = yyinput()) != 0)      /* (EOF maps to 0) */
	{
		SetColumnLine4Input(c);
		//printf("%c",c);

		if (c == '/' && prev == '*') {
			notValueText += "/";
			break;
		}
		prev = c;
		notValueText += c;
	}
	/*error("unterminated comment");*/
	// add COMMENT to exstr
	exstr->addString(ExtraString::COMMENT, notValueText);
	notValueText = "";
}
void CLexer::comment2()
{
	char c;
	prestring2exstr();
	// read one more \n
	notValueText += (char *)theText;
	c = yyinput();
	if ( c != 0 ) {
		SetColumnLine4Input(c);
		notValueText += c;
	}

	// add COMMENT to exstr
	exstr->addString(ExtraString::COMMENT, notValueText);
	notValueText = "";
}

void CLexer::prestring2exstr()
{
	// add pre TYPESET to exstr
	if ( exstr == NULL ) {
		exstr = new ExtraString();
	}
	if ( !notValueText.empty() ) {
		exstr->addString(ExtraString::TYPESET, notValueText);
	}
	notValueText = "";
}
void CLexer::preprocess(void)
{
	prestring2exstr();

	char c;
	notValueText += (char *)theText;
	
	while ((c = yyinput()) != 0)      /* (EOF maps to 0) */
	{
		SetColumnLine4Input(c);
		//printf("%c",c);

		notValueText += c;
		if (c == '\n') {
			// because of notValueText at least will be "# \".length > 2
			if ( notValueText.length() > 2 &&
					notValueText[notValueText.length()-2] == '\\' ) {
				continue;
			} else {
				break;
			}
		}
	}

	// add PREPROCESS to exstr
	exstr->addString(ExtraString::PREPROCESS, notValueText);
	notValueText = "";
}


void CLexer::SetColumnLine4Input(char c)
{
	if (c == '\n') {
		theColumn = 1;
		theLine ++;
	}
	else if (c == '\t')
		theColumn += TAB_COLUMN - (theColumn % TAB_COLUMN);
	else
		theColumn++;

	
}

int CLexer::check_type(TokenValue &theValue)
{
	
	return CParser::IDENTIFIER;
}

// execute before every action in lex
void CLexer::BeginAction(void)
{
	// count the column & lineno
	int i;

	for (i = 0; theText[i] != '\0'; i++) {
		SetColumnLine4Input(theText[i]);
	}

	// echo theText
	//yy_echo();
};
