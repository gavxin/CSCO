#ifndef YY_CParser_h_included
#define YY_CParser_h_included

#line 1 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
/* before anything */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#endif
#include <stdio.h>

/* #line 14 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 21 "CParser.h"
#line 4 "CParser.y"

#include "pre.h"

#include "Node.h"
#include "FunctionNode.h"
#include "Tree.h"
#include "SymbolTable.h"
#include "Symbol.h"

class Node;
class SymbolTable;
class Symbol;
class Tree;

using namespace std;

#line 21 "CParser.y"
typedef union {
	Node * node;
} yy_CParser_stype;
#define YY_CParser_STYPE yy_CParser_stype
#line 25 "CParser.y"

typedef YY_CParser_STYPE TokenValue;
#include "TokenTypes.h"
// 4quick

#define CN new Node

#define YY_CParser_LSP_NEEDED 
#define YY_CParser_LTYPE  TokenLocation
#define YY_CParser_LLOC  theTokenLocation
#define YY_CParser_LVAL  theTokenValue
#define YY_CParser_DEBUG  1
#define YY_CParser_LEX_BODY  =0
#define YY_CParser_ERROR_BODY  =0
#define YY_CParser_ERROR  PrintError
#define YY_CParser_DEBUG_FLAG  debugFlag
#define YY_CParser_LEX  Scan
#define YY_CParser_PARSE  Parse 
#define YY_CParser_PARSE_PARAM  
#define YY_CParser_MEMBERS  \
	public: 	\
		virtual Tree * getCurrentTree(void) {return NULL;}; \
		virtual void setCurrentTree(Tree *value){}; \
		virtual SymbolTable * getCurrentSymbolTable(void){return NULL;}; \
		virtual void ParsedDeclaration(Node *){}; \
		virtual void FindTPYEDEFDeclaration(Node *){}; \
		virtual void ParsedFunctionDefinition(Node *functionNode, Node *declaratorNode){};
#define YY_CParser_CONSTRUCTOR_PARAM  
#define YY_CParser_CONSTRUCTOR_INIT  
#define YY_CParser_CONSTRUCTOR_CODE  \
	;
#define YY_CParser_ENUM_TOKEN  EnumToken

#line 14 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_CParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_CParser_COMPATIBILITY 1
#else
#define  YY_CParser_COMPATIBILITY 0
#endif
#endif

#if YY_CParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_CParser_LTYPE
#define YY_CParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_CParser_STYPE 
#define YY_CParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_CParser_DEBUG
#define  YY_CParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_CParser_STYPE
#ifndef yystype
#define yystype YY_CParser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_CParser_USE_GOTO
#define YY_CParser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_CParser_USE_GOTO
#define YY_CParser_USE_GOTO 0
#endif

#ifndef YY_CParser_PURE

/* #line 63 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 130 "CParser.h"

#line 63 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
/* YY_CParser_PURE */
#endif

/* #line 65 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 137 "CParser.h"

#line 65 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
/* prefix */
#ifndef YY_CParser_DEBUG

/* #line 67 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 144 "CParser.h"

#line 67 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
/* YY_CParser_DEBUG */
#endif
#ifndef YY_CParser_LSP_NEEDED

/* #line 70 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 152 "CParser.h"

#line 70 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
 /* YY_CParser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_CParser_LSP_NEEDED
#ifndef YY_CParser_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_CParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_CParser_STYPE
#define YY_CParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_CParser_PARSE
#define YY_CParser_PARSE yyparse
#endif
#ifndef YY_CParser_LEX
#define YY_CParser_LEX yylex
#endif
#ifndef YY_CParser_LVAL
#define YY_CParser_LVAL yylval
#endif
#ifndef YY_CParser_LLOC
#define YY_CParser_LLOC yylloc
#endif
#ifndef YY_CParser_CHAR
#define YY_CParser_CHAR yychar
#endif
#ifndef YY_CParser_NERRS
#define YY_CParser_NERRS yynerrs
#endif
#ifndef YY_CParser_DEBUG_FLAG
#define YY_CParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_CParser_ERROR
#define YY_CParser_ERROR yyerror
#endif

#ifndef YY_CParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_CParser_PARSE_PARAM
#ifndef YY_CParser_PARSE_PARAM_DEF
#define YY_CParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_CParser_PARSE_PARAM
#define YY_CParser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_CParser_PURE
extern YY_CParser_STYPE YY_CParser_LVAL;
#endif


/* #line 143 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 230 "CParser.h"
#define	IDENTIFIER	258
#define	CONSTANT	259
#define	STRING_LITERAL	260
#define	SIZEOF	261
#define	PTR_OP	262
#define	INC_OP	263
#define	DEC_OP	264
#define	LEFT_OP	265
#define	RIGHT_OP	266
#define	LE_OP	267
#define	GE_OP	268
#define	EQ_OP	269
#define	NE_OP	270
#define	AND_OP	271
#define	OR_OP	272
#define	MUL_ASSIGN	273
#define	DIV_ASSIGN	274
#define	MOD_ASSIGN	275
#define	ADD_ASSIGN	276
#define	SUB_ASSIGN	277
#define	LEFT_ASSIGN	278
#define	RIGHT_ASSIGN	279
#define	AND_ASSIGN	280
#define	XOR_ASSIGN	281
#define	OR_ASSIGN	282
#define	TYPE_NAME	283
#define	TYPEDEF	284
#define	EXTERN	285
#define	STATIC	286
#define	AUTO	287
#define	REGISTER	288
#define	INLINE	289
#define	RESTRICT	290
#define	CHAR	291
#define	SHORT	292
#define	INT	293
#define	LONG	294
#define	SIGNED	295
#define	UNSIGNED	296
#define	FLOAT	297
#define	DOUBLE	298
#define	CONST	299
#define	VOLATILE	300
#define	VOID	301
#define	BOOL	302
#define	COMPLEX	303
#define	IMAGINARY	304
#define	STRUCT	305
#define	UNION	306
#define	ENUM	307
#define	ELLIPSIS	308
#define	CASE	309
#define	DEFAULT	310
#define	IF	311
#define	ELSE	312
#define	SWITCH	313
#define	WHILE	314
#define	DO	315
#define	FOR	316
#define	GOTO	317
#define	CONTINUE	318
#define	BREAK	319
#define	RETURN	320


#line 143 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_CParser_CLASS
#define YY_CParser_CLASS CParser
#endif

#ifndef YY_CParser_INHERIT
#define YY_CParser_INHERIT
#endif
#ifndef YY_CParser_MEMBERS
#define YY_CParser_MEMBERS 
#endif
#ifndef YY_CParser_LEX_BODY
#define YY_CParser_LEX_BODY  
#endif
#ifndef YY_CParser_ERROR_BODY
#define YY_CParser_ERROR_BODY  
#endif
#ifndef YY_CParser_CONSTRUCTOR_PARAM
#define YY_CParser_CONSTRUCTOR_PARAM
#endif
/* choose between enum and const */
#ifndef YY_CParser_USE_CONST_TOKEN
#define YY_CParser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_CParser_USE_CONST_TOKEN != 0
#ifndef YY_CParser_ENUM_TOKEN
#define YY_CParser_ENUM_TOKEN yy_CParser_enum_token
#endif
#endif

class YY_CParser_CLASS YY_CParser_INHERIT
{
public: 
#if YY_CParser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 338 "CParser.h"
static const int IDENTIFIER;
static const int CONSTANT;
static const int STRING_LITERAL;
static const int SIZEOF;
static const int PTR_OP;
static const int INC_OP;
static const int DEC_OP;
static const int LEFT_OP;
static const int RIGHT_OP;
static const int LE_OP;
static const int GE_OP;
static const int EQ_OP;
static const int NE_OP;
static const int AND_OP;
static const int OR_OP;
static const int MUL_ASSIGN;
static const int DIV_ASSIGN;
static const int MOD_ASSIGN;
static const int ADD_ASSIGN;
static const int SUB_ASSIGN;
static const int LEFT_ASSIGN;
static const int RIGHT_ASSIGN;
static const int AND_ASSIGN;
static const int XOR_ASSIGN;
static const int OR_ASSIGN;
static const int TYPE_NAME;
static const int TYPEDEF;
static const int EXTERN;
static const int STATIC;
static const int AUTO;
static const int REGISTER;
static const int INLINE;
static const int RESTRICT;
static const int CHAR;
static const int SHORT;
static const int INT;
static const int LONG;
static const int SIGNED;
static const int UNSIGNED;
static const int FLOAT;
static const int DOUBLE;
static const int CONST;
static const int VOLATILE;
static const int VOID;
static const int BOOL;
static const int COMPLEX;
static const int IMAGINARY;
static const int STRUCT;
static const int UNION;
static const int ENUM;
static const int ELLIPSIS;
static const int CASE;
static const int DEFAULT;
static const int IF;
static const int ELSE;
static const int SWITCH;
static const int WHILE;
static const int DO;
static const int FOR;
static const int GOTO;
static const int CONTINUE;
static const int BREAK;
static const int RETURN;


#line 182 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
 /* decl const */
#else
enum YY_CParser_ENUM_TOKEN { YY_CParser_NULL_TOKEN=0

/* #line 185 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 410 "CParser.h"
	,IDENTIFIER=258
	,CONSTANT=259
	,STRING_LITERAL=260
	,SIZEOF=261
	,PTR_OP=262
	,INC_OP=263
	,DEC_OP=264
	,LEFT_OP=265
	,RIGHT_OP=266
	,LE_OP=267
	,GE_OP=268
	,EQ_OP=269
	,NE_OP=270
	,AND_OP=271
	,OR_OP=272
	,MUL_ASSIGN=273
	,DIV_ASSIGN=274
	,MOD_ASSIGN=275
	,ADD_ASSIGN=276
	,SUB_ASSIGN=277
	,LEFT_ASSIGN=278
	,RIGHT_ASSIGN=279
	,AND_ASSIGN=280
	,XOR_ASSIGN=281
	,OR_ASSIGN=282
	,TYPE_NAME=283
	,TYPEDEF=284
	,EXTERN=285
	,STATIC=286
	,AUTO=287
	,REGISTER=288
	,INLINE=289
	,RESTRICT=290
	,CHAR=291
	,SHORT=292
	,INT=293
	,LONG=294
	,SIGNED=295
	,UNSIGNED=296
	,FLOAT=297
	,DOUBLE=298
	,CONST=299
	,VOLATILE=300
	,VOID=301
	,BOOL=302
	,COMPLEX=303
	,IMAGINARY=304
	,STRUCT=305
	,UNION=306
	,ENUM=307
	,ELLIPSIS=308
	,CASE=309
	,DEFAULT=310
	,IF=311
	,ELSE=312
	,SWITCH=313
	,WHILE=314
	,DO=315
	,FOR=316
	,GOTO=317
	,CONTINUE=318
	,BREAK=319
	,RETURN=320


#line 185 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_CParser_PARSE(YY_CParser_PARSE_PARAM);
 virtual void YY_CParser_ERROR(char *msg) YY_CParser_ERROR_BODY;
#ifdef YY_CParser_PURE
#ifdef YY_CParser_LSP_NEEDED
 virtual int  YY_CParser_LEX(YY_CParser_STYPE *YY_CParser_LVAL,YY_CParser_LTYPE *YY_CParser_LLOC) YY_CParser_LEX_BODY;
#else
 virtual int  YY_CParser_LEX(YY_CParser_STYPE *YY_CParser_LVAL) YY_CParser_LEX_BODY;
#endif
#else
 virtual int YY_CParser_LEX() YY_CParser_LEX_BODY;
 YY_CParser_STYPE YY_CParser_LVAL;
#ifdef YY_CParser_LSP_NEEDED
 YY_CParser_LTYPE YY_CParser_LLOC;
#endif
 int YY_CParser_NERRS;
 int YY_CParser_CHAR;
#endif
#if YY_CParser_DEBUG != 0
public:
 int YY_CParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_CParser_CLASS(YY_CParser_CONSTRUCTOR_PARAM);
public:
 YY_CParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_CParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_CParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_CParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_CParser_DEBUG 
#define YYDEBUG YY_CParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.h" */
#line 530 "CParser.h"
#endif
