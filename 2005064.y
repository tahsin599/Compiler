%{
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


%}


%union{
    SymbolInfo* si; 
}

%token<si> NEWLINE CONST_FLOAT CONST_INT CONST_CHAR IF LOWER_THAN_ELSE FOR DO INT FLOAT VOID SWITCH DEFAULT ELSE WHILE BREAK CHAR DOUBLE RETURN CASE CONTINUE PRINTLN ADDOP MULOP INCOP RELOP ASSIGNOP LOGICOP BITOP NOT LPAREN RPAREN LTHIRD RTHIRD LCURL RCURL COMMA SEMICOLON ID
%type<si> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments LCURL_ error

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

start			: program		{
									$$ = new SymbolInfo("","start","",{$1});
									$$->MakeRule("start : program");
									
				                    $$->globalVars=globalVariables;
									root=$$;
									
									
									
								}
				;
program 		: program unit	{$$ = new SymbolInfo("","program","",{$1,$2});
                                
								 $$->MakeRule("program : program unit");
                                                                 
								
				} 
				| unit			{$$ = new SymbolInfo("","program","",{$1});
				                $$->MakeRule("program : unit");

				} 
				;
unit 			: var_declaration	{$$ = new SymbolInfo($1->name,"unit","",{$1});
                                     $$->MakeRule("unit : var_declaration");
                }
				| func_declaration	{$$ = new SymbolInfo($1->name,"unit","",{$1});
				                     $$->MakeRule("unit : func_declaration");
				}
				| func_definition	{$$ = new SymbolInfo($1->name,"unit","",{$1});
				                     $$->MakeRule("unit : func_definition");
				                     
				}
				;	
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON	{ 
									$$ = new SymbolInfo($2->name,"func_declaration","",{$1,$2,$3,$4,$5,$6}); 
									$$->MakeRule("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
									$2->setTypeSpecifier($1->typeSpecifier); 
									$2->setIsDeclared(true); 
									$2->setParameterList($4->parameterlist); 
									funcparams->setParameterList({}); 
									st->insert($2); 
								}
				| type_specifier ID LPAREN RPAREN SEMICOLON	{ 
									$$ = new SymbolInfo($2->name,"func_declaration","",{$1,$2,$3,$4,$5}); 
									$$->MakeRule("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
									$2->setTypeSpecifier($1->typeSpecifier); 
									$2->setIsDeclared(true); 
									st->insert($2); 
								}
				;
func_definition	: type_specifier ID LPAREN parameter_list RPAREN { InsertIntoScope($2,$1); } compound_statement	{ $$ = new SymbolInfo($2->name,"func_definition","",{$1,$2,$3,$4,$5,$7});$$->MakeRule("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");}
				| type_specifier ID LPAREN RPAREN { InsertIntoScope($2,$1); } compound_statement	{ $$ = new SymbolInfo($2->name,"func_definition","",{$1,$2,$3,$4,$6});$$->MakeRule("func_definition : type_specifier ID LPAREN RPAREN compound_statement");}
				;
parameter_list	: parameter_list COMMA type_specifier ID	{
									$$ = new SymbolInfo("","parameter_list","",{$1,$2,$3,$4});
									$$->MakeRule("parameter_list : parameter list COMMA type_specifier ID");
									$$->setParameterList($1->parameterlist); 
									$$->addParameter($4); 
									$4->setTypeSpecifier($3->typeSpecifier); 
									funcparams->setParameterList($$->parameterlist); 
								}
				| parameter_list COMMA type_specifier	{ 
									$$ = new SymbolInfo("","parameter_list","",{$1,$2,$3}); 
									$$->MakeRule("parameter_list : parameter_list COMMA type_specifier");
									SymbolInfo* body = new SymbolInfo("","ID"); 
									$$->setParameterList($1->parameterlist); 
									$$->addParameter(body);  
									body->setTypeSpecifier($3->typeSpecifier); 
									funcparams->setParameterList($$->parameterlist); 
								}
				| type_specifier ID	{ 
									$$ = new SymbolInfo("","parameter_list","",{$1,$2});
									$$->MakeRule("parameter_list : type_specifier ID");
									$2->setTypeSpecifier($1->typeSpecifier); 
									$$->addParameter($2); 
									funcparams->setParameterList($$->parameterlist); 
								}
				| type_specifier{ 
									$$ = new SymbolInfo("","parameter_list","",{$1});
									$$->MakeRule("parameter_list : type_specifier");
									SymbolInfo* body = new SymbolInfo("","ID"); 
									body->setTypeSpecifier($1->typeSpecifier); 
									$$->addParameter(body); 
									funcparams->setParameterList($$->parameterlist); 
								}
				;

compound_statement: LCURL_ statements RCURL	{
									$$ = new SymbolInfo($2->name,"compound_statement","",{$1,$2,$3});
									$$->MakeRule("compound_statement : LCURL statements RCURL");
									$$->stackOffset = st->getStackOffset();
									st->exitScope();
								}
 		    	| LCURL_ RCURL	{
									$$ = new SymbolInfo("","compound_statement","",{$1,$2});
									$$->MakeRule("compound_statement : LCURL RCURL");
									$$->stackOffset = st->getStackOffset();
									st->exitScope();
								}
 		    	;	
var_declaration	: type_specifier declaration_list SEMICOLON		{
									$$ = new SymbolInfo("","var_declaration","",{$1,$2,$3});
									$$->MakeRule("var_declaration : type_specifier declaration_list SEMICOLON");
									if(st->getID()==1) $$->isGlobal = true;
									else $$->isGlobal = false;
									for(int i=0; i<$2->declarationlist.size(); i++){
										auto a = $2->declarationlist[i];
										a->setTypeSpecifier($1->typeSpecifier);
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
 		 		;
type_specifier	: INT			{$$ = new SymbolInfo($1->name,"type_specifier",$1->typeSpecifier,{$1});$$->MakeRule("type_specifier : INT");}
				| FLOAT			{$$ = new SymbolInfo($1->name,"type_specifier",$1->typeSpecifier,{$1});$$->MakeRule("type_specifier : FLOAT");}
				| VOID			{$$ = new SymbolInfo($1->name,"type_specifier",$1->typeSpecifier,{$1});$$->MakeRule("type_specifier : VOID");}
				;
declaration_list	: declaration_list COMMA ID	{
									$$ = new SymbolInfo("","declaration_list","",{$1,$2,$3});
									$$->MakeRule("declaration_list : declaration_list COMMA ID");
									$$->setDeclarationList($1->declarationlist);
									$$->pushDeclaration($3);
								}
				| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD	{
									$$ = new SymbolInfo("","declaration_list","",{$1,$2,$3,$4,$5,$6});
									$$->MakeRule("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
									$$->setDeclarationList($1->declarationlist);
									$3->setIsArray(true);
									string s = $5->name;
									istringstream is(s);
									int i;
									is >> i;
									$3->arraySize = i;
									
									$$->pushDeclaration($3);
								}
				| ID			{
									$$ = new SymbolInfo("","declaration_list","",{$1});
									$$->MakeRule("declaration_list : ID");
									$$->pushDeclaration($1);
								}
				| ID LTHIRD CONST_INT RTHIRD	{
									$$ = new SymbolInfo("","declaration_list","",{$1,$2,$3,$4});
									$$->MakeRule("declaration_list : ID LTHIRD CONST_INT RTHIRD");
									$1->setIsArray(true);
									string s = $3->name;
									istringstream is(s);
									int i;
									is >> i;
									$1->arraySize = i;	
									cout<< $1->name<< " yay\n";				
									$$->pushDeclaration($1);
								}
				;
statements		: statement		{$$ = new SymbolInfo($1->name,"statements","",{$1});$$->MakeRule("statements : statement");}
				| statements statement	{$$ = new SymbolInfo($1->name,"statements","",{$1,$2});$$->MakeRule("statements : statements statement");}
				;
statement		: var_declaration	{$$ = new SymbolInfo($1->name,"statement","",{$1});$$->MakeRule("statement : var_declaration");}
				| expression_statement	{$$ = new SymbolInfo($1->name,"statement","",{$1});$$->MakeRule("statement : expression_statement");}
				| compound_statement	{$$ = new SymbolInfo($1->name,"statement","",{$1});$$->MakeRule("statement : compound_statement");}
				|  FOR LPAREN expression_statement expression_statement expression RPAREN statement	{
									$$ = new SymbolInfo($1->name,"statement","",{$1,$2,$3,$4,$5,$6,$7});
									$$->MakeRule("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
								}
				|  IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
									$$ = new SymbolInfo($1->name,"statement","",{$1,$2,$3,$4,$5});
									$$->MakeRule("statement : IF LPAREN expression RPAREN statement");
								}
				|  IF LPAREN expression RPAREN statement ELSE statement {
									$$ = new SymbolInfo($1->name,"statement","",{$1,$2,$3,$4,$5,$6,$7});
									$$->MakeRule("statement : IF LPAREN expression RPAREN statement ELSE statement");
								}
				| WHILE LPAREN expression RPAREN statement	{
									$$ = new SymbolInfo($1->name,"statement","",{$1,$2,$3,$4,$5});
									$$->MakeRule("statement : WHILE LPAREN expression RPAREN statement");
								}
				| PRINTLN LPAREN ID RPAREN SEMICOLON	{
									$$ = new SymbolInfo($1->name,"statement","",{$1,$2,$3,$4,$5});
									$$->MakeRule("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
									auto a = st->lookUp($3->name);
									$$->stackOffset = a->stackOffset;
									if(a->isGlobal) $$->isGlobal = true;
									else $$->isGlobal = false;
								}
				| RETURN expression SEMICOLON	{
									$$ = new SymbolInfo($1->name,"statement","",{$1,$2,$3});
									$$->MakeRule("statement : RETURN expression SEMICOLON");
									$1->name = currFunc;
								}
				;
expression_statement: SEMICOLON	{$$ = new SymbolInfo("","expression_statement","",{$1});$$->MakeRule("expression_statement : SEMICOLON");}
				| expression SEMICOLON		{$$ = new SymbolInfo($1->name,"expression_statement",$1->typeSpecifier,{$1,$2});$$->MakeRule("expression_statement : expression SEMICOLON");}
				;		
variable		: ID			{
									SymbolInfo* a = st->lookUp($1->name);
									$$->MakeRule("variable : ID");
									$$ = new SymbolInfo($1->name,"variable",a->typeSpecifier,{$1});
									$$->setIsArray(a->isArray);
									$$->stackOffset = a->stackOffset;
									$$->isGlobal = a->isGlobal;
								}
				| ID LTHIRD expression RTHIRD	{
									SymbolInfo* a = st->lookUp($1->name);
									$$->MakeRule("variable : ID LTHIRD expression RTHIRD");
									$$ = new SymbolInfo($1->name,"variable",a->typeSpecifier,{$1,$2,$3,$4});
									$$->setIsArray(a->isArray);
									$$->stackOffset = a->stackOffset;
									$$->isGlobal = a->isGlobal;
								}
				;
expression		: logic_expression		{$$ = new SymbolInfo($1->name,"expression","",{$1});$$->MakeRule("expression : logic_expression");}
				| variable ASSIGNOP logic_expression {$$ = new SymbolInfo($1->name,"expression","",{$1,$2,$3});$$->MakeRule("expression : variable ASSIGNOP logic_expression");}
				;	
logic_expression	: rel_expression		{
									$$ = new SymbolInfo($1->name,"logic_expression",$1->typeSpecifier,{$1});
									$$->MakeRule("logic_expression : rel_expression");
									$$->setIsArray($1->isArray);
								}
				| rel_expression LOGICOP rel_expression	{$$ = new SymbolInfo($1->name,"logic_expression","INT",{$1,$2,$3});$$->MakeRule("logic_expression : rel_expression LOGICOP rel_expression");}
				;		
rel_expression	: simple_expression		{
									$$ = new SymbolInfo($1->name,"rel_expression",$1->typeSpecifier,{$1});
									$$->MakeRule("rel_expression : simple_expression");
									$$->setIsArray($1->isArray);
								}
				| simple_expression RELOP simple_expression	{$$ = new SymbolInfo($1->name,"rel_expression","INT",{$1,$2,$3});$$->MakeRule("rel_expression : simple_expression RELOP simple_expression");}
				;	
simple_expression: term		{
									$$ = new SymbolInfo($1->name,"simple_expression",$1->typeSpecifier,{$1});
									$$->MakeRule("simple_expression : term");
									$$->setIsArray($1->isArray);
								}
				| simple_expression ADDOP term {$$ = new SymbolInfo($1->name,"simple_expression",typeCast($1,$3),{$1,$2,$3});$$->MakeRule("simple_expression : simple_expression ADDOP term");}
				;
term			: unary_expression		{
									$$ = new SymbolInfo($1->name,"term",$1->typeSpecifier,{$1});
									$$->MakeRule("term : unary_expression");
									$$->setIsArray($1->isArray);
								}
				| term MULOP unary_expression {$$ = new SymbolInfo($1->name,"term",typeCast($1,$3),{$1,$2,$3});$$->MakeRule("term : term MULOP unary_expression");}
				;			
unary_expression: ADDOP unary_expression	{$$ = new SymbolInfo($2->name,"unary_expression",$2->typeSpecifier,{$1,$2});$$->MakeRule("unary_expression : ADDOP unary_expression");}
				| NOT unary_expression{$$ = new SymbolInfo($2->name,"unary_expression","INT",{$1,$2});$$->MakeRule("unary_expression : NOT unary_expression");}
				| factor		{
									$$ = new SymbolInfo($1->name,"unary_expression",$1->typeSpecifier,{$1});
									$$->MakeRule("unary_expression : factor");
									$$->setIsArray($1->isArray);
								}
				;		
factor			: variable		{$$ = new SymbolInfo($1->name,"factor","",{$1});$$->MakeRule("factor : variable");}
				| ID LPAREN argument_list RPAREN	{
									auto a = st->lookUp($1->name);
									$$ = new SymbolInfo(ruleOf({$1,$2,$3,$4}),"factor",a->typeSpecifier,{$1,$2,$3,$4});
									$$->MakeRule("factor : ID LPAREN argument_list RPAREN");
									vector<SymbolInfo*> b = $3->parameterlist;
									vector<SymbolInfo*> c = a->parameterlist;
								}
				| LPAREN expression RPAREN	{$$ = new SymbolInfo($2->name,"factor",$2->typeSpecifier,{$1,$2,$3});$$->MakeRule("factor : LPAREN expression RPAREN");}
				| CONST_INT		{$$ = new SymbolInfo($1->name,"factor","INT",{$1});	$$->MakeRule("factor : CONST_INT");}
				| CONST_FLOAT	{$$ = new SymbolInfo($1->name,"factor","FLOAT",{$1});$$->MakeRule("factor : CONST_FLOAT");}
				| variable INCOP	{$$ = new SymbolInfo($1->name,"factor",$1->typeSpecifier,{$1,$2});$$->MakeRule("factor : variable INCOP");}
				;
	
argument_list	: arguments		{
									$$ = new SymbolInfo($1->name,"argument_list","",{$1});
									$$->MakeRule("argument_list : arguments");

									$$->setParameterList($1->parameterlist);
									$$->stackOffset = $1->stackOffset;
								}
				|				{$$ = new SymbolInfo("","argument_list","",{});}
				;
arguments		: arguments COMMA logic_expression	{
									$$ = new SymbolInfo($1->name,"arguments","",{$1,$2,$3});
									$$->MakeRule("arguments : arguments COMMA logic_expression");
									$$->setParameterList($1->parameterlist);
									$$->addParameter($3);
									$$->stackOffset = $1->stackOffset+2;
								}
				| logic_expression	{
									$$ = new SymbolInfo($1->name,"arguments","",{$1});
									$$->MakeRule("arguments : logic_expression");
									$$->addParameter($1);
									$$->stackOffset = 2;
								}
LCURL_			: LCURL			{
									$$ = $1; st->enterScope();
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
		
%%


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