/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "2005064.y"
#include<bits/stdc++.h>
#include "2005064_SymbolInfo.cpp"
#include "2005064_SymbolTable.h"
using namespace std;



SymbolTable* st;
SymbolInfo* funcparams = new SymbolInfo();
vector<SymbolInfo*> globalVariables;
SymbolInfo *root;
extern int line_count;
extern int error_count;
extern FILE *yyin;



string ruleOf(vector<SymbolInfo*> SI){
	string name = "";
	for(auto si: SI){
		name += " ";
		name += si->type;
	}
	return name;
}

string typeCast(SymbolInfo* a,SymbolInfo* b){
	if(a->typeSpecifier == "FLOAT" or b->typeSpecifier == "FLOAT" ) return "FLOAT";
	
	return "INT";
}

int labelCount=0;
int tempCount=0;





string currFunc;

void InsertIntoScope(SymbolInfo* funcName, SymbolInfo* funcType){
	funcName->setTypeSpecifier(funcType->typeSpecifier);
	funcName->setParameterList(funcparams->parameterlist);
	funcName->setIsFunction(true);
	currFunc = funcName->name;
	if( st->insert(funcName)) return;
	
	SymbolInfo* oldFunc = st->lookUp(funcName->name);
		
	vector<SymbolInfo*> declaredArgs = oldFunc->parameterlist;
	vector<SymbolInfo*> definedArgs = funcName->parameterlist;
}



void yyerror(char *s){
	printf("%s\n",s);
}

int yylex(void);


#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 68 "2005064.y"
typedef union YYSTYPE{
    SymbolInfo* si; 
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 99 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NEWLINE 257
#define CONST_FLOAT 258
#define CONST_INT 259
#define CONST_CHAR 260
#define IF 261
#define LOWER_THAN_ELSE 262
#define FOR 263
#define DO 264
#define INT 265
#define FLOAT 266
#define VOID 267
#define SWITCH 268
#define DEFAULT 269
#define ELSE 270
#define WHILE 271
#define BREAK 272
#define CHAR 273
#define DOUBLE 274
#define RETURN 275
#define CASE 276
#define CONTINUE 277
#define PRINTLN 278
#define ADDOP 279
#define MULOP 280
#define INCOP 281
#define RELOP 282
#define ASSIGNOP 283
#define LOGICOP 284
#define BITOP 285
#define NOT 286
#define LPAREN 287
#define RPAREN 288
#define LTHIRD 289
#define RTHIRD 290
#define LCURL 291
#define RCURL 292
#define COMMA 293
#define SEMICOLON 294
#define ID 295
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    3,    3,   24,    4,
   25,    4,    5,    5,    5,    5,    6,    6,    7,    8,
    8,    8,    9,    9,    9,    9,   10,   10,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   12,   12,   13,
   13,   14,   14,   15,   15,   16,   16,   17,   17,   18,
   18,   19,   19,   19,   20,   20,   20,   20,   20,   20,
   21,   21,   22,   22,   23,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    6,    5,    0,    7,
    0,    6,    4,    3,    2,    1,    3,    2,    3,    1,
    1,    1,    3,    6,    1,    4,    1,    2,    1,    1,
    1,    7,    5,    7,    5,    5,    3,    1,    2,    1,
    4,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    3,    2,    2,    1,    1,    4,    3,    1,    1,    2,
    1,    0,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   20,   21,   22,    0,    0,    3,    5,    6,    4,    0,
    2,    0,    0,    0,    0,    0,   19,    0,    0,    0,
    0,    0,    8,    0,    0,    0,   15,   26,    0,   65,
   12,    0,    7,    0,    0,    0,   59,   58,    0,    0,
    0,    0,    0,    0,    0,    0,   18,   38,    0,   31,
   29,    0,    0,   27,   30,    0,    0,   42,    0,    0,
    0,   50,   54,   10,   13,   24,    0,    0,    0,    0,
    0,    0,   52,   53,    0,    0,    0,    0,   17,   28,
   60,    0,   39,    0,    0,    0,    0,    0,    0,    0,
   37,    0,   57,   64,    0,    0,    0,   43,   45,    0,
    0,   51,    0,    0,    0,    0,   56,    0,   41,    0,
    0,   35,   36,   63,    0,    0,   34,   32,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  265,  266,  267,  297,  298,  299,  300,  301,  304,  305,
  299,  295,  306,  287,  289,  293,  294,  288,  302,  305,
  259,  295,  294,  322,  288,  293,  295,  290,  289,  291,
  303,  320,  294,  321,  305,  259,  258,  259,  261,  263,
  271,  275,  278,  279,  286,  287,  292,  294,  295,  303,
  304,  305,  307,  308,  309,  310,  311,  312,  313,  314,
  315,  316,  317,  303,  295,  290,  287,  287,  287,  311,
  287,  310,  316,  316,  311,  287,  289,  295,  292,  308,
  281,  283,  294,  284,  279,  282,  280,  311,  309,  311,
  294,  295,  288,  312,  318,  319,  311,  312,  313,  315,
  314,  316,  288,  309,  288,  288,  288,  293,  290,  308,
  311,  308,  294,  312,  270,  288,  308,  308,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,   19,   50,   51,   52,   13,   53,
   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   95,   96,   32,   34,   24,
};
static const YYINT yysindex[] = {                      -138,
    0,    0,    0,    0, -138,    0,    0,    0,    0, -289,
    0, -250, -170, -255, -237, -244,    0, -231, -270, -226,
 -217, -198,    0, -192, -187, -138,    0,    0, -157,    0,
    0, -191,    0, -192, -186, -174,    0,    0, -168, -156,
 -150, -197, -147, -197, -197, -197,    0,    0, -210,    0,
    0, -148, -153,    0,    0, -200, -149,    0, -135, -230,
 -125,    0,    0,    0,    0,    0, -197, -201, -197, -133,
 -130, -122,    0,    0, -126, -197, -197, -123,    0,    0,
    0, -197,    0, -197, -197, -197, -197, -121, -201, -120,
    0, -119,    0,    0, -118, -110, -117,    0,    0, -125,
 -105,    0,  -77, -197,  -77, -116,    0, -197,    0,  -95,
 -103,    0,    0,    0,  -77,  -77,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,  187,    0,    0,    0,    0,    0,
    0, -140,    0,    0,    0,    0,    0, -100,    0, -262,
    0, -136,    0,    0,  -99,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -258,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -59,    0,
    0,    0,    0,    0,    0,  -36,    0,    0, -158, -269,
 -234,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -52,    0,    0,    0,  -93,    0, -140,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -92,    0,    0,    0,  -29,
 -173,    0,    0,    0,    0,    0,    0,    0,    0, -115,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  188,    0,    0,    0,   -7,   92,    2,    0,    0,
  -50,  -60,  -44,  -33,  -62,  113,  114,  118,  -40,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 265
static const YYINT yytable[] = {                         72,
   72,   10,   80,   73,   74,   12,   10,   89,   70,    1,
    2,    3,   75,   94,   46,   20,   31,   25,   46,   98,
   46,   21,   26,   46,   46,   16,   64,   35,  104,   14,
   16,   72,   18,   88,   14,   90,   14,   72,   15,   72,
   72,   72,   72,   97,   48,  114,  102,   48,   85,   48,
   22,   86,  110,   48,  112,   48,   37,   38,   48,   48,
   37,   38,   23,   72,  117,  118,   37,   38,   27,   39,
  111,   40,   28,    1,    2,    3,   76,   44,   77,   41,
   81,   44,   82,   42,   45,   46,   43,   44,   45,   46,
   29,    9,   48,   49,   45,   46,    9,   49,   30,   30,
   47,   36,   48,   49,   37,   38,   33,   39,   65,   40,
   47,    1,    2,    3,   47,   66,   47,   41,   67,   47,
   47,   42,   16,   17,   43,   44,    1,    2,    3,   44,
   68,   44,   45,   46,   44,   44,   69,   30,   79,   71,
   48,   49,   33,   33,   83,   33,   78,   33,   84,   33,
   33,   33,   25,   25,   87,   33,   23,   23,   81,   33,
   91,   93,   33,   33,   92,   15,  103,  105,  106,  107,
   33,   33,  109,   85,  115,   33,   33,  113,   33,   33,
   37,   38,  108,   39,  116,   40,    1,    1,    2,    3,
   11,    9,   11,   41,   62,   61,   99,   42,    0,  101,
   43,   44,  100,    0,    0,    0,    0,    0,   45,   46,
    0,    0,    0,   30,    0,    0,   48,   49,    0,   40,
   40,   40,   40,   40,   40,    0,   55,   55,   40,   55,
   40,   55,    0,   40,   40,   55,    0,   55,    0,    0,
   55,   55,   55,   55,    0,   55,    0,   55,    0,   49,
    0,   55,   49,   55,   49,    0,    0,   55,   49,    0,
   49,    0,    0,   49,   49,
};
static const YYINT yycheck[] = {                         44,
   45,    0,   53,   44,   45,  295,    5,   68,   42,  265,
  266,  267,   46,   76,  284,   14,   24,  288,  288,   82,
  290,  259,  293,  293,  294,  288,   34,   26,   89,  288,
  293,   76,  288,   67,  293,   69,  287,   82,  289,   84,
   85,   86,   87,   77,  279,  108,   87,  282,  279,  284,
  295,  282,  103,  288,  105,  290,  258,  259,  293,  294,
  258,  259,  294,  108,  115,  116,  258,  259,  295,  261,
  104,  263,  290,  265,  266,  267,  287,  279,  289,  271,
  281,  279,  283,  275,  286,  287,  278,  279,  286,  287,
  289,    0,  294,  295,  286,  287,    5,  295,  291,  291,
  292,  259,  294,  295,  258,  259,  294,  261,  295,  263,
  284,  265,  266,  267,  288,  290,  290,  271,  287,  293,
  294,  275,  293,  294,  278,  279,  265,  266,  267,  288,
  287,  290,  286,  287,  293,  294,  287,  291,  292,  287,
  294,  295,  258,  259,  294,  261,  295,  263,  284,  265,
  266,  267,  293,  294,  280,  271,  293,  294,  281,  275,
  294,  288,  278,  279,  295,  289,  288,  288,  288,  288,
  286,  287,  290,  279,  270,  291,  292,  294,  294,  295,
  258,  259,  293,  261,  288,  263,    0,  265,  266,  267,
  291,  291,    5,  271,  288,  288,   84,  275,   -1,   86,
  278,  279,   85,   -1,   -1,   -1,   -1,   -1,  286,  287,
   -1,   -1,   -1,  291,   -1,   -1,  294,  295,   -1,  279,
  280,  281,  282,  283,  284,   -1,  279,  280,  288,  282,
  290,  284,   -1,  293,  294,  288,   -1,  290,   -1,   -1,
  293,  294,  279,  280,   -1,  282,   -1,  284,   -1,  279,
   -1,  288,  282,  290,  284,   -1,   -1,  294,  288,   -1,
  290,   -1,   -1,  293,  294,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 295
#define YYUNDFTOKEN 323
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","NEWLINE","CONST_FLOAT",
"CONST_INT","CONST_CHAR","IF","LOWER_THAN_ELSE","FOR","DO","INT","FLOAT","VOID",
"SWITCH","DEFAULT","ELSE","WHILE","BREAK","CHAR","DOUBLE","RETURN","CASE",
"CONTINUE","PRINTLN","ADDOP","MULOP","INCOP","RELOP","ASSIGNOP","LOGICOP",
"BITOP","NOT","LPAREN","RPAREN","LTHIRD","RTHIRD","LCURL","RCURL","COMMA",
"SEMICOLON","ID","$accept","start","program","unit","func_declaration",
"func_definition","parameter_list","compound_statement","var_declaration",
"type_specifier","declaration_list","statements","statement",
"expression_statement","variable","expression","logic_expression",
"rel_expression","simple_expression","term","unary_expression","factor",
"argument_list","arguments","LCURL_","$$1","$$2","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : program",
"program : program unit",
"program : unit",
"unit : var_declaration",
"unit : func_declaration",
"unit : func_definition",
"func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",
"func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON",
"$$1 :",
"func_definition : type_specifier ID LPAREN parameter_list RPAREN $$1 compound_statement",
"$$2 :",
"func_definition : type_specifier ID LPAREN RPAREN $$2 compound_statement",
"parameter_list : parameter_list COMMA type_specifier ID",
"parameter_list : parameter_list COMMA type_specifier",
"parameter_list : type_specifier ID",
"parameter_list : type_specifier",
"compound_statement : LCURL_ statements RCURL",
"compound_statement : LCURL_ RCURL",
"var_declaration : type_specifier declaration_list SEMICOLON",
"type_specifier : INT",
"type_specifier : FLOAT",
"type_specifier : VOID",
"declaration_list : declaration_list COMMA ID",
"declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD",
"declaration_list : ID",
"declaration_list : ID LTHIRD CONST_INT RTHIRD",
"statements : statement",
"statements : statements statement",
"statement : var_declaration",
"statement : expression_statement",
"statement : compound_statement",
"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement",
"statement : IF LPAREN expression RPAREN statement",
"statement : IF LPAREN expression RPAREN statement ELSE statement",
"statement : WHILE LPAREN expression RPAREN statement",
"statement : PRINTLN LPAREN ID RPAREN SEMICOLON",
"statement : RETURN expression SEMICOLON",
"expression_statement : SEMICOLON",
"expression_statement : expression SEMICOLON",
"variable : ID",
"variable : ID LTHIRD expression RTHIRD",
"expression : logic_expression",
"expression : variable ASSIGNOP logic_expression",
"logic_expression : rel_expression",
"logic_expression : rel_expression LOGICOP rel_expression",
"rel_expression : simple_expression",
"rel_expression : simple_expression RELOP simple_expression",
"simple_expression : term",
"simple_expression : simple_expression ADDOP term",
"term : unary_expression",
"term : term MULOP unary_expression",
"unary_expression : ADDOP unary_expression",
"unary_expression : NOT unary_expression",
"unary_expression : factor",
"factor : variable",
"factor : ID LPAREN argument_list RPAREN",
"factor : LPAREN expression RPAREN",
"factor : CONST_INT",
"factor : CONST_FLOAT",
"factor : variable INCOP",
"argument_list : arguments",
"argument_list :",
"arguments : arguments COMMA logic_expression",
"arguments : logic_expression",
"LCURL_ : LCURL",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 391 "2005064.y"


void yyerror(const char *s){
	//cout << "Error at line no " << line_count << " : " << s << endl;
}

int main(int argc, char** argv)
{
    st = new SymbolTable(11);
    line_count = 1;
	error_count = 0;
    if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	yyin=fin;
    yyparse();
	ofstream assemblycode("2005064_code.asm");
	
	root->codeGeneration(assemblycode);
	
	assemblycode<<endl;

									
	
    exit(0);
}
#line 628 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 81 "2005064.y"
	{
									yyval.si = new SymbolInfo("","start","",{yystack.l_mark[0].si});
									yyval.si->MakeRule("start : program");
									
				                    yyval.si->globalVars=globalVariables;
									root=yyval.si;
									
									
									
								}
#line 1310 "y.tab.c"
break;
case 2:
#line 92 "2005064.y"
	{yyval.si = new SymbolInfo("","program","",{yystack.l_mark[-1].si,yystack.l_mark[0].si});
                                
								 yyval.si->MakeRule("program : program unit");
                                                                 
								
				}
#line 1320 "y.tab.c"
break;
case 3:
#line 98 "2005064.y"
	{yyval.si = new SymbolInfo("","program","",{yystack.l_mark[0].si});
				                yyval.si->MakeRule("program : unit");

				}
#line 1328 "y.tab.c"
break;
case 4:
#line 103 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"unit","",{yystack.l_mark[0].si});
                                     yyval.si->MakeRule("unit : var_declaration");
                }
#line 1335 "y.tab.c"
break;
case 5:
#line 106 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"unit","",{yystack.l_mark[0].si});
				                     yyval.si->MakeRule("unit : func_declaration");
				}
#line 1342 "y.tab.c"
break;
case 6:
#line 109 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"unit","",{yystack.l_mark[0].si});
				                     yyval.si->MakeRule("unit : func_definition");
				                     
				}
#line 1350 "y.tab.c"
break;
case 7:
#line 114 "2005064.y"
	{ 
									yyval.si = new SymbolInfo(yystack.l_mark[-4].si->name,"func_declaration","",{yystack.l_mark[-5].si,yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si}); 
									yyval.si->MakeRule("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
									yystack.l_mark[-4].si->setTypeSpecifier(yystack.l_mark[-5].si->typeSpecifier); 
									yystack.l_mark[-4].si->setIsDeclared(true); 
									yystack.l_mark[-4].si->setParameterList(yystack.l_mark[-2].si->parameterlist); 
									funcparams->setParameterList({}); 
									st->insert(yystack.l_mark[-4].si); 
								}
#line 1363 "y.tab.c"
break;
case 8:
#line 123 "2005064.y"
	{ 
									yyval.si = new SymbolInfo(yystack.l_mark[-3].si->name,"func_declaration","",{yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si}); 
									yyval.si->MakeRule("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
									yystack.l_mark[-3].si->setTypeSpecifier(yystack.l_mark[-4].si->typeSpecifier); 
									yystack.l_mark[-3].si->setIsDeclared(true); 
									st->insert(yystack.l_mark[-3].si); 
								}
#line 1374 "y.tab.c"
break;
case 9:
#line 131 "2005064.y"
	{ InsertIntoScope(yystack.l_mark[-3].si,yystack.l_mark[-4].si); }
#line 1379 "y.tab.c"
break;
case 10:
#line 131 "2005064.y"
	{ yyval.si = new SymbolInfo(yystack.l_mark[-5].si->name,"func_definition","",{yystack.l_mark[-6].si,yystack.l_mark[-5].si,yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[0].si});yyval.si->MakeRule("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");}
#line 1384 "y.tab.c"
break;
case 11:
#line 132 "2005064.y"
	{ InsertIntoScope(yystack.l_mark[-2].si,yystack.l_mark[-3].si); }
#line 1389 "y.tab.c"
break;
case 12:
#line 132 "2005064.y"
	{ yyval.si = new SymbolInfo(yystack.l_mark[-4].si->name,"func_definition","",{yystack.l_mark[-5].si,yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[0].si});yyval.si->MakeRule("func_definition : type_specifier ID LPAREN RPAREN compound_statement");}
#line 1394 "y.tab.c"
break;
case 13:
#line 134 "2005064.y"
	{
									yyval.si = new SymbolInfo("","parameter_list","",{yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("parameter_list : parameter list COMMA type_specifier ID");
									yyval.si->setParameterList(yystack.l_mark[-3].si->parameterlist); 
									yyval.si->addParameter(yystack.l_mark[0].si); 
									yystack.l_mark[0].si->setTypeSpecifier(yystack.l_mark[-1].si->typeSpecifier); 
									funcparams->setParameterList(yyval.si->parameterlist); 
								}
#line 1406 "y.tab.c"
break;
case 14:
#line 142 "2005064.y"
	{ 
									yyval.si = new SymbolInfo("","parameter_list","",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si}); 
									yyval.si->MakeRule("parameter_list : parameter_list COMMA type_specifier");
									SymbolInfo* body = new SymbolInfo("","ID"); 
									yyval.si->setParameterList(yystack.l_mark[-2].si->parameterlist); 
									yyval.si->addParameter(body);  
									body->setTypeSpecifier(yystack.l_mark[0].si->typeSpecifier); 
									funcparams->setParameterList(yyval.si->parameterlist); 
								}
#line 1419 "y.tab.c"
break;
case 15:
#line 151 "2005064.y"
	{ 
									yyval.si = new SymbolInfo("","parameter_list","",{yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("parameter_list : type_specifier ID");
									yystack.l_mark[0].si->setTypeSpecifier(yystack.l_mark[-1].si->typeSpecifier); 
									yyval.si->addParameter(yystack.l_mark[0].si); 
									funcparams->setParameterList(yyval.si->parameterlist); 
								}
#line 1430 "y.tab.c"
break;
case 16:
#line 158 "2005064.y"
	{ 
									yyval.si = new SymbolInfo("","parameter_list","",{yystack.l_mark[0].si});
									yyval.si->MakeRule("parameter_list : type_specifier");
									SymbolInfo* body = new SymbolInfo("","ID"); 
									body->setTypeSpecifier(yystack.l_mark[0].si->typeSpecifier); 
									yyval.si->addParameter(body); 
									funcparams->setParameterList(yyval.si->parameterlist); 
								}
#line 1442 "y.tab.c"
break;
case 17:
#line 168 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[-1].si->name,"compound_statement","",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("compound_statement : LCURL statements RCURL");
									yyval.si->stackOffset = st->getStackOffset();
									st->exitScope();
								}
#line 1452 "y.tab.c"
break;
case 18:
#line 174 "2005064.y"
	{
									yyval.si = new SymbolInfo("","compound_statement","",{yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("compound_statement : LCURL RCURL");
									yyval.si->stackOffset = st->getStackOffset();
									st->exitScope();
								}
#line 1462 "y.tab.c"
break;
case 19:
#line 181 "2005064.y"
	{
									yyval.si = new SymbolInfo("","var_declaration","",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("var_declaration : type_specifier declaration_list SEMICOLON");
									if(st->getID()==1) yyval.si->isGlobal = true;
									else yyval.si->isGlobal = false;
									for(int i=0; i<yystack.l_mark[-1].si->declarationlist.size(); i++){
										auto a = yystack.l_mark[-1].si->declarationlist[i];
										a->setTypeSpecifier(yystack.l_mark[-2].si->typeSpecifier);
										st->insert(a);
										if(st->getID()==1){
											a->stackOffset = 0;
											globalVariables.push_back(a);
											a->isGlobal = true;
											
										}
										else{
											a->isGlobal = false;
											if(a->isArray) st->setStackOffset(st->getStackOffset()-2*a->arraySize);
											else st->setStackOffset(st->getStackOffset()-2);
											a->stackOffset = st->getStackOffset();
										}
									}
								}
#line 1489 "y.tab.c"
break;
case 20:
#line 205 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"type_specifier",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[0].si});yyval.si->MakeRule("type_specifier : INT");}
#line 1494 "y.tab.c"
break;
case 21:
#line 206 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"type_specifier",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[0].si});yyval.si->MakeRule("type_specifier : FLOAT");}
#line 1499 "y.tab.c"
break;
case 22:
#line 207 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"type_specifier",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[0].si});yyval.si->MakeRule("type_specifier : VOID");}
#line 1504 "y.tab.c"
break;
case 23:
#line 209 "2005064.y"
	{
									yyval.si = new SymbolInfo("","declaration_list","",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("declaration_list : declaration_list COMMA ID");
									yyval.si->setDeclarationList(yystack.l_mark[-2].si->declarationlist);
									yyval.si->pushDeclaration(yystack.l_mark[0].si);
								}
#line 1514 "y.tab.c"
break;
case 24:
#line 215 "2005064.y"
	{
									yyval.si = new SymbolInfo("","declaration_list","",{yystack.l_mark[-5].si,yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
									yyval.si->setDeclarationList(yystack.l_mark[-5].si->declarationlist);
									yystack.l_mark[-3].si->setIsArray(true);
									string s = yystack.l_mark[-1].si->name;
									istringstream is(s);
									int i;
									is >> i;
									yystack.l_mark[-3].si->arraySize = i;
									
									yyval.si->pushDeclaration(yystack.l_mark[-3].si);
								}
#line 1531 "y.tab.c"
break;
case 25:
#line 228 "2005064.y"
	{
									yyval.si = new SymbolInfo("","declaration_list","",{yystack.l_mark[0].si});
									yyval.si->MakeRule("declaration_list : ID");
									yyval.si->pushDeclaration(yystack.l_mark[0].si);
								}
#line 1540 "y.tab.c"
break;
case 26:
#line 233 "2005064.y"
	{
									yyval.si = new SymbolInfo("","declaration_list","",{yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("declaration_list : ID LTHIRD CONST_INT RTHIRD");
									yystack.l_mark[-3].si->setIsArray(true);
									string s = yystack.l_mark[-1].si->name;
									istringstream is(s);
									int i;
									is >> i;
									yystack.l_mark[-3].si->arraySize = i;	
									cout<< yystack.l_mark[-3].si->name<< " yay\n";				
									yyval.si->pushDeclaration(yystack.l_mark[-3].si);
								}
#line 1556 "y.tab.c"
break;
case 27:
#line 246 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"statements","",{yystack.l_mark[0].si});yyval.si->MakeRule("statements : statement");}
#line 1561 "y.tab.c"
break;
case 28:
#line 247 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-1].si->name,"statements","",{yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("statements : statements statement");}
#line 1566 "y.tab.c"
break;
case 29:
#line 249 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"statement","",{yystack.l_mark[0].si});yyval.si->MakeRule("statement : var_declaration");}
#line 1571 "y.tab.c"
break;
case 30:
#line 250 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"statement","",{yystack.l_mark[0].si});yyval.si->MakeRule("statement : expression_statement");}
#line 1576 "y.tab.c"
break;
case 31:
#line 251 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"statement","",{yystack.l_mark[0].si});yyval.si->MakeRule("statement : compound_statement");}
#line 1581 "y.tab.c"
break;
case 32:
#line 252 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[-6].si->name,"statement","",{yystack.l_mark[-6].si,yystack.l_mark[-5].si,yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
								}
#line 1589 "y.tab.c"
break;
case 33:
#line 256 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[-4].si->name,"statement","",{yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("statement : IF LPAREN expression RPAREN statement");
								}
#line 1597 "y.tab.c"
break;
case 34:
#line 260 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[-6].si->name,"statement","",{yystack.l_mark[-6].si,yystack.l_mark[-5].si,yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("statement : IF LPAREN expression RPAREN statement ELSE statement");
								}
#line 1605 "y.tab.c"
break;
case 35:
#line 264 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[-4].si->name,"statement","",{yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("statement : WHILE LPAREN expression RPAREN statement");
								}
#line 1613 "y.tab.c"
break;
case 36:
#line 268 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[-4].si->name,"statement","",{yystack.l_mark[-4].si,yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
									auto a = st->lookUp(yystack.l_mark[-2].si->name);
									yyval.si->stackOffset = a->stackOffset;
									if(a->isGlobal) yyval.si->isGlobal = true;
									else yyval.si->isGlobal = false;
								}
#line 1625 "y.tab.c"
break;
case 37:
#line 276 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[-2].si->name,"statement","",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("statement : RETURN expression SEMICOLON");
									yystack.l_mark[-2].si->name = currFunc;
								}
#line 1634 "y.tab.c"
break;
case 38:
#line 282 "2005064.y"
	{yyval.si = new SymbolInfo("","expression_statement","",{yystack.l_mark[0].si});yyval.si->MakeRule("expression_statement : SEMICOLON");}
#line 1639 "y.tab.c"
break;
case 39:
#line 283 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-1].si->name,"expression_statement",yystack.l_mark[-1].si->typeSpecifier,{yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("expression_statement : expression SEMICOLON");}
#line 1644 "y.tab.c"
break;
case 40:
#line 285 "2005064.y"
	{
									SymbolInfo* a = st->lookUp(yystack.l_mark[0].si->name);
									yyval.si->MakeRule("variable : ID");
									yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"variable",a->typeSpecifier,{yystack.l_mark[0].si});
									yyval.si->setIsArray(a->isArray);
									yyval.si->stackOffset = a->stackOffset;
									yyval.si->isGlobal = a->isGlobal;
								}
#line 1656 "y.tab.c"
break;
case 41:
#line 293 "2005064.y"
	{
									SymbolInfo* a = st->lookUp(yystack.l_mark[-3].si->name);
									yyval.si->MakeRule("variable : ID LTHIRD expression RTHIRD");
									yyval.si = new SymbolInfo(yystack.l_mark[-3].si->name,"variable",a->typeSpecifier,{yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->setIsArray(a->isArray);
									yyval.si->stackOffset = a->stackOffset;
									yyval.si->isGlobal = a->isGlobal;
								}
#line 1668 "y.tab.c"
break;
case 42:
#line 302 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"expression","",{yystack.l_mark[0].si});yyval.si->MakeRule("expression : logic_expression");}
#line 1673 "y.tab.c"
break;
case 43:
#line 303 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-2].si->name,"expression","",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("expression : variable ASSIGNOP logic_expression");}
#line 1678 "y.tab.c"
break;
case 44:
#line 305 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"logic_expression",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[0].si});
									yyval.si->MakeRule("logic_expression : rel_expression");
									yyval.si->setIsArray(yystack.l_mark[0].si->isArray);
								}
#line 1687 "y.tab.c"
break;
case 45:
#line 310 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-2].si->name,"logic_expression","INT",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("logic_expression : rel_expression LOGICOP rel_expression");}
#line 1692 "y.tab.c"
break;
case 46:
#line 312 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"rel_expression",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[0].si});
									yyval.si->MakeRule("rel_expression : simple_expression");
									yyval.si->setIsArray(yystack.l_mark[0].si->isArray);
								}
#line 1701 "y.tab.c"
break;
case 47:
#line 317 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-2].si->name,"rel_expression","INT",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("rel_expression : simple_expression RELOP simple_expression");}
#line 1706 "y.tab.c"
break;
case 48:
#line 319 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"simple_expression",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[0].si});
									yyval.si->MakeRule("simple_expression : term");
									yyval.si->setIsArray(yystack.l_mark[0].si->isArray);
								}
#line 1715 "y.tab.c"
break;
case 49:
#line 324 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-2].si->name,"simple_expression",typeCast(yystack.l_mark[-2].si,yystack.l_mark[0].si),{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("simple_expression : simple_expression ADDOP term");}
#line 1720 "y.tab.c"
break;
case 50:
#line 326 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"term",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[0].si});
									yyval.si->MakeRule("term : unary_expression");
									yyval.si->setIsArray(yystack.l_mark[0].si->isArray);
								}
#line 1729 "y.tab.c"
break;
case 51:
#line 331 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-2].si->name,"term",typeCast(yystack.l_mark[-2].si,yystack.l_mark[0].si),{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("term : term MULOP unary_expression");}
#line 1734 "y.tab.c"
break;
case 52:
#line 333 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"unary_expression",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("unary_expression : ADDOP unary_expression");}
#line 1739 "y.tab.c"
break;
case 53:
#line 334 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"unary_expression","INT",{yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("unary_expression : NOT unary_expression");}
#line 1744 "y.tab.c"
break;
case 54:
#line 335 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"unary_expression",yystack.l_mark[0].si->typeSpecifier,{yystack.l_mark[0].si});
									yyval.si->MakeRule("unary_expression : factor");
									yyval.si->setIsArray(yystack.l_mark[0].si->isArray);
								}
#line 1753 "y.tab.c"
break;
case 55:
#line 341 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"factor","",{yystack.l_mark[0].si});yyval.si->MakeRule("factor : variable");}
#line 1758 "y.tab.c"
break;
case 56:
#line 342 "2005064.y"
	{
									auto a = st->lookUp(yystack.l_mark[-3].si->name);
									yyval.si = new SymbolInfo(ruleOf({yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si}),"factor",a->typeSpecifier,{yystack.l_mark[-3].si,yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("factor : ID LPAREN argument_list RPAREN");
									vector<SymbolInfo*> b = yystack.l_mark[-1].si->parameterlist;
									vector<SymbolInfo*> c = a->parameterlist;
								}
#line 1769 "y.tab.c"
break;
case 57:
#line 349 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-1].si->name,"factor",yystack.l_mark[-1].si->typeSpecifier,{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("factor : LPAREN expression RPAREN");}
#line 1774 "y.tab.c"
break;
case 58:
#line 350 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"factor","INT",{yystack.l_mark[0].si});	yyval.si->MakeRule("factor : CONST_INT");}
#line 1779 "y.tab.c"
break;
case 59:
#line 351 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"factor","FLOAT",{yystack.l_mark[0].si});yyval.si->MakeRule("factor : CONST_FLOAT");}
#line 1784 "y.tab.c"
break;
case 60:
#line 352 "2005064.y"
	{yyval.si = new SymbolInfo(yystack.l_mark[-1].si->name,"factor",yystack.l_mark[-1].si->typeSpecifier,{yystack.l_mark[-1].si,yystack.l_mark[0].si});yyval.si->MakeRule("factor : variable INCOP");}
#line 1789 "y.tab.c"
break;
case 61:
#line 355 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"argument_list","",{yystack.l_mark[0].si});
									yyval.si->MakeRule("argument_list : arguments");

									yyval.si->setParameterList(yystack.l_mark[0].si->parameterlist);
									yyval.si->stackOffset = yystack.l_mark[0].si->stackOffset;
								}
#line 1800 "y.tab.c"
break;
case 62:
#line 362 "2005064.y"
	{yyval.si = new SymbolInfo("","argument_list","",{});}
#line 1805 "y.tab.c"
break;
case 63:
#line 364 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[-2].si->name,"arguments","",{yystack.l_mark[-2].si,yystack.l_mark[-1].si,yystack.l_mark[0].si});
									yyval.si->MakeRule("arguments : arguments COMMA logic_expression");
									yyval.si->setParameterList(yystack.l_mark[-2].si->parameterlist);
									yyval.si->addParameter(yystack.l_mark[0].si);
									yyval.si->stackOffset = yystack.l_mark[-2].si->stackOffset+2;
								}
#line 1816 "y.tab.c"
break;
case 64:
#line 371 "2005064.y"
	{
									yyval.si = new SymbolInfo(yystack.l_mark[0].si->name,"arguments","",{yystack.l_mark[0].si});
									yyval.si->MakeRule("arguments : logic_expression");
									yyval.si->addParameter(yystack.l_mark[0].si);
									yyval.si->stackOffset = 2;
								}
#line 1826 "y.tab.c"
break;
case 65:
#line 377 "2005064.y"
	{
									yyval.si = yystack.l_mark[0].si; st->enterScope();
									int stackOffset = 2;
									for(int i = funcparams->parameterlist.size()-1; i>=0; i--){
										auto a = funcparams->parameterlist[i];
										if( a->name == "" ) continue;
										stackOffset+=2;
										a->stackOffset = stackOffset;
										st->insert(a);
									} funcparams->setParameterList({});
									st->setStackOffset(0);
								}
#line 1842 "y.tab.c"
break;
#line 1844 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
