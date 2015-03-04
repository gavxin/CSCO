#define YY_CParser_h_included

/*  A Bison++ parser, made from CParser.y  */

 /* with Bison++ version bison++ Version 1.21-8, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */

#if defined( _MSDOS ) || defined(MSDOS) || defined(__MSDOS__) 
#define __MSDOS_AND_ALIKE
#endif
#if defined(_WINDOWS) && defined(_MSC_VER)
#define __HAVE_NO_ALLOCA
#define __MSDOS_AND_ALIKE
#endif

#ifndef alloca
#if defined( __GNUC__)
#define alloca __builtin_alloca

#elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi)
#include <alloca.h>

#elif defined (__MSDOS_AND_ALIKE)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif

#elif defined(_AIX)
#include <malloc.h>
#pragma alloca

#elif defined(__hpux)
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */

#endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */
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
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#define YYBISON 1  

/* #line 74 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 86 "CParser.cc"
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

#line 74 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_CParser_BISON 1
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
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_CParser_STYPE 
#define YY_CParser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_CParser_DEBUG
#define  YY_CParser_DEBUG YYDEBUG
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

/* #line 118 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 190 "CParser.cc"

#line 118 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
/*  YY_CParser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 122 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 199 "CParser.cc"

#line 122 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
/* prefix */
#ifndef YY_CParser_DEBUG

/* #line 124 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 206 "CParser.cc"

#line 124 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
/* YY_CParser_DEBUG */
#endif


#ifndef YY_CParser_LSP_NEEDED

/* #line 129 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 216 "CParser.cc"
#define YYLSP_CParser_NEEDED

#line 129 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
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
      /* We used to use `unsigned long' as YY_CParser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

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
#if YY_CParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_CParser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_CParser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_CParser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_CParser_PURE
#ifndef YYPURE
#define YYPURE YY_CParser_PURE
#endif
#endif
#ifdef YY_CParser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_CParser_DEBUG 
#endif
#endif
#ifndef YY_CParser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_CParser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_CParser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_CParser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 237 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 330 "CParser.cc"
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


#line 237 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
 /* #defines tokens */
#else
/* CLASS */
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
#ifndef YY_CParser_CONSTRUCTOR_CODE
#define YY_CParser_CONSTRUCTOR_CODE
#endif
#ifndef YY_CParser_CONSTRUCTOR_INIT
#define YY_CParser_CONSTRUCTOR_INIT
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

/* #line 281 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 443 "CParser.cc"
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


#line 281 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
 /* decl const */
#else
enum YY_CParser_ENUM_TOKEN { YY_CParser_NULL_TOKEN=0

/* #line 284 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 515 "CParser.cc"
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


#line 284 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_CParser_PARSE (YY_CParser_PARSE_PARAM);
 virtual void YY_CParser_ERROR(char *msg) YY_CParser_ERROR_BODY;
#ifdef YY_CParser_PURE
#ifdef YY_CParser_LSP_NEEDED
 virtual int  YY_CParser_LEX (YY_CParser_STYPE *YY_CParser_LVAL,YY_CParser_LTYPE *YY_CParser_LLOC) YY_CParser_LEX_BODY;
#else
 virtual int  YY_CParser_LEX (YY_CParser_STYPE *YY_CParser_LVAL) YY_CParser_LEX_BODY;
#endif
#else
 virtual int YY_CParser_LEX() YY_CParser_LEX_BODY;
 YY_CParser_STYPE YY_CParser_LVAL;
#ifdef YY_CParser_LSP_NEEDED
 YY_CParser_LTYPE YY_CParser_LLOC;
#endif
 int   YY_CParser_NERRS;
 int    YY_CParser_CHAR;
#endif
#if YY_CParser_DEBUG != 0
 int YY_CParser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_CParser_CLASS(YY_CParser_CONSTRUCTOR_PARAM);
public:
 YY_CParser_MEMBERS 
};
/* other declare folow */
#if YY_CParser_USE_CONST_TOKEN != 0

/* #line 315 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 615 "CParser.cc"
const int YY_CParser_CLASS::IDENTIFIER=258;
const int YY_CParser_CLASS::CONSTANT=259;
const int YY_CParser_CLASS::STRING_LITERAL=260;
const int YY_CParser_CLASS::SIZEOF=261;
const int YY_CParser_CLASS::PTR_OP=262;
const int YY_CParser_CLASS::INC_OP=263;
const int YY_CParser_CLASS::DEC_OP=264;
const int YY_CParser_CLASS::LEFT_OP=265;
const int YY_CParser_CLASS::RIGHT_OP=266;
const int YY_CParser_CLASS::LE_OP=267;
const int YY_CParser_CLASS::GE_OP=268;
const int YY_CParser_CLASS::EQ_OP=269;
const int YY_CParser_CLASS::NE_OP=270;
const int YY_CParser_CLASS::AND_OP=271;
const int YY_CParser_CLASS::OR_OP=272;
const int YY_CParser_CLASS::MUL_ASSIGN=273;
const int YY_CParser_CLASS::DIV_ASSIGN=274;
const int YY_CParser_CLASS::MOD_ASSIGN=275;
const int YY_CParser_CLASS::ADD_ASSIGN=276;
const int YY_CParser_CLASS::SUB_ASSIGN=277;
const int YY_CParser_CLASS::LEFT_ASSIGN=278;
const int YY_CParser_CLASS::RIGHT_ASSIGN=279;
const int YY_CParser_CLASS::AND_ASSIGN=280;
const int YY_CParser_CLASS::XOR_ASSIGN=281;
const int YY_CParser_CLASS::OR_ASSIGN=282;
const int YY_CParser_CLASS::TYPE_NAME=283;
const int YY_CParser_CLASS::TYPEDEF=284;
const int YY_CParser_CLASS::EXTERN=285;
const int YY_CParser_CLASS::STATIC=286;
const int YY_CParser_CLASS::AUTO=287;
const int YY_CParser_CLASS::REGISTER=288;
const int YY_CParser_CLASS::INLINE=289;
const int YY_CParser_CLASS::RESTRICT=290;
const int YY_CParser_CLASS::CHAR=291;
const int YY_CParser_CLASS::SHORT=292;
const int YY_CParser_CLASS::INT=293;
const int YY_CParser_CLASS::LONG=294;
const int YY_CParser_CLASS::SIGNED=295;
const int YY_CParser_CLASS::UNSIGNED=296;
const int YY_CParser_CLASS::FLOAT=297;
const int YY_CParser_CLASS::DOUBLE=298;
const int YY_CParser_CLASS::CONST=299;
const int YY_CParser_CLASS::VOLATILE=300;
const int YY_CParser_CLASS::VOID=301;
const int YY_CParser_CLASS::BOOL=302;
const int YY_CParser_CLASS::COMPLEX=303;
const int YY_CParser_CLASS::IMAGINARY=304;
const int YY_CParser_CLASS::STRUCT=305;
const int YY_CParser_CLASS::UNION=306;
const int YY_CParser_CLASS::ENUM=307;
const int YY_CParser_CLASS::ELLIPSIS=308;
const int YY_CParser_CLASS::CASE=309;
const int YY_CParser_CLASS::DEFAULT=310;
const int YY_CParser_CLASS::IF=311;
const int YY_CParser_CLASS::ELSE=312;
const int YY_CParser_CLASS::SWITCH=313;
const int YY_CParser_CLASS::WHILE=314;
const int YY_CParser_CLASS::DO=315;
const int YY_CParser_CLASS::FOR=316;
const int YY_CParser_CLASS::GOTO=317;
const int YY_CParser_CLASS::CONTINUE=318;
const int YY_CParser_CLASS::BREAK=319;
const int YY_CParser_CLASS::RETURN=320;


#line 315 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
 /* const YY_CParser_CLASS::token */
#endif
/*apres const  */
YY_CParser_CLASS::YY_CParser_CLASS(YY_CParser_CONSTRUCTOR_PARAM) YY_CParser_CONSTRUCTOR_INIT
{
#if YY_CParser_DEBUG != 0
YY_CParser_DEBUG_FLAG=0;
#endif
YY_CParser_CONSTRUCTOR_CODE;
};
#endif

/* #line 326 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 695 "CParser.cc"


#define	YYFINAL		401
#define	YYFLAG		32768
#define	YYNTBASE	90

#define YYTRANSLATE(x) ((unsigned)(x) <= 320 ? yytranslate[x] : 158)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    79,     2,     2,     2,    81,    74,     2,    66,
    67,    75,    76,    73,    77,    70,    80,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    87,    89,    82,
    88,    83,    86,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    68,     2,    69,    84,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    71,    85,    72,    78,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65
};

#if YY_CParser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     6,    10,    12,    17,    21,    26,    30,
    34,    37,    40,    47,    55,    57,    61,    63,    66,    69,
    72,    75,    80,    82,    84,    86,    88,    90,    92,    94,
    99,   101,   105,   109,   113,   115,   119,   123,   125,   129,
   133,   135,   139,   143,   147,   151,   153,   157,   161,   163,
   167,   169,   173,   175,   179,   181,   185,   187,   191,   193,
   199,   201,   205,   207,   209,   211,   213,   215,   217,   219,
   221,   223,   225,   227,   229,   233,   235,   238,   242,   244,
   247,   249,   252,   254,   257,   259,   262,   264,   268,   270,
   274,   276,   278,   280,   282,   284,   286,   288,   290,   292,
   294,   296,   298,   300,   302,   304,   306,   308,   310,   312,
   314,   320,   325,   328,   330,   332,   334,   337,   341,   344,
   346,   349,   351,   353,   357,   359,   362,   366,   371,   377,
   383,   390,   393,   395,   399,   401,   405,   407,   409,   411,
   413,   416,   418,   420,   424,   430,   435,   440,   447,   454,
   460,   465,   469,   474,   479,   483,   485,   488,   491,   495,
   497,   500,   502,   506,   508,   512,   515,   518,   520,   522,
   526,   528,   531,   533,   535,   538,   542,   545,   549,   553,
   558,   562,   567,   570,   574,   578,   583,   585,   589,   594,
   596,   599,   603,   608,   611,   613,   616,   620,   623,   625,
   627,   629,   631,   633,   635,   639,   644,   648,   651,   655,
   657,   660,   662,   664,   666,   669,   675,   683,   689,   695,
   703,   710,   718,   725,   733,   737,   740,   743,   746,   750,
   752,   755,   757,   759,   761,   766,   770,   772
};

static const short yyrhs[] = {     3,
     0,     4,     0,     5,     0,    66,   109,    67,     0,    90,
     0,    91,    68,   109,    69,     0,    91,    66,    67,     0,
    91,    66,    92,    67,     0,    91,    70,     3,     0,    91,
     7,     3,     0,    91,     8,     0,    91,     9,     0,    66,
   137,    67,    71,   141,    72,     0,    66,   137,    67,    71,
   141,    73,    72,     0,   107,     0,    92,    73,   107,     0,
    91,     0,     8,    93,     0,     9,    93,     0,    94,    95,
     0,     6,    93,     0,     6,    66,   137,    67,     0,    74,
     0,    75,     0,    76,     0,    77,     0,    78,     0,    79,
     0,    93,     0,    66,   137,    67,    95,     0,    95,     0,
    96,    75,    95,     0,    96,    80,    95,     0,    96,    81,
    95,     0,    96,     0,    97,    76,    96,     0,    97,    77,
    96,     0,    97,     0,    98,    10,    97,     0,    98,    11,
    97,     0,    98,     0,    99,    82,    98,     0,    99,    83,
    98,     0,    99,    12,    98,     0,    99,    13,    98,     0,
    99,     0,   100,    14,    99,     0,   100,    15,    99,     0,
   100,     0,   101,    74,   100,     0,   101,     0,   102,    84,
   101,     0,   102,     0,   103,    85,   102,     0,   103,     0,
   104,    16,   103,     0,   104,     0,   105,    17,   104,     0,
   105,     0,   105,    86,   109,    87,   106,     0,   106,     0,
    93,   108,   107,     0,    88,     0,    18,     0,    19,     0,
    20,     0,    21,     0,    22,     0,    23,     0,    24,     0,
    25,     0,    26,     0,    27,     0,   107,     0,   109,    73,
   107,     0,   106,     0,   112,    89,     0,   112,   113,    89,
     0,   115,     0,   115,   112,     0,   116,     0,   116,   112,
     0,   127,     0,   127,   112,     0,   128,     0,   128,   112,
     0,   114,     0,   113,    73,   114,     0,   129,     0,   129,
    88,   140,     0,    29,     0,    30,     0,    31,     0,    32,
     0,    33,     0,    46,     0,    36,     0,    37,     0,    38,
     0,    39,     0,    42,     0,    43,     0,    40,     0,    41,
     0,    47,     0,    48,     0,    49,     0,   117,     0,   124,
     0,    28,     0,   118,     3,    71,   119,    72,     0,   118,
    71,   119,    72,     0,   118,     3,     0,    50,     0,    51,
     0,   120,     0,   119,   120,     0,   121,   122,    89,     0,
   116,   121,     0,   116,     0,   127,   121,     0,   127,     0,
   123,     0,   122,    73,   123,     0,   129,     0,    87,   110,
     0,   129,    87,   110,     0,    52,    71,   125,    72,     0,
    52,     3,    71,   125,    72,     0,    52,    71,   125,    73,
    72,     0,    52,     3,    71,   125,    73,    72,     0,    52,
     3,     0,   126,     0,   125,    73,   126,     0,     3,     0,
     3,    88,   110,     0,    44,     0,    35,     0,    45,     0,
    34,     0,   131,   130,     0,   130,     0,     3,     0,    66,
   129,    67,     0,   130,    68,   132,   107,    69,     0,   130,
    68,   132,    69,     0,   130,    68,   107,    69,     0,   130,
    68,    31,   132,   107,    69,     0,   130,    68,   132,    31,
   107,    69,     0,   130,    68,   132,    75,    69,     0,   130,
    68,    75,    69,     0,   130,    68,    69,     0,   130,    66,
   133,    67,     0,   130,    66,   136,    67,     0,   130,    66,
    67,     0,    75,     0,    75,   132,     0,    75,   131,     0,
    75,   132,   131,     0,   127,     0,   132,   127,     0,   134,
     0,   134,    73,    53,     0,   135,     0,   134,    73,   135,
     0,   112,   129,     0,   112,   138,     0,   112,     0,     3,
     0,   136,    73,     3,     0,   121,     0,   121,   138,     0,
   131,     0,   139,     0,   131,   139,     0,    66,   138,    67,
     0,    68,    69,     0,    68,   107,    69,     0,   139,    68,
    69,     0,   139,    68,   107,    69,     0,    68,    75,    69,
     0,   139,    68,    75,    69,     0,    66,    67,     0,    66,
   133,    67,     0,   139,    66,    67,     0,   139,    66,   133,
    67,     0,   107,     0,    71,   141,    72,     0,    71,   141,
    73,    72,     0,   140,     0,   142,   140,     0,   141,    73,
   140,     0,   141,    73,   142,   140,     0,   143,    88,     0,
   144,     0,   143,   144,     0,    68,   110,    69,     0,    70,
     3,     0,   146,     0,   147,     0,   150,     0,   151,     0,
   152,     0,   153,     0,     3,    87,   145,     0,    54,   110,
    87,   145,     0,    55,    87,   145,     0,    71,    72,     0,
    71,   148,    72,     0,   149,     0,   148,   149,     0,   111,
     0,   145,     0,    89,     0,   109,    89,     0,    56,    66,
   109,    67,   145,     0,    56,    66,   109,    67,   145,    57,
   145,     0,    58,    66,   109,    67,   145,     0,    59,    66,
   109,    67,   145,     0,    60,   145,    59,    66,   109,    67,
    89,     0,    61,    66,   150,   150,    67,   145,     0,    61,
    66,   150,   150,   109,    67,   145,     0,    61,    66,   111,
   150,    67,   145,     0,    61,    66,   111,   150,   109,    67,
   145,     0,    62,     3,    89,     0,    63,    89,     0,    64,
    89,     0,    65,    89,     0,    65,   109,    89,     0,   155,
     0,   154,   155,     0,   156,     0,   111,     0,    89,     0,
   112,   129,   157,   147,     0,   112,   129,   147,     0,   111,
     0,   157,   111,     0
};

#endif

#if YY_CParser_DEBUG != 0
static const short yyrline[] = { 0,
   101,   105,   109,   113,   120,   124,   128,   132,   136,   140,
   144,   148,   152,   156,   163,   167,   174,   178,   182,   186,
   190,   194,   201,   203,   205,   207,   209,   211,   215,   219,
   226,   230,   234,   238,   245,   249,   253,   260,   264,   268,
   275,   279,   283,   287,   291,   298,   302,   306,   313,   317,
   324,   328,   335,   339,   346,   350,   357,   361,   368,   372,
   379,   383,   390,   392,   394,   396,   398,   400,   402,   404,
   406,   408,   410,   415,   419,   426,   433,   440,   453,   455,
   457,   461,   465,   469,   473,   477,   484,   488,   499,   503,
   510,   512,   514,   516,   518,   523,   525,   527,   529,   531,
   533,   535,   537,   539,   541,   543,   545,   547,   549,   551,
   556,   560,   564,   571,   573,   578,   582,   589,   596,   600,
   604,   608,   615,   619,   626,   630,   634,   641,   645,   649,
   653,   657,   664,   668,   675,   679,   686,   688,   690,   695,
   700,   704,   713,   717,   721,   725,   729,   733,   737,   741,
   745,   749,   753,   757,   761,   768,   772,   776,   780,   787,
   791,   799,   803,   810,   814,   821,   825,   829,   836,   840,
   847,   851,   858,   862,   866,   873,   877,   881,   885,   889,
   893,   897,   901,   905,   909,   913,   920,   924,   928,   935,
   939,   943,   947,   954,   961,   965,   972,   976,   983,   987,
   991,   995,   999,  1003,  1010,  1014,  1018,  1025,  1029,  1036,
  1040,  1049,  1054,  1062,  1066,  1073,  1077,  1081,  1088,  1092,
  1096,  1100,  1104,  1108,  1115,  1119,  1123,  1127,  1131,  1138,
  1143,  1151,  1155,  1159,  1166,  1172,  1181,  1185
};

static const char * const yytname[] = {   "$","error","$illegal.","IDENTIFIER",
"CONSTANT","STRING_LITERAL","SIZEOF","PTR_OP","INC_OP","DEC_OP","LEFT_OP","RIGHT_OP",
"LE_OP","GE_OP","EQ_OP","NE_OP","AND_OP","OR_OP","MUL_ASSIGN","DIV_ASSIGN","MOD_ASSIGN",
"ADD_ASSIGN","SUB_ASSIGN","LEFT_ASSIGN","RIGHT_ASSIGN","AND_ASSIGN","XOR_ASSIGN",
"OR_ASSIGN","TYPE_NAME","TYPEDEF","EXTERN","STATIC","AUTO","REGISTER","INLINE",
"RESTRICT","CHAR","SHORT","INT","LONG","SIGNED","UNSIGNED","FLOAT","DOUBLE",
"CONST","VOLATILE","VOID","BOOL","COMPLEX","IMAGINARY","STRUCT","UNION","ENUM",
"ELLIPSIS","CASE","DEFAULT","IF","ELSE","SWITCH","WHILE","DO","FOR","GOTO","CONTINUE",
"BREAK","RETURN","'('","')'","'['","']'","'.'","'{'","'}'","','","'&'","'*'",
"'+'","'-'","'~'","'!'","'/'","'%'","'<'","'>'","'^'","'|'","'?'","':'","'='",
"';'","primary_expression","postfix_expression","argument_expression_list","unary_expression",
"unary_operator","cast_expression","multiplicative_expression","additive_expression",
"shift_expression","relational_expression","equality_expression","and_expression",
"exclusive_or_expression","inclusive_or_expression","logical_and_expression",
"logical_or_expression","conditional_expression","assignment_expression","assignment_operator",
"expression","constant_expression","declaration","declaration_specifiers","init_declarator_list",
"init_declarator","storage_class_specifier","type_specifier","struct_or_union_specifier",
"struct_or_union","struct_declaration_list","struct_declaration","specifier_qualifier_list",
"struct_declarator_list","struct_declarator","enum_specifier","enumerator_list",
"enumerator","type_qualifier","function_specifier","declarator","direct_declarator",
"pointer","type_qualifier_list","parameter_type_list","parameter_list","parameter_declaration",
"identifier_list","type_name","abstract_declarator","direct_abstract_declarator",
"initializer","initializer_list","designation","designator_list","designator",
"statement","labeled_statement","compound_statement","block_item_list","block_item",
"expression_statement","selection_statement","iteration_statement","jump_statement",
"translation_unit","external_declaration","function_definition","declaration_list",
""
};
#endif

static const short yyr1[] = {     0,
    90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
    91,    91,    91,    91,    92,    92,    93,    93,    93,    93,
    93,    93,    94,    94,    94,    94,    94,    94,    95,    95,
    96,    96,    96,    96,    97,    97,    97,    98,    98,    98,
    99,    99,    99,    99,    99,   100,   100,   100,   101,   101,
   102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
   107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
   108,   108,   108,   109,   109,   110,   111,   111,   112,   112,
   112,   112,   112,   112,   112,   112,   113,   113,   114,   114,
   115,   115,   115,   115,   115,   116,   116,   116,   116,   116,
   116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
   117,   117,   117,   118,   118,   119,   119,   120,   121,   121,
   121,   121,   122,   122,   123,   123,   123,   124,   124,   124,
   124,   124,   125,   125,   126,   126,   127,   127,   127,   128,
   129,   129,   130,   130,   130,   130,   130,   130,   130,   130,
   130,   130,   130,   130,   130,   131,   131,   131,   131,   132,
   132,   133,   133,   134,   134,   135,   135,   135,   136,   136,
   137,   137,   138,   138,   138,   139,   139,   139,   139,   139,
   139,   139,   139,   139,   139,   139,   140,   140,   140,   141,
   141,   141,   141,   142,   143,   143,   144,   144,   145,   145,
   145,   145,   145,   145,   146,   146,   146,   147,   147,   148,
   148,   149,   149,   150,   150,   151,   151,   151,   152,   152,
   152,   152,   152,   152,   153,   153,   153,   153,   153,   154,
   154,   155,   155,   155,   156,   156,   157,   157
};

static const short yyr2[] = {     0,
     1,     1,     1,     3,     1,     4,     3,     4,     3,     3,
     2,     2,     6,     7,     1,     3,     1,     2,     2,     2,
     2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
     1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
     1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
     1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
     1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     5,     4,     2,     1,     1,     1,     2,     3,     2,     1,
     2,     1,     1,     3,     1,     2,     3,     4,     5,     5,
     6,     2,     1,     3,     1,     3,     1,     1,     1,     1,
     2,     1,     1,     3,     5,     4,     4,     6,     6,     5,
     4,     3,     4,     4,     3,     1,     2,     2,     3,     1,
     2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
     1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
     3,     4,     2,     3,     3,     4,     1,     3,     4,     1,
     2,     3,     4,     2,     1,     2,     3,     2,     1,     1,
     1,     1,     1,     1,     3,     4,     3,     2,     3,     1,
     2,     1,     1,     1,     2,     5,     7,     5,     5,     7,
     6,     7,     6,     7,     3,     2,     2,     2,     3,     1,
     2,     1,     1,     1,     4,     3,     1,     2
};

static const short yydefact[] = {     0,
   110,    91,    92,    93,    94,    95,   140,   138,    97,    98,
    99,   100,   103,   104,   101,   102,   137,   139,    96,   105,
   106,   107,   114,   115,     0,   234,   233,     0,    79,    81,
   108,     0,   109,    83,    85,     0,   230,   232,   132,     0,
   143,     0,   156,    77,     0,    87,    89,   142,     0,    80,
    82,   113,     0,    84,    86,   231,     0,   135,     0,   133,
     0,   160,   158,   157,     0,    78,     0,     0,   237,     0,
   236,     0,     0,     0,   141,     0,   120,     0,   116,     0,
   122,     0,     0,   128,     0,   144,   161,   159,    88,    89,
     1,     2,     3,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   208,    23,
    24,    25,    26,    27,    28,   214,     5,    17,    29,     0,
    31,    35,    38,    41,    46,    49,    51,    53,    55,    57,
    59,    61,    74,     0,   212,   213,   199,   200,     0,   210,
   201,   202,   203,   204,     1,     0,   187,    90,   238,   235,
   169,   155,   168,     0,   162,   164,     0,     0,   152,    24,
     0,     0,     0,   119,   112,   117,     0,     0,   123,   125,
   121,   129,     0,    29,    76,   136,   130,   134,     0,     0,
    21,     0,    18,    19,     0,     0,     0,     0,     0,     0,
     0,     0,   226,   227,   228,     0,     0,   171,     0,     0,
    11,    12,     0,     0,     0,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    63,     0,    20,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   215,   209,
   211,     0,     0,   190,     0,     0,     0,   195,     0,     0,
   166,   173,   167,   174,   153,     0,   154,     0,     0,   151,
   147,     0,   146,    24,     0,   111,   126,     0,   118,     0,
   131,   205,     0,     0,     0,   207,     0,     0,     0,     0,
     0,     0,   225,   229,     4,     0,   173,   172,     0,    10,
     7,     0,    15,     0,     9,    62,    32,    33,    34,    36,
    37,    39,    40,    44,    45,    42,    43,    47,    48,    50,
    52,    54,    56,    58,     0,    75,     0,   198,   188,     0,
   191,   194,   196,   183,     0,     0,   177,    24,     0,   175,
     0,     0,   163,   165,   170,     0,     0,   150,   145,   124,
   127,    22,     0,   206,     0,     0,     0,     0,     0,     0,
     0,    30,     8,     0,     6,     0,   197,   189,   192,     0,
   184,   176,   181,   178,   185,     0,   179,    24,     0,   148,
   149,   216,   218,   219,     0,     0,     0,     0,     0,     0,
    16,    60,   193,   186,   182,   180,     0,     0,   223,     0,
   221,     0,    13,     0,   217,   220,   224,   222,    14,     0,
     0
};

static const short yydefgoto[] = {   117,
   118,   292,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   217,   134,   176,
    27,    70,    45,    46,    29,    30,    31,    32,    78,    79,
    80,   168,   169,    33,    59,    60,    34,    35,    61,    48,
    49,    64,   325,   155,   156,   157,   199,   326,   254,   244,
   245,   246,   247,   248,   136,   137,   138,   139,   140,   141,
   142,   143,   144,    36,    37,    38,    72
};

static const short yypact[] = {  1177,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    45,-32768,-32768,    18,  1497,  1497,
-32768,    64,-32768,  1497,  1497,   309,-32768,-32768,   -27,    69,
-32768,    59,   149,-32768,   -63,-32768,  1202,    80,    19,-32768,
-32768,   -10,  1522,-32768,-32768,-32768,    69,    -7,   102,-32768,
    62,-32768,-32768,   149,    59,-32768,   371,   850,-32768,    18,
-32768,  1387,  1137,   689,    80,  1522,  1522,  1304,-32768,    57,
  1522,   124,   991,-32768,    52,-32768,-32768,-32768,-32768,    68,
    90,-32768,-32768,   998,  1035,  1035,   991,    98,   185,   202,
   213,   575,   240,   260,   196,   200,   307,   639,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   157,   217,   991,
-32768,    79,   156,   237,    58,   268,   229,   224,   222,   298,
    41,-32768,-32768,   -35,-32768,-32768,-32768,-32768,   448,-32768,
-32768,-32768,-32768,-32768,-32768,   815,-32768,-32768,-32768,-32768,
-32768,-32768,    24,   252,   247,-32768,    85,   128,-32768,   253,
   254,   738,  1342,-32768,-32768,-32768,   991,    42,-32768,   234,
-32768,-32768,    77,-32768,-32768,-32768,-32768,-32768,   575,   639,
-32768,   639,-32768,-32768,   238,   575,   991,   991,   991,   265,
   525,   241,-32768,-32768,-32768,    53,   109,   123,   259,   326,
-32768,-32768,   865,   991,   329,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   991,-32768,   991,   991,
   991,   991,   991,   991,   991,   991,   991,   991,   991,   991,
   991,   991,   991,   991,   991,   991,   991,   991,-32768,-32768,
-32768,   991,   330,-32768,   219,   850,    51,-32768,  1087,   466,
-32768,    20,-32768,   120,-32768,  1471,-32768,   331,   822,-32768,
-32768,   991,-32768,   266,   293,-32768,-32768,    57,-32768,   991,
-32768,-32768,   296,   297,   575,-32768,   153,   179,   193,   299,
   543,   543,-32768,-32768,-32768,  1263,   212,-32768,   899,-32768,
-32768,   194,-32768,   148,-32768,-32768,-32768,-32768,-32768,    79,
    79,   156,   156,   237,   237,   237,   237,    58,    58,   268,
   229,   224,   222,   298,    16,-32768,   300,-32768,-32768,   722,
-32768,-32768,-32768,-32768,   301,   303,-32768,   302,   318,   120,
  1431,   914,-32768,-32768,-32768,   319,   320,-32768,-32768,-32768,
-32768,   295,   295,-32768,   575,   575,   575,   991,   942,   958,
   815,-32768,-32768,   991,-32768,   991,-32768,-32768,-32768,   850,
-32768,-32768,-32768,-32768,-32768,   305,-32768,   321,   322,-32768,
-32768,   310,-32768,-32768,   197,   575,   204,   575,   208,   223,
-32768,-32768,-32768,-32768,-32768,-32768,   575,   289,-32768,   575,
-32768,   575,-32768,   771,-32768,-32768,-32768,-32768,-32768,   392,
-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   -20,-32768,  -111,    75,    76,     2,    87,   161,
   162,   160,   189,   192,-32768,   -80,   -67,-32768,   -76,   -89,
   -22,     0,-32768,   332,-32768,   -12,-32768,-32768,   362,   -58,
   -62,-32768,   171,-32768,   383,   -79,   -25,-32768,   -23,   -33,
   -31,   -61,   -69,-32768,   188,-32768,   -37,  -116,  -228,   -66,
   104,  -280,-32768,   211,   -88,-32768,    -4,-32768,   323,  -180,
-32768,-32768,-32768,-32768,   405,-32768,-32768
};


#define	YYLAST		1574


static const short yytable[] = {    28,
   147,   148,   175,   154,    47,   178,   161,   185,   218,    65,
   282,    63,   162,   190,   164,    75,   175,    62,   171,   166,
    41,    41,    41,   330,    69,    66,    41,    81,    50,    51,
   196,   197,    88,    54,    55,    28,   253,   238,    87,   360,
    77,    90,    71,    57,   135,   198,    90,    39,    62,   149,
    81,    81,    81,   239,    58,    81,   170,   236,   330,    41,
    76,    41,   174,    77,    77,    77,    52,   150,    77,   226,
   227,    58,   153,   181,   183,   184,   174,   267,   147,    58,
    83,   288,    81,    42,    42,   249,   175,   250,   238,   249,
   272,   250,    43,   178,   265,    77,   259,   276,    43,   174,
   349,   350,   356,   197,   166,   197,    44,   297,   298,   299,
   277,   278,   279,   360,   268,    40,   135,   198,   242,   198,
   243,   252,    42,   177,    42,   238,   237,   294,    86,   251,
   269,    43,    62,    43,    53,   293,    87,    81,   322,   228,
   229,   284,   273,   167,   274,    73,   174,    74,   271,   296,
    77,   257,   317,   219,    81,    68,    81,   258,   220,   221,
   315,   175,     8,   200,   201,   202,   287,    77,   281,    77,
   316,    17,    18,    84,    85,   285,   179,   352,   147,   321,
   341,   238,   329,     8,   186,   331,   344,   332,   286,   175,
   250,   336,    17,    18,   337,   172,   173,    43,   174,   174,
   174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
   174,   174,   174,   174,   174,   174,   355,   252,    75,   345,
   238,   174,   203,    43,   204,   238,   205,   304,   305,   306,
   307,   222,   223,    87,   206,   207,   208,   209,   210,   211,
   212,   213,   214,   215,   170,   346,   224,   225,   153,   174,
   187,   238,   147,   359,   287,   153,   372,   373,   374,   347,
   353,   366,   192,   388,   369,   238,   354,   188,   174,   238,
   390,   375,   377,   379,   392,   382,   238,   286,   189,   250,
   238,   230,   231,   147,   193,   153,   381,   389,   194,   391,
   319,   320,   147,   383,   393,   394,   300,   301,   395,   302,
   303,   397,   232,   398,   216,   191,   234,   233,   400,   145,
    92,    93,    94,   235,    95,    96,   308,   309,   255,   256,
   270,   260,   261,   280,   275,   289,   147,   359,   290,   283,
   153,   295,   318,   335,   338,   174,     1,     2,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
    25,   339,   342,   343,   348,   351,   387,   361,   357,   362,
   363,   384,   108,    91,    92,    93,    94,   396,    95,    96,
   110,   111,   112,   113,   114,   115,   364,   370,   371,   385,
   386,   401,   310,   312,   311,   195,    89,    26,     1,     2,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    24,    25,   313,    97,    98,    99,   314,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   163,   340,    82,
    56,    67,   109,   334,   110,   111,   112,   113,   114,   115,
    91,    92,    93,    94,   380,    95,    96,   323,     0,   116,
     0,   241,     0,     0,     0,     0,     0,     0,   145,    92,
    93,    94,     0,    95,    96,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     0,    97,    98,    99,     0,   100,   101,   102,   103,   104,
   105,   106,   107,   108,     0,     0,     0,     0,    67,   240,
     0,   110,   111,   112,   113,   114,   115,   145,    92,    93,
    94,   108,    95,    96,   327,     0,   116,     0,     0,   110,
   328,   112,   113,   114,   115,   145,    92,    93,    94,     0,
    95,    96,     1,     2,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
    19,    20,    21,    22,    23,    24,    25,    91,    92,    93,
    94,     0,    95,    96,     0,     0,     0,     0,     0,     0,
   108,     0,     0,     0,     0,     0,     0,     0,   110,   111,
   112,   113,   114,   115,     0,     0,     0,     0,   108,     0,
     0,     0,     0,   116,     0,     0,   110,   111,   112,   113,
   114,   115,     0,     0,     0,     0,     0,     0,    97,    98,
    99,   116,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   145,    92,    93,    94,    67,    95,    96,   110,   111,
   112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   116,     0,     0,     1,     0,     0,     0,
     0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
    25,   145,    92,    93,    94,     0,    95,    96,     0,     0,
     0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
     0,     0,   110,   111,   112,   113,   114,   115,     0,   158,
     0,     0,     0,     8,   145,    92,    93,    94,     0,    95,
    96,     0,    17,    18,     0,     0,     0,     0,     0,     0,
   145,    92,    93,    94,     0,    95,    96,     0,     0,     0,
     0,     0,     0,     0,   108,     0,     0,   159,     0,     0,
     0,     0,   110,   160,   112,   113,   114,   115,   262,     0,
     0,     0,     8,   145,    92,    93,    94,     0,    95,    96,
     0,    17,    18,     0,     0,     0,     0,   108,     0,   242,
     0,   243,   146,   358,     0,   110,   111,   112,   113,   114,
   115,     0,     0,   108,     0,     0,   263,     0,     0,     0,
     0,   110,   264,   112,   113,   114,   115,   145,    92,    93,
    94,     0,    95,    96,   145,    92,    93,    94,     0,    95,
    96,     0,     0,     0,     0,     0,   108,     0,   242,     0,
   243,   146,   399,     0,   110,   111,   112,   113,   114,   115,
     0,     0,   145,    92,    93,    94,     8,    95,    96,     0,
     0,     0,     0,     0,     0,    17,    18,   145,    92,    93,
    94,     0,    95,    96,     0,     0,     0,     0,     0,     0,
   108,     0,   242,     0,   243,   146,     0,   108,   110,   111,
   112,   113,   114,   115,     0,   110,   111,   112,   113,   114,
   115,   145,    92,    93,    94,     0,    95,    96,     0,     0,
     0,     0,     0,     0,     0,   108,   145,    92,    93,    94,
   146,    95,    96,   110,   111,   112,   113,   114,   115,     0,
   108,   291,     0,     0,     0,     0,     0,     0,   110,   111,
   112,   113,   114,   115,   145,    92,    93,    94,     0,    95,
    96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   145,    92,    93,    94,   108,    95,    96,     0,     0,   351,
     0,     0,   110,   111,   112,   113,   114,   115,     0,   108,
     0,     0,   367,     0,     0,     0,     0,   110,   368,   112,
   113,   114,   115,   145,    92,    93,    94,     0,    95,    96,
   145,    92,    93,    94,     0,    95,    96,   108,   376,     0,
     0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
   115,     0,     0,   108,   378,     0,     0,     0,     0,     0,
     0,   110,   111,   112,   113,   114,   115,   145,    92,    93,
    94,     0,    95,    96,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
     0,     0,     0,   180,   110,   111,   112,   113,   114,   115,
     0,   110,   111,   112,   113,   114,   115,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   182,     0,     0,     0,     0,     0,     0,     0,   110,   111,
   112,   113,   114,   115,     1,     2,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,   151,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   249,   324,   250,     0,     0,     0,     0,     0,
     0,    43,     0,     0,     1,     2,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   152,     1,     2,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
     0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   286,   324,
   250,     1,     0,     0,     0,     0,     0,    43,     8,     9,
    10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
    20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
     0,     0,     0,     0,     0,   165,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   266,     1,     2,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    67,     1,     2,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   365,     1,     2,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    24,    25,   333,     1,     2,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
     0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,    24,    25
};

static const short yycheck[] = {     0,
    68,    68,    83,    73,    28,    85,    74,    97,   120,    73,
   191,    43,    74,   102,    77,    49,    97,    43,    81,    78,
     3,     3,     3,   252,    47,    89,     3,    53,    29,    30,
   107,   108,    64,    34,    35,    36,   153,    73,    64,   320,
    53,    65,    47,    71,    67,   108,    70,     3,    74,    72,
    76,    77,    78,    89,     3,    81,    80,    17,   287,     3,
    71,     3,    83,    76,    77,    78,     3,    72,    81,    12,
    13,     3,    73,    94,    95,    96,    97,   167,   146,     3,
    88,   198,   108,    66,    66,    66,   167,    68,    73,    66,
   179,    68,    75,   173,   162,   108,   158,   186,    75,   120,
   281,   282,    87,   180,   163,   182,    89,   219,   220,   221,
   187,   188,   189,   394,    73,    71,   139,   180,    68,   182,
    70,   153,    66,    72,    66,    73,    86,   204,    67,   153,
    89,    75,   158,    75,    71,   203,   162,   163,    88,    82,
    83,    89,   180,    87,   182,    66,   167,    68,    72,   217,
   163,    67,   242,    75,   180,    88,   182,    73,    80,    81,
   237,   242,    35,     7,     8,     9,   198,   180,   191,   182,
   238,    44,    45,    72,    73,    67,    87,   289,   246,   246,
   270,    73,   250,    35,    87,    66,   275,    68,    66,   270,
    68,   259,    44,    45,   262,    72,    73,    75,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,    69,   249,   252,    67,
    73,   242,    66,    75,    68,    73,    70,   226,   227,   228,
   229,    76,    77,   259,    18,    19,    20,    21,    22,    23,
    24,    25,    26,    27,   268,    67,    10,    11,   249,   270,
    66,    73,   320,   320,   286,   256,   345,   346,   347,    67,
    67,   331,     3,    67,   332,    73,    73,    66,   289,    73,
    67,   348,   349,   350,    67,   356,    73,    66,    66,    68,
    73,    14,    15,   351,    89,   286,   354,   376,    89,   378,
    72,    73,   360,   360,    72,    73,   222,   223,   387,   224,
   225,   390,    74,   392,    88,    66,    85,    84,     0,     3,
     4,     5,     6,    16,     8,     9,   230,   231,    67,    73,
    87,    69,    69,    59,    87,    67,   394,   394,     3,    89,
   331,     3,     3,     3,    69,   356,    28,    29,    30,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    69,    67,    67,    66,    71,    57,    67,    69,    67,
    69,    67,    66,     3,     4,     5,     6,    89,     8,     9,
    74,    75,    76,    77,    78,    79,    69,    69,    69,    69,
    69,     0,   232,   234,   233,    89,    65,    89,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,   235,    54,    55,    56,   236,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    76,   268,    57,
    36,    71,    72,   256,    74,    75,    76,    77,    78,    79,
     3,     4,     5,     6,   351,     8,     9,   247,    -1,    89,
    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
     5,     6,    -1,     8,     9,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    -1,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
    -1,    74,    75,    76,    77,    78,    79,     3,     4,     5,
     6,    66,     8,     9,    69,    -1,    89,    -1,    -1,    74,
    75,    76,    77,    78,    79,     3,     4,     5,     6,    -1,
     8,     9,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,     3,     4,     5,
     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
    76,    77,    78,    79,    -1,    -1,    -1,    -1,    66,    -1,
    -1,    -1,    -1,    89,    -1,    -1,    74,    75,    76,    77,
    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
    56,    89,    58,    59,    60,    61,    62,    63,    64,    65,
    66,     3,     4,     5,     6,    71,     8,     9,    74,    75,
    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    89,    -1,    -1,    28,    -1,    -1,    -1,
    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    31,
    -1,    -1,    -1,    35,     3,     4,     5,     6,    -1,     8,
     9,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    -1,    -1,
    -1,    -1,    74,    75,    76,    77,    78,    79,    31,    -1,
    -1,    -1,    35,     3,     4,     5,     6,    -1,     8,     9,
    -1,    44,    45,    -1,    -1,    -1,    -1,    66,    -1,    68,
    -1,    70,    71,    72,    -1,    74,    75,    76,    77,    78,
    79,    -1,    -1,    66,    -1,    -1,    69,    -1,    -1,    -1,
    -1,    74,    75,    76,    77,    78,    79,     3,     4,     5,
     6,    -1,     8,     9,     3,     4,     5,     6,    -1,     8,
     9,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    -1,
    70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
    -1,    -1,     3,     4,     5,     6,    35,     8,     9,    -1,
    -1,    -1,    -1,    -1,    -1,    44,    45,     3,     4,     5,
     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
    66,    -1,    68,    -1,    70,    71,    -1,    66,    74,    75,
    76,    77,    78,    79,    -1,    74,    75,    76,    77,    78,
    79,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    66,     3,     4,     5,     6,
    71,     8,     9,    74,    75,    76,    77,    78,    79,    -1,
    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
    76,    77,    78,    79,     3,     4,     5,     6,    -1,     8,
     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     3,     4,     5,     6,    66,     8,     9,    -1,    -1,    71,
    -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    66,
    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    75,    76,
    77,    78,    79,     3,     4,     5,     6,    -1,     8,     9,
     3,     4,     5,     6,    -1,     8,     9,    66,    67,    -1,
    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
    79,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
    -1,    74,    75,    76,    77,    78,    79,     3,     4,     5,
     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
    -1,    -1,    -1,    66,    74,    75,    76,    77,    78,    79,
    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
    76,    77,    78,    79,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,     3,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
    -1,    75,    -1,    -1,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    67,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
    68,    28,    -1,    -1,    -1,    -1,    -1,    75,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
    -1,    -1,    -1,    -1,    -1,    72,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    72,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    28,
    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52
};

#line 326 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#if YY_CParser_USE_GOTO != 0
/* 
 SUPRESSION OF GOTO : on some C++ compiler (sun c++)
  the goto is strictly forbidden if any constructor/destructor
  is used in the whole function (very stupid isn't it ?)
 so goto are to be replaced with a 'while/switch/case construct'
 here are the macro to keep some apparent compatibility
*/
#define YYGOTO(lb) {yy_gotostate=lb;continue;}
#define YYBEGINGOTO  enum yy_labels yy_gotostate=yygotostart; \
                     for(;;) switch(yy_gotostate) { case yygotostart: {
#define YYLABEL(lb) } case lb: {
#define YYENDGOTO } } 
#define YYBEGINDECLARELABEL enum yy_labels {yygotostart
#define YYDECLARELABEL(lb) ,lb
#define YYENDDECLARELABEL  };
#else
/* macro to keep goto */
#define YYGOTO(lb) goto lb
#define YYBEGINGOTO 
#define YYLABEL(lb) lb:
#define YYENDGOTO
#define YYBEGINDECLARELABEL 
#define YYDECLARELABEL(lb)
#define YYENDDECLARELABEL 
#endif
/* LABEL DECLARATION */
YYBEGINDECLARELABEL
  YYDECLARELABEL(yynewstate)
  YYDECLARELABEL(yybackup)
/* YYDECLARELABEL(yyresume) */
  YYDECLARELABEL(yydefault)
  YYDECLARELABEL(yyreduce)
  YYDECLARELABEL(yyerrlab)   /* here on detecting error */
  YYDECLARELABEL(yyerrlab1)   /* here on error raised explicitly by an action */
  YYDECLARELABEL(yyerrdefault)  /* current state does not do anything special for the error token. */
  YYDECLARELABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */
  YYDECLARELABEL(yyerrhandle)  
YYENDDECLARELABEL
/* ALLOCA SIMULATION */
/* __HAVE_NO_ALLOCA */
#ifdef __HAVE_NO_ALLOCA
int __alloca_free_ptr(char *ptr,char *ref)
{if(ptr!=ref) free(ptr);
 return 0;}

#define __ALLOCA_alloca(size) malloc(size)
#define __ALLOCA_free(ptr,ref) __alloca_free_ptr((char *)ptr,(char *)ref)

#ifdef YY_CParser_LSP_NEEDED
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		    __ALLOCA_free(yyls,yylsa)+\
		   (num))
#else
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		   (num))
#endif
#else
#define __ALLOCA_return(num) return(num)
#define __ALLOCA_alloca(size) alloca(size)
#define __ALLOCA_free(ptr,ref) 
#endif

/* ENDALLOCA SIMULATION */

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_CParser_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        __ALLOCA_return(0)
#define YYABORT         __ALLOCA_return(1)
#define YYERROR         YYGOTO(yyerrlab1)
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          YYGOTO(yyerrlab)
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_CParser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_CParser_CHAR = (token), YY_CParser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_CParser_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_CParser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_CParser_PURE
/* UNPURE */
#define YYLEX           YY_CParser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_CParser_CHAR;                      /*  the lookahead symbol        */
YY_CParser_STYPE      YY_CParser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_CParser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_CParser_LSP_NEEDED
YY_CParser_LTYPE YY_CParser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_CParser_LSP_NEEDED
#define YYLEX           YY_CParser_LEX(&YY_CParser_LVAL, &YY_CParser_LLOC)
#else
#define YYLEX           YY_CParser_LEX(&YY_CParser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_CParser_DEBUG != 0
int YY_CParser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_CParser_CLASS::
#endif
     YY_CParser_PARSE(YY_CParser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_CParser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_CParser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_CParser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_CParser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_CParser_LSP_NEEDED
  YY_CParser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_CParser_LTYPE *yyls = yylsa;
  YY_CParser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_CParser_PURE
  int YY_CParser_CHAR;
  YY_CParser_STYPE YY_CParser_LVAL;
  int YY_CParser_NERRS;
#ifdef YY_CParser_LSP_NEEDED
  YY_CParser_LTYPE YY_CParser_LLOC;
#endif
#endif

  YY_CParser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_CParser_DEBUG != 0
  if (YY_CParser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_CParser_NERRS = 0;
  YY_CParser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_CParser_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
YYLABEL(yynewstate)

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_CParser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_CParser_LSP_NEEDED
      YY_CParser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_CParser_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_CParser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_CParser_ERROR("parser stack overflow");
	  __ALLOCA_return(2);
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) __ALLOCA_alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      __ALLOCA_free(yyss1,yyssa);
      yyvs = (YY_CParser_STYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
      __ALLOCA_free(yyvs1,yyvsa);
#ifdef YY_CParser_LSP_NEEDED
      yyls = (YY_CParser_LTYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
      __ALLOCA_free(yyls1,yylsa);
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_CParser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_CParser_DEBUG != 0
      if (YY_CParser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_CParser_DEBUG != 0
  if (YY_CParser_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  YYGOTO(yybackup);
YYLABEL(yybackup)

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* YYLABEL(yyresume) */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yydefault);

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_CParser_CHAR == YYEMPTY)
    {
#if YY_CParser_DEBUG != 0
      if (YY_CParser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_CParser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_CParser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_CParser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_CParser_DEBUG != 0
      if (YY_CParser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_CParser_CHAR);

#if YY_CParser_DEBUG != 0
      if (YY_CParser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_CParser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_CParser_CHAR, YY_CParser_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    YYGOTO(yydefault);

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrlab);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrlab);

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_CParser_DEBUG != 0
  if (YY_CParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_CParser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_CParser_CHAR != YYEOF)
    YY_CParser_CHAR = YYEMPTY;

  *++yyvsp = YY_CParser_LVAL;
#ifdef YY_CParser_LSP_NEEDED
  *++yylsp = YY_CParser_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  YYGOTO(yynewstate);

/* Do the default action for the current state.  */
YYLABEL(yydefault)

  yyn = yydefact[yystate];
  if (yyn == 0)
    YYGOTO(yyerrlab);

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
YYLABEL(yyreduce)
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_CParser_DEBUG != 0
  if (YY_CParser_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 812 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 1885 "CParser.cc"

  switch (yyn) {

case 1:
#line 102 "CParser.y"
{
			yyval.node = CN("primary_expression",1,CN(yylsp[0]));
		;
    break;}
case 2:
#line 106 "CParser.y"
{
			yyval.node = CN("primary_expression",1,CN(yylsp[0]));
		;
    break;}
case 3:
#line 110 "CParser.y"
{
			yyval.node = CN("primary_expression",1,CN(yylsp[0]));
		;
    break;}
case 4:
#line 114 "CParser.y"
{
			yyval.node = CN("primary_expression",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 5:
#line 121 "CParser.y"
{
			yyval.node = CN("postfix_expression",1,yyvsp[0].node);
		;
    break;}
case 6:
#line 125 "CParser.y"
{
			yyval.node = CN("postfix_expression",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 7:
#line 129 "CParser.y"
{
			yyval.node = CN("postfix_expression",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 8:
#line 133 "CParser.y"
{
			yyval.node = CN("postfix_expression",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 9:
#line 137 "CParser.y"
{
			yyval.node = CN("postfix_expression",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 10:
#line 141 "CParser.y"
{
			yyval.node = CN("postfix_expression",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 11:
#line 145 "CParser.y"
{
			yyval.node = CN("postfix_expression",2,yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 12:
#line 149 "CParser.y"
{
			yyval.node = CN("postfix_expression",2,yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 13:
#line 153 "CParser.y"
{
			yyval.node = CN("postfix_expression",6,CN(yylsp[-5]),yyvsp[-4].node,CN(yylsp[-3]),CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 14:
#line 157 "CParser.y"
{
			yyval.node = CN("postfix_expression",7,CN(yylsp[-6]),yyvsp[-5].node,CN(yylsp[-4]),CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 15:
#line 164 "CParser.y"
{
			yyval.node = CN("argument_expression_list",1,yyvsp[0].node);
		;
    break;}
case 16:
#line 168 "CParser.y"
{
			yyval.node = CN("argument_expression_list",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 17:
#line 175 "CParser.y"
{
			yyval.node = CN("unary_expression",1,yyvsp[0].node);
		;
    break;}
case 18:
#line 179 "CParser.y"
{
			yyval.node = CN("unary_expression",2,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 19:
#line 183 "CParser.y"
{
			yyval.node = CN("unary_expression",2,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 20:
#line 187 "CParser.y"
{
			yyval.node = CN("unary_expression",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 21:
#line 191 "CParser.y"
{
			yyval.node = CN("unary_expression",2,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 22:
#line 195 "CParser.y"
{
			yyval.node = CN("unary_expression",4,CN(yylsp[-3]),CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 23:
#line 202 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 24:
#line 204 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 25:
#line 206 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 26:
#line 208 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 27:
#line 210 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 28:
#line 212 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 29:
#line 216 "CParser.y"
{
			yyval.node = CN("cast_expression",1,yyvsp[0].node);
		;
    break;}
case 30:
#line 220 "CParser.y"
{
			yyval.node = CN("cast_expression",4,CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 31:
#line 227 "CParser.y"
{
			yyval.node = CN("multiplicative_expression",1,yyvsp[0].node);
		;
    break;}
case 32:
#line 231 "CParser.y"
{
			yyval.node = CN("multiplicative_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 33:
#line 235 "CParser.y"
{
			yyval.node = CN("multiplicative_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 34:
#line 239 "CParser.y"
{
			yyval.node = CN("multiplicative_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 35:
#line 246 "CParser.y"
{
			yyval.node = CN("additive_expression",1,yyvsp[0].node);
		;
    break;}
case 36:
#line 250 "CParser.y"
{
			yyval.node = CN("additive_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 37:
#line 254 "CParser.y"
{
			yyval.node = CN("additive_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 38:
#line 261 "CParser.y"
{
			yyval.node = CN("shift_expression",1,yyvsp[0].node);
		;
    break;}
case 39:
#line 265 "CParser.y"
{
			yyval.node = CN("shift_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 40:
#line 269 "CParser.y"
{
			yyval.node = CN("shift_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 41:
#line 276 "CParser.y"
{
			yyval.node = CN("relational_expression",1,yyvsp[0].node);
		;
    break;}
case 42:
#line 280 "CParser.y"
{
			yyval.node = CN("relational_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 43:
#line 284 "CParser.y"
{
			yyval.node = CN("relational_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 44:
#line 288 "CParser.y"
{
			yyval.node = CN("relational_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 45:
#line 292 "CParser.y"
{
			yyval.node = CN("relational_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 46:
#line 299 "CParser.y"
{
			yyval.node = CN("equality_expression",1,yyvsp[0].node);
		;
    break;}
case 47:
#line 303 "CParser.y"
{
			yyval.node = CN("equality_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 48:
#line 307 "CParser.y"
{
			yyval.node = CN("equality_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 49:
#line 314 "CParser.y"
{
			yyval.node = CN("and_expression",1,yyvsp[0].node);
		;
    break;}
case 50:
#line 318 "CParser.y"
{
			yyval.node = CN("and_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 51:
#line 325 "CParser.y"
{
			yyval.node = CN("exclusive_or_expression",1,yyvsp[0].node);
		;
    break;}
case 52:
#line 329 "CParser.y"
{
			yyval.node = CN("exclusive_or_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 53:
#line 336 "CParser.y"
{
			yyval.node = CN("inclusive_or_expression",1,yyvsp[0].node);
		;
    break;}
case 54:
#line 340 "CParser.y"
{
			yyval.node = CN("inclusive_or_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 55:
#line 347 "CParser.y"
{
			yyval.node = CN("logical_and_expression",1,yyvsp[0].node);
		;
    break;}
case 56:
#line 351 "CParser.y"
{
			yyval.node = CN("logical_and_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 57:
#line 358 "CParser.y"
{
			yyval.node = CN("logical_or_expression",1,yyvsp[0].node);
		;
    break;}
case 58:
#line 362 "CParser.y"
{
			yyval.node = CN("logical_or_expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 59:
#line 369 "CParser.y"
{
			yyval.node = CN("conditional_expression",1,yyvsp[0].node);
		;
    break;}
case 60:
#line 373 "CParser.y"
{
			yyval.node = CN("conditional_expression",5,yyvsp[-4].node,CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 61:
#line 380 "CParser.y"
{
			yyval.node = CN("assignment_expression",1,yyvsp[0].node);
		;
    break;}
case 62:
#line 384 "CParser.y"
{
			yyval.node = CN("assignment_expression",3,yyvsp[-2].node,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 63:
#line 391 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 64:
#line 393 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 65:
#line 395 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 66:
#line 397 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 67:
#line 399 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 68:
#line 401 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 69:
#line 403 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 70:
#line 405 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 71:
#line 407 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 72:
#line 409 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 73:
#line 411 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 74:
#line 416 "CParser.y"
{
			yyval.node = CN("expression",1,yyvsp[0].node);
		;
    break;}
case 75:
#line 420 "CParser.y"
{
			yyval.node = CN("expression",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 76:
#line 427 "CParser.y"
{
			yyval.node = CN("constant_expression",1,yyvsp[0].node);
		;
    break;}
case 77:
#line 434 "CParser.y"
{
			yyval.node = CN("declaration",2,yyvsp[-1].node,CN(yylsp[0]));
			//cout << endl << "declaration" << $$->ToCode() << endl;
			// Parser Action
			ParsedDeclaration(yyval.node);
		;
    break;}
case 78:
#line 441 "CParser.y"
{
			yyval.node = CN("declaration",3,yyvsp[-2].node,yyvsp[-1].node,CN(yylsp[0]));
			//cout << endl << "declaration:" << $$->ToCode() << endl;
			// find all declarator and convert, if it is typedef.
			//FindTPYEDEFDeclaration($$);
			//cout << "not implement" << endl;
			// Parser Action
			ParsedDeclaration(yyval.node);
		;
    break;}
case 79:
#line 454 "CParser.y"
{ yyval.node = CN("declaration_specifiers",1,yyvsp[0].node); ;
    break;}
case 80:
#line 456 "CParser.y"
{ yyval.node = CN("declaration_specifiers",2,yyvsp[-1].node,yyvsp[0].node); ;
    break;}
case 81:
#line 458 "CParser.y"
{
			yyval.node = CN("declaration_specifiers",1,yyvsp[0].node);
		;
    break;}
case 82:
#line 462 "CParser.y"
{
			yyval.node = CN("declaration_specifiers",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 83:
#line 466 "CParser.y"
{
			yyval.node = CN("declaration_specifiers",1,yyvsp[0].node);
		;
    break;}
case 84:
#line 470 "CParser.y"
{
			yyval.node = CN("declaration_specifiers",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 85:
#line 474 "CParser.y"
{
			yyval.node = CN("declaration_specifiers",1,yyvsp[0].node);
		;
    break;}
case 86:
#line 478 "CParser.y"
{
			yyval.node = CN("declaration_specifiers",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 87:
#line 485 "CParser.y"
{
			yyval.node = CN("init_declarator_list",1,yyvsp[0].node);
		;
    break;}
case 88:
#line 489 "CParser.y"
{
			// method 1
			yyval.node = CN("init_declarator_list",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
			// method 2. It will reduce the deepth of the AST.
			//$1->AddChildNode(2, CN(@2), $3);
			//$$ = $1;
		;
    break;}
case 89:
#line 500 "CParser.y"
{
			yyval.node = CN("init_declarator",1,yyvsp[0].node);
		;
    break;}
case 90:
#line 504 "CParser.y"
{
			yyval.node = CN("init_declarator",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 91:
#line 511 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 92:
#line 513 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 93:
#line 515 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 94:
#line 517 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 95:
#line 519 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 96:
#line 524 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 97:
#line 526 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 98:
#line 528 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 99:
#line 530 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 100:
#line 532 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 101:
#line 534 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 102:
#line 536 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 103:
#line 538 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 104:
#line 540 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 105:
#line 542 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 106:
#line 544 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 107:
#line 546 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 108:
#line 548 "CParser.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 109:
#line 550 "CParser.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 110:
#line 552 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 111:
#line 557 "CParser.y"
{
			yyval.node = CN("struct_or_union_specifier",5,yyvsp[-4].node,CN(yylsp[-3]),CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 112:
#line 561 "CParser.y"
{
			yyval.node = CN("struct_or_union_specifier",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 113:
#line 565 "CParser.y"
{
			yyval.node = CN("struct_or_union_specifier",2,yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 114:
#line 572 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 115:
#line 574 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 116:
#line 579 "CParser.y"
{
			yyval.node = CN("struct_declaration_list",1,yyvsp[0].node);
		;
    break;}
case 117:
#line 583 "CParser.y"
{
			yyval.node = CN("struct_declaration_list",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 118:
#line 590 "CParser.y"
{
			yyval.node = CN("struct_declaration",3,yyvsp[-2].node,yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 119:
#line 597 "CParser.y"
{
			yyval.node = CN("specifier_qualifier_list",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 120:
#line 601 "CParser.y"
{
			yyval.node = CN("specifier_qualifier_list",1,yyvsp[0].node);
		;
    break;}
case 121:
#line 605 "CParser.y"
{
			yyval.node = CN("specifier_qualifier_list",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 122:
#line 609 "CParser.y"
{
			yyval.node = CN("specifier_qualifier_list",1,yyvsp[0].node);
		;
    break;}
case 123:
#line 616 "CParser.y"
{
			yyval.node = CN("struct_declarator_list",1,yyvsp[0].node);
		;
    break;}
case 124:
#line 620 "CParser.y"
{
			yyval.node = CN("struct_declarator_list",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 125:
#line 627 "CParser.y"
{
			yyval.node = CN("struct_declarator",1,yyvsp[0].node);
		;
    break;}
case 126:
#line 631 "CParser.y"
{
			yyval.node = CN("struct_declarator",2,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 127:
#line 635 "CParser.y"
{
			yyval.node = CN("struct_declarator",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 128:
#line 642 "CParser.y"
{
			yyval.node = CN("enum_specifier",4,CN(yylsp[-3]),CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 129:
#line 646 "CParser.y"
{
			yyval.node = CN("enum_specifier",5,CN(yylsp[-4]),CN(yylsp[-3]),CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 130:
#line 650 "CParser.y"
{
			yyval.node = CN("enum_specifier",5,CN(yylsp[-4]),CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 131:
#line 654 "CParser.y"
{
			yyval.node = CN("enum_specifier",6,CN(yylsp[-5]),CN(yylsp[-4]),CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 132:
#line 658 "CParser.y"
{
			yyval.node = CN("enum_specifier",2,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 133:
#line 665 "CParser.y"
{
			yyval.node = CN("enumerator_list",1,yyvsp[0].node);
		;
    break;}
case 134:
#line 669 "CParser.y"
{
			yyval.node = CN("enumerator_list",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 135:
#line 676 "CParser.y"
{
			yyval.node = CN("enumerator",1,CN(yylsp[0]));
		;
    break;}
case 136:
#line 680 "CParser.y"
{
			yyval.node = CN("enumerator",3,CN(yylsp[-2]),CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 137:
#line 687 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 138:
#line 689 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 139:
#line 691 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 140:
#line 696 "CParser.y"
{ yyval.node = CN(yylsp[0]); ;
    break;}
case 141:
#line 701 "CParser.y"
{
			yyval.node = CN("declarator",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 142:
#line 705 "CParser.y"
{
			//cout << "direct_declarator" << @1.theText << endl;
			yyval.node = CN("declarator",1,yyvsp[0].node);
		;
    break;}
case 143:
#line 714 "CParser.y"
{
			yyval.node = CN("direct_declarator",1,CN(yylsp[0]));
		;
    break;}
case 144:
#line 718 "CParser.y"
{
			yyval.node = CN("direct_declarator",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 145:
#line 722 "CParser.y"
{
			yyval.node = CN("direct_declarator",5,yyvsp[-4].node,CN(yylsp[-3]),yyvsp[-2].node,yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 146:
#line 726 "CParser.y"
{
			yyval.node = CN("direct_declarator",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 147:
#line 730 "CParser.y"
{
			yyval.node = CN("direct_declarator",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 148:
#line 734 "CParser.y"
{
			yyval.node = CN("direct_declarator",6,yyvsp[-5].node,CN(yylsp[-4]),CN(yylsp[-3]),yyvsp[-2].node,yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 149:
#line 738 "CParser.y"
{
			yyval.node = CN("direct_declarator",6,yyvsp[-5].node,CN(yylsp[-4]),yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 150:
#line 742 "CParser.y"
{
			yyval.node = CN("direct_declarator",5,yyvsp[-4].node,CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 151:
#line 746 "CParser.y"
{
			yyval.node = CN("direct_declarator",4,yyvsp[-3].node,CN(yylsp[-2]),CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 152:
#line 750 "CParser.y"
{
			yyval.node = CN("direct_declarator",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 153:
#line 754 "CParser.y"
{
			yyval.node = CN("direct_declarator",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 154:
#line 758 "CParser.y"
{
			yyval.node = CN("direct_declarator",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 155:
#line 762 "CParser.y"
{
			yyval.node = CN("direct_declarator",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0])); 
		;
    break;}
case 156:
#line 769 "CParser.y"
{
			yyval.node = CN("pointer",1,CN(yylsp[0]));
		;
    break;}
case 157:
#line 773 "CParser.y"
{
			yyval.node = CN("pointer",2,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 158:
#line 777 "CParser.y"
{
			yyval.node = CN("pointer",2,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 159:
#line 781 "CParser.y"
{
			yyval.node = CN("pointer",3,CN(yylsp[-2]),yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 160:
#line 788 "CParser.y"
{
			yyval.node = CN("type_qualifier_list",1,yyvsp[0].node);
		;
    break;}
case 161:
#line 792 "CParser.y"
{
			yyval.node = CN("type_qualifier_list",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 162:
#line 800 "CParser.y"
{
			yyval.node = CN("parameter_type_list",1,yyvsp[0].node);
		;
    break;}
case 163:
#line 804 "CParser.y"
{
			yyval.node = CN("parameter_type_list",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 164:
#line 811 "CParser.y"
{
			yyval.node = CN("parameter_list",1,yyvsp[0].node);
		;
    break;}
case 165:
#line 815 "CParser.y"
{
			yyval.node = CN("parameter_list",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 166:
#line 822 "CParser.y"
{
			yyval.node = CN("parameter_declaration",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 167:
#line 826 "CParser.y"
{
			yyval.node = CN("parameter_declaration",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 168:
#line 830 "CParser.y"
{
			yyval.node = CN("parameter_declaration",1,yyvsp[0].node);
		;
    break;}
case 169:
#line 837 "CParser.y"
{
			yyval.node = CN("identifier_list",1,CN(yylsp[0]));
		;
    break;}
case 170:
#line 841 "CParser.y"
{
			yyval.node = CN("identifier_list",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 171:
#line 848 "CParser.y"
{
			yyval.node = CN("type_name",1,yyvsp[0].node);
		;
    break;}
case 172:
#line 852 "CParser.y"
{
			yyval.node = CN("type_name",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 173:
#line 859 "CParser.y"
{
			yyval.node = CN("abstract_declarator",1,yyvsp[0].node);
		;
    break;}
case 174:
#line 863 "CParser.y"
{
			yyval.node = CN("abstract_declarator",1,yyvsp[0].node);
		;
    break;}
case 175:
#line 867 "CParser.y"
{
			yyval.node = CN("abstract_declarator",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 176:
#line 874 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 177:
#line 878 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",2,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 178:
#line 882 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 179:
#line 886 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 180:
#line 890 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 181:
#line 894 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",3,CN(yylsp[-2]),CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 182:
#line 898 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",4,yyvsp[-3].node,CN(yylsp[-2]),CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 183:
#line 902 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",2,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 184:
#line 906 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 185:
#line 910 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",3,yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 186:
#line 914 "CParser.y"
{
			yyval.node = CN("direct_abstract_declarator",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 187:
#line 921 "CParser.y"
{
			yyval.node = CN("initializer",1,yyvsp[0].node);
		;
    break;}
case 188:
#line 925 "CParser.y"
{
			yyval.node = CN("initializer",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 189:
#line 929 "CParser.y"
{
			yyval.node = CN("initializer",4,CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 190:
#line 936 "CParser.y"
{
			yyval.node = CN("initializer_list",1,yyvsp[0].node);
		;
    break;}
case 191:
#line 940 "CParser.y"
{
			yyval.node = CN("initializer_list",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 192:
#line 944 "CParser.y"
{
			yyval.node = CN("initializer_list",3,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 193:
#line 948 "CParser.y"
{
			yyval.node = CN("initializer_list",4,yyvsp[-3].node,CN(yylsp[-2]),yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 194:
#line 955 "CParser.y"
{
			yyval.node = CN("designation",2,yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 195:
#line 962 "CParser.y"
{
			yyval.node = CN("designator_list",1,yyvsp[0].node);
		;
    break;}
case 196:
#line 966 "CParser.y"
{
			yyval.node = CN("designator_list",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
case 197:
#line 973 "CParser.y"
{
			yyval.node = CN("designator",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 198:
#line 977 "CParser.y"
{
			yyval.node = CN("designator",2,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 199:
#line 984 "CParser.y"
{
			yyval.node = CN("statement",1,yyvsp[0].node);
		;
    break;}
case 200:
#line 988 "CParser.y"
{
			yyval.node = CN("statement",1,yyvsp[0].node);
		;
    break;}
case 201:
#line 992 "CParser.y"
{
			yyval.node = CN("statement",1,yyvsp[0].node);
		;
    break;}
case 202:
#line 996 "CParser.y"
{
			yyval.node = CN("statement",1,yyvsp[0].node);
		;
    break;}
case 203:
#line 1000 "CParser.y"
{
			yyval.node = CN("statement",1,yyvsp[0].node);
		;
    break;}
case 204:
#line 1004 "CParser.y"
{
			yyval.node = CN("statement",1,yyvsp[0].node);
		;
    break;}
case 205:
#line 1011 "CParser.y"
{
			yyval.node = CN("labeled_statement",3,CN(yylsp[-2]),CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 206:
#line 1015 "CParser.y"
{
			yyval.node = CN("labeled_statement",4,CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 207:
#line 1019 "CParser.y"
{
			yyval.node = CN("labeled_statement",3,CN(yylsp[-2]),CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 208:
#line 1026 "CParser.y"
{
			yyval.node = CN("compound_statement",2,CN(yylsp[-1]),CN(yylsp[0])); 
		;
    break;}
case 209:
#line 1030 "CParser.y"
{
			yyval.node = CN("compound_statement",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0])); 
		;
    break;}
case 210:
#line 1037 "CParser.y"
{
			yyval.node = CN("block_item_list",1,yyvsp[0].node); 
		;
    break;}
case 211:
#line 1041 "CParser.y"
{
			//$$ = CN("block_item_list",2,$1,$2); 
			yyval.node = yyvsp[-1].node;
			yyvsp[-1].node->AddChildNode(yyvsp[0].node);
		;
    break;}
case 212:
#line 1050 "CParser.y"
{
			//$$ = CN("block_item",1,$1); 
			yyval.node = yyvsp[0].node;
		;
    break;}
case 213:
#line 1055 "CParser.y"
{
			//$$ = CN("block_item",1,$1);
			yyval.node = yyvsp[0].node;
		;
    break;}
case 214:
#line 1063 "CParser.y"
{
			yyval.node = CN("expression_statement",1,CN(yylsp[0]));
		;
    break;}
case 215:
#line 1067 "CParser.y"
{
			yyval.node = CN("expression_statement",2,yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 216:
#line 1074 "CParser.y"
{
			yyval.node = CN("selection_statement",5,CN(yylsp[-4]),CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 217:
#line 1078 "CParser.y"
{
			yyval.node = CN("selection_statement",7,CN(yylsp[-6]),CN(yylsp[-5]),yyvsp[-4].node,CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 218:
#line 1082 "CParser.y"
{
			yyval.node = CN("selection_statement",5,CN(yylsp[-4]),CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 219:
#line 1089 "CParser.y"
{
			yyval.node = CN("iteration_statement",5,CN(yylsp[-4]),CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 220:
#line 1093 "CParser.y"
{
			yyval.node = CN("iteration_statement",7,CN(yylsp[-6]),yyvsp[-5].node,CN(yylsp[-4]),CN(yylsp[-3]),yyvsp[-2].node,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 221:
#line 1097 "CParser.y"
{
			yyval.node = CN("iteration_statement",6,CN(yylsp[-5]),CN(yylsp[-4]),yyvsp[-3].node,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 222:
#line 1101 "CParser.y"
{
			yyval.node = CN("iteration_statement",7,CN(yylsp[-6]),CN(yylsp[-5]),yyvsp[-4].node,yyvsp[-3].node,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 223:
#line 1105 "CParser.y"
{
			yyval.node = CN("iteration_statement",6,CN(yylsp[-5]),CN(yylsp[-4]),yyvsp[-3].node,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 224:
#line 1109 "CParser.y"
{
			yyval.node = CN("iteration_statement",7,CN(yylsp[-6]),CN(yylsp[-5]),yyvsp[-4].node,yyvsp[-3].node,yyvsp[-2].node,CN(yylsp[-1]),yyvsp[0].node);
		;
    break;}
case 225:
#line 1116 "CParser.y"
{
			yyval.node = CN("jump_statement",3,CN(yylsp[-2]),CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 226:
#line 1120 "CParser.y"
{
			yyval.node = CN("jump_statement",2,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 227:
#line 1124 "CParser.y"
{
			yyval.node = CN("jump_statement",2,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 228:
#line 1128 "CParser.y"
{
			yyval.node = CN("jump_statement",2,CN(yylsp[-1]),CN(yylsp[0]));
		;
    break;}
case 229:
#line 1132 "CParser.y"
{
			yyval.node = CN("jump_statement",3,CN(yylsp[-2]),yyvsp[-1].node,CN(yylsp[0]));
		;
    break;}
case 230:
#line 1139 "CParser.y"
{
			yyval.node = CN("translation_unit",1,yyvsp[0].node);
			setCurrentTree((Tree *)yyval.node);
		;
    break;}
case 231:
#line 1144 "CParser.y"
{
			yyval.node = CN("translation_unit",2,yyvsp[-1].node,yyvsp[0].node);
			setCurrentTree((Tree *)yyval.node);
		;
    break;}
case 232:
#line 1152 "CParser.y"
{
			yyval.node = CN("external_declaration",1,yyvsp[0].node);
		;
    break;}
case 233:
#line 1156 "CParser.y"
{
			yyval.node = CN("external_declaration",1,yyvsp[0].node);
		;
    break;}
case 234:
#line 1160 "CParser.y"
{
			yyval.node = CN("external_declaration",1,CN(yylsp[0])); 
		;
    break;}
case 235:
#line 1167 "CParser.y"
{
			yyval.node = CN("function_definition",4,yyvsp[-3].node,yyvsp[-2].node,yyvsp[-1].node,yyvsp[0].node);
			// Parser Action
			ParsedFunctionDefinition(yyval.node, yyvsp[-2].node);
		;
    break;}
case 236:
#line 1173 "CParser.y"
{
			yyval.node = CN("function_definition",3,yyvsp[-2].node,yyvsp[-1].node,yyvsp[0].node);
			// Parser Action
			ParsedFunctionDefinition(yyval.node, yyvsp[-1].node);
		;
    break;}
case 237:
#line 1182 "CParser.y"
{
			yyval.node = CN("declaration_list",1,yyvsp[0].node);
		;
    break;}
case 238:
#line 1186 "CParser.y"
{
			yyval.node = CN("declaration_list",2,yyvsp[-1].node,yyvsp[0].node);
		;
    break;}
}

#line 812 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_CParser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_CParser_DEBUG != 0
  if (YY_CParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_CParser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_CParser_LLOC.first_line;
      yylsp->first_column = YY_CParser_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  YYGOTO(yynewstate);

YYLABEL(yyerrlab)   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_CParser_NERRS;

#ifdef YY_CParser_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_CParser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_CParser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_CParser_ERROR_VERBOSE */
	YY_CParser_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_CParser_CHAR == YYEOF)
	YYABORT;

#if YY_CParser_DEBUG != 0
      if (YY_CParser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_CParser_CHAR, yytname[yychar1]);
#endif

      YY_CParser_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  YYGOTO(yyerrhandle);

YYLABEL(yyerrdefault)  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) YYGOTO(yydefault);
#endif

YYLABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_CParser_LSP_NEEDED
  yylsp--;
#endif

#if YY_CParser_DEBUG != 0
  if (YY_CParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

YYLABEL(yyerrhandle)

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yyerrdefault);

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    YYGOTO(yyerrdefault);

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrpop);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrpop);

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_CParser_DEBUG != 0
  if (YY_CParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_CParser_LVAL;
#ifdef YY_CParser_LSP_NEEDED
  *++yylsp = YY_CParser_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 1011 "C:\\Users\\L.Falcon\\Desktop\\源代码\\obfusc\\flex_bison\\bison.cc" */
#line 3455 "CParser.cc"
#line 1191 "CParser.y"

