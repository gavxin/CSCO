%name CParser


%header{
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
%}

%union {
	Node * node;
}

%header{
typedef YY_CParser_STYPE TokenValue;
#include "TokenTypes.h"
// 4quick

#define CN new Node

%}

%define LSP_NEEDED
%define LTYPE TokenLocation
%define LLOC theTokenLocation
%define LVAL theTokenValue

%define DEBUG 1
%define LEX_BODY =0
%define ERROR_BODY =0
%define ERROR PrintError
%define DEBUG_FLAG debugFlag

%define LEX Scan
%define PARSE Parse 
%define PARSE_PARAM 

%define MEMBERS \
	public: 	\
		virtual Tree * getCurrentTree(void) {return NULL;}; \
		virtual void setCurrentTree(Tree *value){}; \
		virtual SymbolTable * getCurrentSymbolTable(void){return NULL;}; \
		virtual void ParsedDeclaration(Node *){}; \
		virtual void FindTPYEDEFDeclaration(Node *){}; \
		virtual void ParsedFunctionDefinition(Node *functionNode, Node *declaratorNode){};
%define CONSTRUCTOR_PARAM 
%define CONSTRUCTOR_INIT 
%define CONSTRUCTOR_CODE \
	;
%define ENUM_TOKEN EnumToken


%token IDENTIFIER
%token CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <node> primary_expression
%type <node> postfix_expression argument_expression_list unary_expression
%type <node> unary_operator cast_expression multiplicative_expression additive_expression
%type <node> shift_expression relational_expression equality_expression and_expression
%type <node> exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <node> conditional_expression assignment_expression assignment_operator expression
%type <node> constant_expression declaration declaration_specifiers init_declarator_list
%type <node> init_declarator storage_class_specifier type_specifier struct_or_union_specifier
%type <node> struct_or_union struct_declaration_list struct_declaration specifier_qualifier_list
%type <node> struct_declarator_list struct_declarator enum_specifier enumerator_list
%type <node> enumerator type_qualifier function_specifier declarator
%type <node> direct_declarator pointer type_qualifier_list parameter_type_list
%type <node> parameter_list parameter_declaration identifier_list type_name
%type <node> abstract_declarator direct_abstract_declarator initializer initializer_list
%type <node> designation designator_list designator statement
%type <node> labeled_statement compound_statement block_item_list block_item
%type <node> expression_statement selection_statement iteration_statement jump_statement
%type <node> translation_unit external_declaration function_definition declaration_list

%start translation_unit
%%

primary_expression
	: IDENTIFIER	
		{
			$$ = CN("primary_expression",1,CN(@1));
		}
	| CONSTANT
		{
			$$ = CN("primary_expression",1,CN(@1));
		}
	| STRING_LITERAL
		{
			$$ = CN("primary_expression",1,CN(@1));
		}
	| '(' expression ')'
		{
			$$ = CN("primary_expression",3,CN(@1),$2,CN(@3));
		}
	;

postfix_expression
	: primary_expression
		{
			$$ = CN("postfix_expression",1,$1);
		}
	| postfix_expression '[' expression ']'
		{
			$$ = CN("postfix_expression",4,$1,CN(@2),$3,CN(@4));
		}
	| postfix_expression '(' ')'
		{
			$$ = CN("postfix_expression",3,$1,CN(@2),CN(@3));
		}
	| postfix_expression '(' argument_expression_list ')'
		{
			$$ = CN("postfix_expression",4,$1,CN(@2),$3,CN(@4));
		}
	| postfix_expression '.' IDENTIFIER
		{
			$$ = CN("postfix_expression",3,$1,CN(@2),CN(@3));
		}
	| postfix_expression PTR_OP IDENTIFIER
		{
			$$ = CN("postfix_expression",3,$1,CN(@2),CN(@3));
		}
	| postfix_expression INC_OP
		{
			$$ = CN("postfix_expression",2,$1,CN(@2));
		}
	| postfix_expression DEC_OP
		{
			$$ = CN("postfix_expression",2,$1,CN(@2));
		}
	| '(' type_name ')' '{' initializer_list '}'
		{
			$$ = CN("postfix_expression",6,CN(@1),$2,CN(@3),CN(@4),$5,CN(@6));
		}
	| '(' type_name ')' '{' initializer_list ',' '}'
		{
			$$ = CN("postfix_expression",7,CN(@1),$2,CN(@3),CN(@4),$5,CN(@6),CN(@7));
		}
	;

argument_expression_list
	: assignment_expression
		{
			$$ = CN("argument_expression_list",1,$1);
		}
	| argument_expression_list ',' assignment_expression
		{
			$$ = CN("argument_expression_list",3,$1,CN(@2),$3);
		}
	;

unary_expression
	: postfix_expression
		{
			$$ = CN("unary_expression",1,$1);
		}
	| INC_OP unary_expression
		{
			$$ = CN("unary_expression",2,CN(@1),$2);
		}
	| DEC_OP unary_expression
		{
			$$ = CN("unary_expression",2,CN(@1),$2);
		}
	| unary_operator cast_expression
		{
			$$ = CN("unary_expression",2,$1,$2);
		}
	| SIZEOF unary_expression
		{
			$$ = CN("unary_expression",2,CN(@1),$2);
		}
	| SIZEOF '(' type_name ')'
		{
			$$ = CN("unary_expression",4,CN(@1),CN(@2),$3,CN(@4));
		}
	;

unary_operator
	: '&'
		{ $$ = CN(@1); }
	| '*'
		{ $$ = CN(@1); }
	| '+'
		{ $$ = CN(@1); }
	| '-'
		{ $$ = CN(@1); }
	| '~'
		{ $$ = CN(@1); }
	| '!'
		{ $$ = CN(@1); }
	;
cast_expression
	: unary_expression
		{
			$$ = CN("cast_expression",1,$1);
		}
	| '(' type_name ')' cast_expression
		{
			$$ = CN("cast_expression",4,CN(@1),$2,CN(@3),$4);
		}
	;

multiplicative_expression
	: cast_expression
		{
			$$ = CN("multiplicative_expression",1,$1);
		}
	| multiplicative_expression '*' cast_expression
		{
			$$ = CN("multiplicative_expression",3,$1,CN(@2),$3);
		}
	| multiplicative_expression '/' cast_expression
		{
			$$ = CN("multiplicative_expression",3,$1,CN(@2),$3);
		}
	| multiplicative_expression '%' cast_expression
		{
			$$ = CN("multiplicative_expression",3,$1,CN(@2),$3);
		}
	;

additive_expression
	: multiplicative_expression
		{
			$$ = CN("additive_expression",1,$1);
		}
	| additive_expression '+' multiplicative_expression
		{
			$$ = CN("additive_expression",3,$1,CN(@2),$3);
		}
	| additive_expression '-' multiplicative_expression
		{
			$$ = CN("additive_expression",3,$1,CN(@2),$3);
		}
	;

shift_expression
	: additive_expression
		{
			$$ = CN("shift_expression",1,$1);
		}
	| shift_expression LEFT_OP additive_expression
		{
			$$ = CN("shift_expression",3,$1,CN(@2),$3);
		}
	| shift_expression RIGHT_OP additive_expression
		{
			$$ = CN("shift_expression",3,$1,CN(@2),$3);
		}
	;

relational_expression
	: shift_expression
		{
			$$ = CN("relational_expression",1,$1);
		}
	| relational_expression '<' shift_expression
		{
			$$ = CN("relational_expression",3,$1,CN(@2),$3);
		}
	| relational_expression '>' shift_expression
		{
			$$ = CN("relational_expression",3,$1,CN(@2),$3);
		}
	| relational_expression LE_OP shift_expression
		{
			$$ = CN("relational_expression",3,$1,CN(@2),$3);
		}
	| relational_expression GE_OP shift_expression
		{
			$$ = CN("relational_expression",3,$1,CN(@2),$3);
		}
	;

equality_expression
	: relational_expression
		{
			$$ = CN("equality_expression",1,$1);
		}
	| equality_expression EQ_OP relational_expression
		{
			$$ = CN("equality_expression",3,$1,CN(@2),$3);
		}
	| equality_expression NE_OP relational_expression
		{
			$$ = CN("equality_expression",3,$1,CN(@2),$3);
		}
	;

and_expression
	: equality_expression
		{
			$$ = CN("and_expression",1,$1);
		}
	| and_expression '&' equality_expression
		{
			$$ = CN("and_expression",3,$1,CN(@2),$3);
		}
	;

exclusive_or_expression
	: and_expression
		{
			$$ = CN("exclusive_or_expression",1,$1);
		}
	| exclusive_or_expression '^' and_expression
		{
			$$ = CN("exclusive_or_expression",3,$1,CN(@2),$3);
		}
	;

inclusive_or_expression
	: exclusive_or_expression
		{
			$$ = CN("inclusive_or_expression",1,$1);
		}
	| inclusive_or_expression '|' exclusive_or_expression
		{
			$$ = CN("inclusive_or_expression",3,$1,CN(@2),$3);
		}
	;

logical_and_expression
	: inclusive_or_expression
		{
			$$ = CN("logical_and_expression",1,$1);
		}
	| logical_and_expression AND_OP inclusive_or_expression
		{
			$$ = CN("logical_and_expression",3,$1,CN(@2),$3);
		}
	;

logical_or_expression
	: logical_and_expression
		{
			$$ = CN("logical_or_expression",1,$1);
		}
	| logical_or_expression OR_OP logical_and_expression
		{
			$$ = CN("logical_or_expression",3,$1,CN(@2),$3);
		}
	;

conditional_expression
	: logical_or_expression
		{
			$$ = CN("conditional_expression",1,$1);
		}
	| logical_or_expression '?' expression ':' conditional_expression
		{
			$$ = CN("conditional_expression",5,$1,CN(@2),$3,CN(@4),$5);
		}
	;

assignment_expression
	: conditional_expression
		{
			$$ = CN("assignment_expression",1,$1);
		}
	| unary_expression assignment_operator assignment_expression
		{
			$$ = CN("assignment_expression",3,$1,$2,$3);
		}
	;

assignment_operator
	: '='
		{ $$ = CN(@1); }
	| MUL_ASSIGN
		{ $$ = CN(@1); }
	| DIV_ASSIGN
		{ $$ = CN(@1); }
	| MOD_ASSIGN
		{ $$ = CN(@1); }
	| ADD_ASSIGN
		{ $$ = CN(@1); }
	| SUB_ASSIGN
		{ $$ = CN(@1); }
	| LEFT_ASSIGN
		{ $$ = CN(@1); }
	| RIGHT_ASSIGN
		{ $$ = CN(@1); }
	| AND_ASSIGN
		{ $$ = CN(@1); }
	| XOR_ASSIGN
		{ $$ = CN(@1); }
	| OR_ASSIGN
		{ $$ = CN(@1); }
	;

expression
	: assignment_expression
		{
			$$ = CN("expression",1,$1);
		}
	| expression ',' assignment_expression
		{
			$$ = CN("expression",3,$1,CN(@2),$3);
		}
	;

constant_expression
	: conditional_expression
		{
			$$ = CN("constant_expression",1,$1);
		}
	;

declaration
	: declaration_specifiers ';'
		{
			$$ = CN("declaration",2,$1,CN(@2));
			//cout << endl << "declaration" << $$->ToCode() << endl;
			// Parser Action
			ParsedDeclaration($$);
		}
	| declaration_specifiers init_declarator_list ';'
		{
			$$ = CN("declaration",3,$1,$2,CN(@3));
			//cout << endl << "declaration:" << $$->ToCode() << endl;
			// find all declarator and convert, if it is typedef.
			//FindTPYEDEFDeclaration($$);
			//cout << "not implement" << endl;
			// Parser Action
			ParsedDeclaration($$);
		}
	;

declaration_specifiers 
	: storage_class_specifier
		{ $$ = CN("declaration_specifiers",1,$1); }
	| storage_class_specifier declaration_specifiers
		{ $$ = CN("declaration_specifiers",2,$1,$2); }
	| type_specifier
		{
			$$ = CN("declaration_specifiers",1,$1);
		}
	| type_specifier declaration_specifiers
		{
			$$ = CN("declaration_specifiers",2,$1,$2);
		}
	| type_qualifier
		{
			$$ = CN("declaration_specifiers",1,$1);
		}
	| type_qualifier declaration_specifiers
		{
			$$ = CN("declaration_specifiers",2,$1,$2);
		}
	| function_specifier
		{
			$$ = CN("declaration_specifiers",1,$1);
		}
	| function_specifier declaration_specifiers
		{
			$$ = CN("declaration_specifiers",2,$1,$2);
		}
	;

init_declarator_list
	: init_declarator
		{
			$$ = CN("init_declarator_list",1,$1);
		}
	| init_declarator_list ',' init_declarator
		{
			// method 1
			$$ = CN("init_declarator_list",3,$1,CN(@2),$3);
			// method 2. It will reduce the deepth of the AST.
			//$1->AddChildNode(2, CN(@2), $3);
			//$$ = $1;
		}
	;

init_declarator
	: declarator
		{
			$$ = CN("init_declarator",1,$1);
		}
	| declarator '=' initializer
		{
			$$ = CN("init_declarator",3,$1,CN(@2),$3);
		}
	;

storage_class_specifier
	: TYPEDEF
		{ $$ = CN(@1); }
	| EXTERN
		{ $$ = CN(@1); }
	| STATIC
		{ $$ = CN(@1); }
	| AUTO
		{ $$ = CN(@1); }
	| REGISTER
		{ $$ = CN(@1); }
	;

type_specifier
	: VOID
		{ $$ = CN(@1); }
	| CHAR 
		{ $$ = CN(@1); }
	| SHORT
		{ $$ = CN(@1); }
	| INT
		{ $$ = CN(@1); }
	| LONG
		{ $$ = CN(@1); }
	| FLOAT
		{ $$ = CN(@1); }
	| DOUBLE
		{ $$ = CN(@1); }
	| SIGNED
		{ $$ = CN(@1); }
	| UNSIGNED
		{ $$ = CN(@1); }
	| BOOL
		{ $$ = CN(@1); }
	| COMPLEX
		{ $$ = CN(@1); }
	| IMAGINARY
		{ $$ = CN(@1); }
	| struct_or_union_specifier
		{ $$ = $1; }
	| enum_specifier
		{ $$ = $1; }
	| TYPE_NAME
		{ $$ = CN(@1); }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
		{
			$$ = CN("struct_or_union_specifier",5,$1,CN(@2),CN(@3),$4,CN(@5));
		}
	| struct_or_union '{' struct_declaration_list '}'
		{
			$$ = CN("struct_or_union_specifier",4,$1,CN(@2),$3,CN(@4));
		}
	| struct_or_union IDENTIFIER
		{
			$$ = CN("struct_or_union_specifier",2,$1,CN(@2));
		}
	;

struct_or_union
	: STRUCT
		{ $$ = CN(@1); }
	| UNION
		{ $$ = CN(@1); }
	;

struct_declaration_list
	: struct_declaration
		{
			$$ = CN("struct_declaration_list",1,$1);
		}
	| struct_declaration_list struct_declaration
		{
			$$ = CN("struct_declaration_list",2,$1,$2);
		}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
		{
			$$ = CN("struct_declaration",3,$1,$2,CN(@3));
		}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
		{
			$$ = CN("specifier_qualifier_list",2,$1,$2);
		}
	| type_specifier
		{
			$$ = CN("specifier_qualifier_list",1,$1);
		}
	| type_qualifier specifier_qualifier_list
		{
			$$ = CN("specifier_qualifier_list",2,$1,$2);
		}
	| type_qualifier
		{
			$$ = CN("specifier_qualifier_list",1,$1);
		}
	;

struct_declarator_list
	: struct_declarator
		{
			$$ = CN("struct_declarator_list",1,$1);
		}
	| struct_declarator_list ',' struct_declarator
		{
			$$ = CN("struct_declarator_list",3,$1,CN(@2),$3);
		}
	;

struct_declarator
	: declarator
		{
			$$ = CN("struct_declarator",1,$1);
		}
	| ':' constant_expression
		{
			$$ = CN("struct_declarator",2,CN(@1),$2);
		}
	| declarator ':' constant_expression
		{
			$$ = CN("struct_declarator",3,$1,CN(@2),$3);
		}
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
		{
			$$ = CN("enum_specifier",4,CN(@1),CN(@2),$3,CN(@4));
		}
	| ENUM IDENTIFIER '{' enumerator_list '}'
		{
			$$ = CN("enum_specifier",5,CN(@1),CN(@2),CN(@3),$4,CN(@5));
		}
	| ENUM '{' enumerator_list ',' '}'
		{
			$$ = CN("enum_specifier",5,CN(@1),CN(@2),$3,CN(@4),CN(@5));
		}
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
		{
			$$ = CN("enum_specifier",6,CN(@1),CN(@2),CN(@3),$4,CN(@5),CN(@6));
		}
	| ENUM IDENTIFIER
		{
			$$ = CN("enum_specifier",2,CN(@1),CN(@2));
		}
	;

enumerator_list
	: enumerator
		{
			$$ = CN("enumerator_list",1,$1);
		}
	| enumerator_list ',' enumerator
		{
			$$ = CN("enumerator_list",3,$1,CN(@2),$3);
		}
	;

enumerator
	: IDENTIFIER
		{
			$$ = CN("enumerator",1,CN(@1));
		}
	| IDENTIFIER '=' constant_expression
		{
			$$ = CN("enumerator",3,CN(@1),CN(@2),$3);
		}
	;

type_qualifier
	: CONST
		{ $$ = CN(@1); }
	| RESTRICT
		{ $$ = CN(@1); }
	| VOLATILE
		{ $$ = CN(@1); }
	;

function_specifier
	: INLINE
		{ $$ = CN(@1); }
	;

declarator
	: pointer direct_declarator
		{
			$$ = CN("declarator",2,$1,$2);
		}
	| direct_declarator
		{
			//cout << "direct_declarator" << @1.theText << endl;
			$$ = CN("declarator",1,$1);
		}
	;


direct_declarator
	: IDENTIFIER
		{
			$$ = CN("direct_declarator",1,CN(@1));
		}
	| '(' declarator ')'
		{
			$$ = CN("direct_declarator",3,CN(@1),$2,CN(@3));
		}
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
		{
			$$ = CN("direct_declarator",5,$1,CN(@2),$3,$4,CN(@5));
		}
	| direct_declarator '[' type_qualifier_list ']'
		{
			$$ = CN("direct_declarator",4,$1,CN(@2),$3,CN(@4));
		}
	| direct_declarator '[' assignment_expression ']'
		{
			$$ = CN("direct_declarator",4,$1,CN(@2),$3,CN(@4));
		}
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
		{
			$$ = CN("direct_declarator",6,$1,CN(@2),CN(@3),$4,$5,CN(@6));
		}
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
		{
			$$ = CN("direct_declarator",6,$1,CN(@2),$3,CN(@4),$5,CN(@6));
		}
	| direct_declarator '[' type_qualifier_list '*' ']'
		{
			$$ = CN("direct_declarator",5,$1,CN(@2),$3,CN(@4),CN(@5));
		}
	| direct_declarator '[' '*' ']'
		{
			$$ = CN("direct_declarator",4,$1,CN(@2),CN(@3),CN(@4));
		}
	| direct_declarator '[' ']' 
		{
			$$ = CN("direct_declarator",3,$1,CN(@2),CN(@3));
		}
	| direct_declarator '(' parameter_type_list ')'
		{
			$$ = CN("direct_declarator",4,$1,CN(@2),$3,CN(@4));
		}
	| direct_declarator '(' identifier_list ')'
		{
			$$ = CN("direct_declarator",4,$1,CN(@2),$3,CN(@4));
		}
	| direct_declarator '(' ')'
		{
			$$ = CN("direct_declarator",3,$1,CN(@2),CN(@3)); 
		}
	;

pointer
	: '*'
		{
			$$ = CN("pointer",1,CN(@1));
		}
	| '*' type_qualifier_list
		{
			$$ = CN("pointer",2,CN(@1),$2);
		}
	| '*' pointer
		{
			$$ = CN("pointer",2,CN(@1),$2);
		}
	| '*' type_qualifier_list pointer
		{
			$$ = CN("pointer",3,CN(@1),$2,$3);
		}
	;

type_qualifier_list
	: type_qualifier
		{
			$$ = CN("type_qualifier_list",1,$1);
		}
	| type_qualifier_list type_qualifier
		{
			$$ = CN("type_qualifier_list",2,$1,$2);
		}
	;


parameter_type_list
	: parameter_list
		{
			$$ = CN("parameter_type_list",1,$1);
		}
	| parameter_list ',' ELLIPSIS
		{
			$$ = CN("parameter_type_list",3,$1,CN(@2),CN(@3));
		}
	;

parameter_list
	: parameter_declaration
		{
			$$ = CN("parameter_list",1,$1);
		}
	| parameter_list ',' parameter_declaration
		{
			$$ = CN("parameter_list",3,$1,CN(@2),$3);
		}
	;

parameter_declaration
	: declaration_specifiers declarator
		{
			$$ = CN("parameter_declaration",2,$1,$2);
		}
	| declaration_specifiers abstract_declarator
		{
			$$ = CN("parameter_declaration",2,$1,$2);
		}
	| declaration_specifiers
		{
			$$ = CN("parameter_declaration",1,$1);
		}
	;

identifier_list
	: IDENTIFIER
		{
			$$ = CN("identifier_list",1,CN(@1));
		}
	| identifier_list ',' IDENTIFIER
		{
			$$ = CN("identifier_list",3,$1,CN(@2),CN(@3));
		}
	;

type_name
	: specifier_qualifier_list
		{
			$$ = CN("type_name",1,$1);
		}
	| specifier_qualifier_list abstract_declarator
		{
			$$ = CN("type_name",2,$1,$2);
		}
	;

abstract_declarator
	: pointer
		{
			$$ = CN("abstract_declarator",1,$1);
		}
	| direct_abstract_declarator
		{
			$$ = CN("abstract_declarator",1,$1);
		}
	| pointer direct_abstract_declarator
		{
			$$ = CN("abstract_declarator",2,$1,$2);
		}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
		{
			$$ = CN("direct_abstract_declarator",3,CN(@1),$2,CN(@3));
		}
	| '[' ']'
		{
			$$ = CN("direct_abstract_declarator",2,CN(@1),CN(@2));
		}
	| '[' assignment_expression ']'
		{
			$$ = CN("direct_abstract_declarator",3,CN(@1),$2,CN(@3));
		}
	| direct_abstract_declarator '[' ']'
		{
			$$ = CN("direct_abstract_declarator",3,$1,CN(@2),CN(@3));
		}
	| direct_abstract_declarator '[' assignment_expression ']'
		{
			$$ = CN("direct_abstract_declarator",4,$1,CN(@2),$3,CN(@4));
		}
	| '[' '*' ']'
		{
			$$ = CN("direct_abstract_declarator",3,CN(@1),CN(@2),CN(@3));
		}
	| direct_abstract_declarator '[' '*' ']'
		{
			$$ = CN("direct_abstract_declarator",4,$1,CN(@2),CN(@3),CN(@4));
		}
	| '(' ')'
		{
			$$ = CN("direct_abstract_declarator",2,CN(@1),CN(@2));
		}
	| '(' parameter_type_list ')'
		{
			$$ = CN("direct_abstract_declarator",3,CN(@1),$2,CN(@3));
		}
	| direct_abstract_declarator '(' ')'
		{
			$$ = CN("direct_abstract_declarator",3,$1,CN(@2),CN(@3));
		}
	| direct_abstract_declarator '(' parameter_type_list ')'
		{
			$$ = CN("direct_abstract_declarator",4,$1,CN(@2),$3,CN(@4));
		}
	;

initializer
	: assignment_expression
		{
			$$ = CN("initializer",1,$1);
		}
	| '{' initializer_list '}'
		{
			$$ = CN("initializer",3,CN(@1),$2,CN(@3));
		}
	| '{' initializer_list ',' '}'
		{
			$$ = CN("initializer",4,CN(@1),$2,CN(@3),CN(@4));
		}
	;

initializer_list
	: initializer
		{
			$$ = CN("initializer_list",1,$1);
		}
	| designation initializer
		{
			$$ = CN("initializer_list",2,$1,$2);
		}
	| initializer_list ',' initializer
		{
			$$ = CN("initializer_list",3,$1,CN(@2),$3);
		}
	| initializer_list ',' designation initializer
		{
			$$ = CN("initializer_list",4,$1,CN(@2),$3,$4);
		}
	;

designation
	: designator_list '='
		{
			$$ = CN("designation",2,$1,CN(@2));
		}
	;

designator_list
	: designator
		{
			$$ = CN("designator_list",1,$1);
		}
	| designator_list designator
		{
			$$ = CN("designator_list",2,$1,$2);
		}
	;

designator
	: '[' constant_expression ']'
		{
			$$ = CN("designator",3,CN(@1),$2,CN(@3));
		}
	| '.' IDENTIFIER
		{
			$$ = CN("designator",2,CN(@1),CN(@2));
		}
	;

statement
	: labeled_statement
		{
			$$ = CN("statement",1,$1);
		}
	| compound_statement
		{
			$$ = CN("statement",1,$1);
		}
	| expression_statement
		{
			$$ = CN("statement",1,$1);
		}
	| selection_statement
		{
			$$ = CN("statement",1,$1);
		}
	| iteration_statement
		{
			$$ = CN("statement",1,$1);
		}
	| jump_statement
		{
			$$ = CN("statement",1,$1);
		}
	;

labeled_statement
	: IDENTIFIER ':' statement
		{
			$$ = CN("labeled_statement",3,CN(@1),CN(@2),$3);
		}
	| CASE constant_expression ':' statement
		{
			$$ = CN("labeled_statement",4,CN(@1),$2,CN(@3),$4);
		}
	| DEFAULT ':' statement
		{
			$$ = CN("labeled_statement",3,CN(@1),CN(@2),$3);
		}
	;

compound_statement
	: '{' '}'
		{
			$$ = CN("compound_statement",2,CN(@1),CN(@2)); 
		}
	| '{' block_item_list '}'
		{
			$$ = CN("compound_statement",3,CN(@1),$2,CN(@3)); 
		}
	;

block_item_list
	: block_item
		{
			$$ = CN("block_item_list",1,$1); 
		}
	| block_item_list block_item
		{
			//$$ = CN("block_item_list",2,$1,$2); 
			$$ = $1;
			$1->AddChildNode($2);
		}
	;

block_item
	: declaration
		{
			//$$ = CN("block_item",1,$1); 
			$$ = $1;
		}
	| statement
		{
			//$$ = CN("block_item",1,$1);
			$$ = $1;
		}
	;

expression_statement
	: ';'
		{
			$$ = CN("expression_statement",1,CN(@1));
		}
	| expression ';'
		{
			$$ = CN("expression_statement",2,$1,CN(@2));
		}
	;

selection_statement
	: IF '(' expression ')' statement
		{
			$$ = CN("selection_statement",5,CN(@1),CN(@2),$3,CN(@4),$5);
		}
	| IF '(' expression ')' statement ELSE statement
		{
			$$ = CN("selection_statement",7,CN(@1),CN(@2),$3,CN(@4),$5,CN(@6),$7);
		}
	| SWITCH '(' expression ')' statement
		{
			$$ = CN("selection_statement",5,CN(@1),CN(@2),$3,CN(@4),$5);
		}
	;

iteration_statement
	: WHILE '(' expression ')' statement
		{
			$$ = CN("iteration_statement",5,CN(@1),CN(@2),$3,CN(@4),$5);
		}
	| DO statement WHILE '(' expression ')' ';'
		{
			$$ = CN("iteration_statement",7,CN(@1),$2,CN(@3),CN(@4),$5,CN(@6),CN(@7));
		}
	| FOR '(' expression_statement expression_statement ')' statement
		{
			$$ = CN("iteration_statement",6,CN(@1),CN(@2),$3,$4,CN(@5),$6);
		}
	| FOR '(' expression_statement expression_statement expression ')' statement
		{
			$$ = CN("iteration_statement",7,CN(@1),CN(@2),$3,$4,$5,CN(@6),$7);
		}
	| FOR '(' declaration expression_statement ')' statement
		{
			$$ = CN("iteration_statement",6,CN(@1),CN(@2),$3,$4,CN(@5),$6);
		}
	| FOR '(' declaration expression_statement expression ')' statement
		{
			$$ = CN("iteration_statement",7,CN(@1),CN(@2),$3,$4,$5,CN(@6),$7);
		}
	;

jump_statement
	: GOTO IDENTIFIER ';'
		{
			$$ = CN("jump_statement",3,CN(@1),CN(@2),CN(@3));
		}
	| CONTINUE ';'
		{
			$$ = CN("jump_statement",2,CN(@1),CN(@2));
		}
	| BREAK ';'
		{
			$$ = CN("jump_statement",2,CN(@1),CN(@2));
		}
	| RETURN ';'
		{
			$$ = CN("jump_statement",2,CN(@1),CN(@2));
		}
	| RETURN expression ';'
		{
			$$ = CN("jump_statement",3,CN(@1),$2,CN(@3));
		}
	;

translation_unit
	: external_declaration
		{
			$$ = CN("translation_unit",1,$1);
			setCurrentTree((Tree *)$$);
		}
	| translation_unit external_declaration
		{
			$$ = CN("translation_unit",2,$1,$2);
			setCurrentTree((Tree *)$$);
		}
	;

external_declaration
	: function_definition
		{
			$$ = CN("external_declaration",1,$1);
		}
	| declaration
		{
			$$ = CN("external_declaration",1,$1);
		}
	| ';'
		{
			$$ = CN("external_declaration",1,CN(@1)); 
		}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
		{
			$$ = CN("function_definition",4,$1,$2,$3,$4);
			// Parser Action
			ParsedFunctionDefinition($$, $2);
		}
	| declaration_specifiers declarator compound_statement
		{
			$$ = CN("function_definition",3,$1,$2,$3);
			// Parser Action
			ParsedFunctionDefinition($$, $2);
		}
	;

declaration_list
	: declaration
		{
			$$ = CN("declaration_list",1,$1);
		}
	| declaration_list declaration
		{
			$$ = CN("declaration_list",2,$1,$2);
		}
	;

%%
