#pragma once
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;


class SymbolInfo{
public:
    SymbolInfo* next;
    string name;
    string type;
    string typeSpecifier;
    bool isToken;
    bool isArray;
    bool isFunction;
    bool isDeclared;
    bool isCond;
    vector<SymbolInfo*> children; 
    vector<SymbolInfo*> declarationlist; 
    vector<SymbolInfo*> parameterlist;
    int stackOffset;
    int arraySize;
    bool isGlobal;
    string lTrue;
    string lFalse;
    string lEnd;
    string rule;


    SymbolInfo(){
        isToken = false;
        this->isArray = false;
        this->isDeclared = false;
        this->isFunction = false;
    }

    SymbolInfo(string name, string type, string typeSpecifier, vector<SymbolInfo*> SI){
        this->name = name;
        this->type = type;
        this->typeSpecifier = typeSpecifier;
        this->next = nullptr;
        this->isArray = false;
        this->isDeclared = false;
        this->isFunction = false;
        isToken = false;
        isCond = false;
        lEnd = "";
        lTrue = "";
        lFalse = "";

        for(auto si: SI){
            children.push_back(si);
        }
    }

    SymbolInfo(string name, string type){
        this->name = name;
        this->type = type;
        this->next = nullptr;
        isToken = false;
        this->isArray = false;
        this->isDeclared = false;
        this->isFunction = false;
    }

    SymbolInfo(SymbolInfo* symbol){
        this->name = symbol->name;
        this->type = symbol->type;
        this->next = symbol->next;
    }

    void MakeRule(string rule){
        this->rule=rule;
    }

    string getName(){
        return name;
    }
    string getType(){
        return type;
    }
    SymbolInfo* getNext(){
        return this->next;
    }
    vector<SymbolInfo*> getExpansion(){
        return children;
    }
    bool getIsToken(){
        return isToken;
    }
    bool getIsArray(){
        return isArray;
    }
    bool getIsFunction(){
        return isFunction;
    }
    bool getIsDeclared(){
        return isDeclared;
    }
    string getTypeSpecifier(){
        return typeSpecifier;
    }
    vector<SymbolInfo*> getDeclarationList(){
        return declarationlist;
    }
    vector<SymbolInfo*> getParameterList(){
        return parameterlist;
    }

    void setName(string s){
        name = s;
        return;
    }
    void setType(string s){
        type = s;
        return;
    }
    void setNext(SymbolInfo* next){
        this->next = next;
    }
    void addExpansion(vector<SymbolInfo*> SI){
        for(auto si: SI){
            children.push_back(si);
        }
    }
    void setIsToken(bool b){
        isToken = b;
    }
    void setIsArray(bool b){
        isArray = b;
    }
    void setIsFunction(bool b){
        isDeclared = b;
        isFunction = b;
    }
    void setIsDeclared(bool b){
        isDeclared = b;
    }
    void setTypeSpecifier(string typeSpecifier){
        this->typeSpecifier = typeSpecifier;
    }
    void setDeclarationList(vector<SymbolInfo*> SI){
        declarationlist = SI;
    }
    void pushDeclaration(SymbolInfo* si){
        declarationlist.push_back(si);
    }
    void setParameterList(vector<SymbolInfo*> SI){
        parameterlist = SI;
    }
    void addParameter(SymbolInfo* si){
        parameterlist.push_back(si);
    }

    void printParseTree(ostream& os){
       
        os<< type<< " : ";

        for(SymbolInfo* si : children){
            os<< si->type<< " ";
        }
        if(children.size()==0) os<< name<< " ";
        os<< "\n";
        for(SymbolInfo* si : children){
            si->printParseTree(os);
        }
    }

    string getStatement(){
        if(isToken) return name;
        string a = "";
        for(auto b : children){
            a+=b->getStatement();
        }
        return a;
    }


    friend ostream& operator<<(ostream& os, const SymbolInfo& dt);
    ~SymbolInfo(){
        delete next;
    }

    string getRule(){
        string g = type + " :";
        for(auto s : children){
            g+=" "+s->type;
        }
        return g;
    }
   

    string getOpcode(string op){
        string opcode = "";
        if(op == "<") opcode ="\tJL";
        else if(op == ">") opcode ="\tJG";
        else if(op == ">=") opcode ="\tJGE";
        else if(op == "<=") opcode ="\tJLE";
        else if(op == "==") opcode ="\tJE";
        else if(op == "!=") opcode ="\tJNE";
        return opcode;
    }

    string newLabel(){
        string h = to_string(labelCnt++);
        h = "L"+h;
        return h;
    }

    string newTem(){
        string h = to_string(tempCnt++);
        h = "t"+h;
        return h;
    }

   
    

    void codeGeneration( ostream& os){
        if(getRule()=="start : program"){
            string newLineProc = "NEWLINE PROC\n\tPUSH AX\n\tPUSH DX\n\tMOV AH,2\n\tMOV DL,CR\n\tINT 21H\n\tMOV AH,2\n\tMOV DL,LF\n\tINT 21H\n\tPOP DX\n\tPOP AX\n\tRET\nNEWLINE ENDP\n";
            string printOutputProc = "PRINTNUMBER PROC  ;PRINT WHAT IS IN AX\n\tPUSH AX\n\tPUSH BX\n\tPUSH CX\n\tPUSH DX\n\tPUSH SI\n\tLEA SI,NUMBER\n\tMOV BX,10\n\tADD SI,4\n\tCMP AX,0\n\tJNGE NEGATE\n\tPRINT:\n\tXOR DX,DX\n\tDIV BX\n\tMOV [SI],DL\n\tADD [SI],'0'\n\tDEC SI\n\tCMP AX,0\n\tJNE PRINT\n\tINC SI\n\tLEA DX,SI\n\tMOV AH,9\n\tINT 21H\n\tPOP SI\n\tPOP DX\n\tPOP CX\n\tPOP BX\n\tPOP AX\n\tRET\n\tNEGATE:\n\tPUSH AX\n\tMOV AH,2\n\tMOV DL,'-'\n\tINT 21H\n\tPOP AX\n\tNEG AX\n\tJMP PRINT\nPRINTNUMBER ENDP\n";
            string header = ";-------\n;\n;-------\n.MODEL SMALL\n.STACK 1000H\n.DATA\n\tCR EQU 0DH\n\tLF EQU 0AH\n\tNUMBER DB \"00000$\"\n";
            os<< header;
            for(int i=0; i<globalVars.size(); i++){
                if(globalVars[i]->isArray){
                    os<< "\t"<< globalVars[i]->name<< " DW "<< globalVars[i]->arraySize<< " DUP (0000H)\n";
                }
                else{
                    os<< "\t"<< globalVars[i]->name<< " DW 1 DUP (0000H)\n";
                }
            }
            os<< ".CODE\n";
            children[0]->codeGeneration(os);
            os<< newLineProc;
            os<< printOutputProc;
            os<< "END main\n";
        }
        if(getRule()=="program : program unit"){
            children[0]->codeGeneration(os);
            children[1]->codeGeneration(os);
        }
        if(getRule()=="program : unit"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="unit : var_declaration"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="unit : func_declaration"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="unit : func_definition"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"){
            children[0]->codeGeneration(os);
            children[3]->codeGeneration(os);
        }
        if(getRule()=="func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"){
            children[0]->codeGeneration(os);
            children[3]->codeGeneration(os);
            os<< name<< " PROC\n";
            if(name == "main"){
                os<< "\tMOV AX, @DATA\n";
                os<< "\tMOV DS, AX\n";
            }
            os<< "\tPUSH BP\n";
            os<< "\tMOV BP, SP\n";
            children[5]->codeGeneration(os);
            os<< name<< "_exit:\n";
            if(name == "main"){
                os<< "\tMOV AX, 4CH\n";
                os<< "\tINT 21H\n";
            }
            os<< "\tADD SP, "<< -children[5]->stackOffset<< endl;
            os<< "\tPOP BP\n";
            if(name != "main"){
                os<< "\tRET\n";
            }
            os<< name<< " ENDP\n";
        }
        if(getRule()=="func_definition : type_specifier ID LPAREN RPAREN compound_statement"){
            children[0]->codeGeneration(os);
            os<< name<< " PROC\n";
            if(name == "main"){
                os<< "\tMOV AX, @DATA\n";
                os<< "\tMOV DS, AX\n";
            }
            os<< "\tPUSH BP\n";
            os<< "\tMOV BP, SP\n";
            children[4]->codeGeneration(os);
            os<< name<< "_exit:\n";
            if(name == "main"){
                os<< "\tMOV AX, 4CH\n";
                os<< "\tINT 21H\n";
            }
            os<< "\tADD SP, "<< -children[4]->stackOffset<< endl;
            os<< "\tPOP BP\n";
            os<< name<< " ENDP\n";
        }
        if(getRule()=="parameter_list : parameter_list COMMA type_specifier ID"){
            children[0]->codeGeneration(os);
            children[2]->codeGeneration(os);
        }
        if(getRule()=="parameter_list : parameter_list COMMA type_specifier"){
            children[0]->codeGeneration(os);
            children[2]->codeGeneration(os);
        }
        if(getRule()=="parameter_list : type_specifier ID"){
            children[0]->codeGeneration(os);
            children[1]->codeGeneration(os);
        }
        if(getRule()=="parameter_list : type_specifier"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="compound_statement : LCURL statements RCURL"){
            if(lEnd=="") lEnd = newLabel();
            children[1]->lEnd = lEnd;
            children[1]->codeGeneration(os);
        }
        if(getRule()=="var_declaration : type_specifier declaration_list SEMICOLON"){
            children[0]->codeGeneration(os);
            children[1]->codeGeneration(os);
            for(int i= 0; i<children[1]->declarationlist.size(); i++){
                if(isGlobal);
                else{
                    if(children[1]->declarationlist[i]->isArray) os<< "\tSUB SP, "<< to_string(2*children[1]->declarationlist[i]->arraySize)<< "\n";
                    else os<< "\tSUB SP, 2\n";
                }
            }
        }
        if(getRule()=="statements : statement"){
            children[0]->lEnd = lEnd;
            children[0]->codeGeneration(os);
            os<< lEnd<< ":\n";
        }
        if(getRule()=="statements : statements statement"){
            children[0]->lEnd = newLabel();
            children[1]->lEnd = lEnd;
            children[0]->codeGeneration(os);
            children[1]->codeGeneration(os);
            os<< lEnd<< ":\n";
        }
        if(getRule()=="statement : var_declaration"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="statement : expression_statement"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="statement : compound_statement"){
            children[0]->lEnd = newLabel();
            children[0]->codeGeneration(os);
        }
        if(getRule()=="statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"){
            children[2]->codeGeneration(os);
            string loop = newLabel();
            os<< loop<< ":\n";
            children[3]->isCond = true;
            children[3]->lTrue = newLabel();
            children[3]->lFalse = lEnd;
            children[6]->lEnd = newLabel();
            children[3]->codeGeneration(os);
            os<< children[3]->lTrue<< ":\n";
            children[6]->codeGeneration(os);
            children[4]->codeGeneration(os);
            os<< "\tJMP "<< loop<< "\n";
        }
        if(getRule()=="statement : IF LPAREN expression RPAREN statement"){
            children[2]->isCond = true;
            children[2]->lTrue = newLabel();
            children[2]->lFalse = lEnd;
            children[4]->lEnd = lEnd;
            children[2]->codeGeneration(os);
            os<< children[2]->lTrue<< ":\n";
            children[4]->codeGeneration(os);
        }
        if(getRule()=="statement : IF LPAREN expression RPAREN statement ELSE statement"){
            children[2]->isCond = true;
            children[2]->lTrue = newLabel();
            children[2]->lFalse = newLabel();
            children[4]->lEnd = children[2]->lFalse;
            children[6]->lEnd = lEnd;
            children[2]->codeGeneration(os);
            os<< children[2]->lTrue<< ":\n";
            children[4]->codeGeneration(os);
            os<< "\tJMP "<< lEnd<< "\n";
            os<< children[2]->lFalse<< ":\n";
            children[6]->codeGeneration(os);
        }
        if(getRule()=="statement : WHILE LPAREN expression RPAREN statement"){
            string loop = newLabel();
            children[2]->isCond = true;
            children[2]->lTrue = newLabel();
            children[2]->lFalse = lEnd;
            children[4]->lEnd = lEnd;
            os<< loop<< ":\n";
            children[2]->codeGeneration(os);
            os<< children[2]->lTrue<< ":\n";
            children[4]->codeGeneration(os);
            os<< "\tJMP "<< loop<< "\n";
        }
        if(getRule()=="statement : PRINTLN LPAREN ID RPAREN SEMICOLON"){
            if(isGlobal){
                os<< "\tMOV AX, "+ children[2]->name +"\n";
                os<< "\tCALL PRINTNUMBER\n";
                os<< "\tCALL NEWLINE\n";
            }
            else{
                os<< "\tPUSH BP\n";
                os<< "\tMOV BX, "<< to_string(stackOffset)<< "\n";
                os<< "\tADD BP, BX\n";
                os<< "\tMOV AX, [BP]\n";
                os<< "\tCALL PRINTNUMBER\n";
                os<< "\tCALL NEWLINE\n";
                os<< "\tPOP BP\n";
            }
        }
        if(getRule()=="statement : RETURN expression SEMICOLON"){
            children[1]->codeGeneration(os);
		    os<< "\tMOV DX,CX\n";
            os<< "\tJMP "<< children[0]->name<< "_exit\n";
        }
        if(getRule()=="expression_statement : expression SEMICOLON"){
            children[0]->isCond = isCond;
            children[0]->lTrue = lTrue;
            children[0]->lFalse = lFalse;
            children[0]->codeGeneration(os);
        }
        if(getRule()=="variable : ID"){
            if(isGlobal);
            else{
                os<< "\tPUSH BP\n";
                os<< "\tMOV BX, "<< to_string(stackOffset)<< "\n";
                os<< "\tADD BP, BX\n";
            }
        }
        if(getRule()=="variable : ID LTHIRD expression RTHIRD"){
            children[2]->codeGeneration(os);
            if(!isGlobal){
                os<< "\tPUSH BP\n";
                os<< "\tMOV BX, CX\n";
                os<< "\tADD BX, BX\n";
                os<< "\tADD BX, "<< to_string(stackOffset)<< "\n";
                os<< "\tADD BP, BX\n";
            }
            else{
                os<< "\tLEA SI, "<< children[0]->name<< "\n";
                os<< "\tADD SI, CX\n";
                os<< "\tADD SI, CX\n";
                os<< "\tPUSH BP\n";
                os<< "\tMOV BP, SI\n";
            }
        }
        if(getRule()=="expression : logic_expression"){
            children[0]->isCond = isCond;
            children[0]->lTrue = lTrue;
            children[0]->lFalse = lFalse;
            children[0]->codeGeneration(os);
        }
        if(getRule()=="expression : variable ASSIGNOP logic_expression"){ //no more condition propagation
            children[2]->codeGeneration(os);
            children[0]->isCond = false;
            children[2]->isCond = false;
            if(children[0]->isGlobal && !children[0]->isArray){
                children[0]->codeGeneration(os);
                os<< "\tMOV "+children[0]->name<< ", CX\n";
            }
            else{
                os<< "\tPUSH CX\n";
                children[0]->codeGeneration(os);
                
                os<< "\tPOP AX\n";
                os<< "\tPOP CX\n";
                os<< "\tMOV [BP], CX\n";
                os<< "\tMOV BP, AX\n";
            }
            if(isCond) os<< "\tJMP "<< lTrue<< "\n";
        }
        if(getRule()=="logic_expression : rel_expression"){
            children[0]->isCond = isCond;
            children[0]->lTrue = lTrue;
            children[0]->lFalse = lFalse;
            children[0]->codeGeneration(os);
        }
        if(getRule()=="logic_expression : rel_expression LOGICOP rel_expression"){
            children[0]->isCond = isCond;
            children[2]->isCond = isCond;
            if(children[1]->name == "||"){
                children[0]->lTrue = lTrue;
                children[0]->lFalse = newLabel()+"jmpfalse";
                children[2]->lTrue = lTrue;
                children[2]->lFalse = lFalse;
            }
            else{
                children[0]->lTrue = newLabel()+"jmptrue";
                children[0]->lFalse = lFalse;
                children[2]->lTrue = lTrue;
                children[2]->lFalse = lFalse;
            }
            children[0]->codeGeneration(os);
            if(isCond){
                if(children[1]->name == "||") os<< children[0]->lFalse<< ":\n"; 
                else  os<< children[0]->lTrue<< ":\n"; 
            }
            else os<< "\tPUSH CX\n";
            children[2]->codeGeneration(os);
            if(!isCond){
                os<< "\tPOP AX\n";
                if(children[1]->name=="||"){
                    string x = newLabel();
                    string y = newLabel();
                    string z = newLabel();
                    string a = newLabel();
                    os<< "\tCMP AX, 0\n";
                    os<< "\tJE "<< x<< "\n";
                    os<< "\tJMP "<< y<< "\n";
                    os<< x<< ":\n";
                    os<< "\tJCXZ "<< z<< " ;yay\n";
                    os<< y<< ":\n";
                    os<< "\tMOV CX, 1\n";
                    os<< "\tJMP "<< a<< ":\n";
                    os<< z<< ":\n";
                    os<< "\tMOV CX, 0\n";
                    os<< a<< ":\n";
                }
                else{
                    string x = newLabel();
                    string y = newLabel();
                    string z = newLabel();
                    os<< "\tCMP AX, 0\n";
                    os<< "\tJE "<< x<< "\n";
                    os<< "\tJCXZ "<< x<< " ;yay\n";
                    os<< "\tJMP "<< y<< "\n";
                    os<< x<< ":\n";
                    os<< "\tMOV CX, 0\n";
                    os<< "\tJMP "<< z<< ":\n";
                    os<< y<< ":\n";
                    os<< "\tMOV CX, 1\n";
                    os<< z<< ":\n";
                }
            }
        }
        if(getRule()=="rel_expression : simple_expression"){
            children[0]->isCond = isCond;
            children[0]->lTrue = lTrue ;
            children[0]->lFalse = lFalse ;
            children[0]->codeGeneration(os);
        }
        if(getRule()=="rel_expression : simple_expression RELOP simple_expression"){ //cond propagation ends;
            children[0]->codeGeneration(os);
            os<< "\tPUSH CX\n";
            children[2]->codeGeneration(os);
            string opcode = getOpcode(children[1]->name);
            os<< "\tPOP AX\n";
            os<< "\tCMP AX, CX\n";
            if(lTrue == "") lTrue = newLabel();
            if(lFalse == "") lFalse = newLabel();
            os<< opcode + " " + lTrue +"\n";
            os<< "\tJMP "+lFalse+"\n";
            if(!isCond){
                os<< lTrue<< ":\n";
                os<< "\tMOV CX, 1\n";
                string leave = newLabel();
                os<< "\tJMP "<< leave<< "\n";
                os<< lFalse<< ":\n";
                os<< "\tMOV CX, 0\n";
                os<< leave<< ":\n";
            }
        }
        if(getRule()=="simple_expression : term"){
            children[0]->isCond = isCond;
            children[0]->lTrue = lTrue ;
            children[0]->lFalse = lFalse ;
            children[0]->codeGeneration(os);
        }
        if(getRule()=="simple_expression : simple_expression ADDOP term"){//cond propagation ends
            children[0]->codeGeneration(os);
            os<< "\tPUSH CX\n";
            children[2]->codeGeneration(os);
            os<< "\tPOP AX\n";
            if(children[1]->name=="+") os<< "\tADD CX, AX\n";
            if(children[1]->name=="-") os<< "\tSUB AX, CX\n\tMOV CX, AX\n";
            if(isCond){
                os<< "\tJCXZ "<< lFalse<< "\n";
                os<< "\tJMP "<< lTrue<< "\n";
            }
        }
        if(getRule()=="term : unary_expression"){
            children[0]->isCond = isCond;
            children[0]->lTrue = lTrue ;
            children[0]->lFalse = lFalse ;
            children[0]->codeGeneration(os);  
        }
        if(getRule()=="term : term MULOP unary_expression"){//cond propagation ends
            children[0]->codeGeneration(os);
            os<< "\tPUSH CX\n";
            children[2]->codeGeneration(os);
            os<< "\tPOP AX\n";
            if(children[1]->name=="*"){
                os<< "\tIMUL CX\n";
                os<< "\tMOV CX, AX\n";
            }
            else if(children[1]->name=="/"){
                os<< "\tCWD\n";
                os<< "\tIDIV CX\n";
                os<< "\tMOV CX, AX\n";
            }
            else if(children[1]->name=="%"){
                os<< "\tCWD\n";
                os<< "\tIDIV CX\n";
                os<< "\tMOV CX, DX\n";
            }
            if(isCond){
                os<< "\tJCXZ "<< lFalse<< "\n";
                os<< "\tJMP "<< lTrue<< "\n";
            }
        }
        if(getRule()=="unary_expression : ADDOP unary_expression"){
            children[1]->isCond = isCond;
            children[1]->lTrue = lTrue ;
            children[1]->lFalse = lFalse ;
            children[1]->codeGeneration(os);
            if(children[0]->name=="-"){
                os<< "\tNEG CX\n";
            }
        }
        if(getRule()=="unary_expression : NOT unary_expression"){
            children[1]->isCond = isCond;
            children[1]->lTrue = lFalse ;
            children[1]->lFalse = lTrue ;
            children[1]->codeGeneration(os);
            if(!isCond){
                string l0 = newLabel();
                string l1 = newLabel();
                os<< "\tJCXZ "+l1+"\n";
                os<< "\tMOV CX,0\n";
                os<< "\tJMP "<< l0<< "\n"; 
                os<< l1+":\n";
                os<< "\tMOV CX,1\n";
                os<< l0+":\n";
            }
        }
        if(getRule()=="unary_expression : factor"){
            children[0]->isCond = isCond;
            children[0]->lTrue = lTrue ;
            children[0]->lFalse = lFalse ;
            children[0]->codeGeneration(os);
            
        }
        if(getRule()=="factor : variable"){
            children[0]->codeGeneration(os);
            if(children[0]->isGlobal && !children[0]->isArray){
                if(!children[0]->isArray) os<< "\tMOV CX, "<< children[0]->name<< "\n";
            }
            else{
                os<< "\tMOV CX, [BP]\n";
                os<< "\tPOP BP\n";
            }
            if(isCond){
                os<< "\tJCXZ "<< lFalse<< "\n";
                os<< "\tJMP "<< lTrue<< "\n";
            }
        }
        if(getRule()=="factor : ID LPAREN argument_list RPAREN"){
            children[0]->codeGeneration(os);
            children[2]->codeGeneration(os);
            os<< "\tCALL "+children[0]->name+"\n";
            os<< "\tMOV CX, DX\n";
            os<< "\tADD SP, "<< children[2]->stackOffset<< "\n";
            if(isCond){
                os<< "\tJCXZ "<< lFalse<< "\n";
                os<< "\tJMP "<< lTrue<< "\n";
            }
            
        }
        if(getRule()=="factor : LPAREN expression RPAREN"){
            children[1]->codeGeneration(os);
            if(isCond){
                os<< "\tJCXZ "<< lFalse<< "\n";
                os<< "\tJMP "<< lTrue<< "\n";
            }
        }
        if(getRule()=="factor : CONST_INT"){
            children[0]->codeGeneration(os);
            os<< "\tMOV CX, "+name+"\n";
            if(isCond){
                os<< "\tJCXZ "<< lFalse<< "\n";
                os<< "\tJMP "<< lTrue<< "\n";
            }
        }
        if(getRule()=="factor : CONST_FLOAT"){
            children[0]->codeGeneration(os);
            os<< "\tMOV CX, "+name+"\n";
            if(isCond){
                os<< "\tJCXZ "<< lFalse<< "\n";
                os<< "\tJMP "<< lTrue<< "\n";
            } 
        }
        if(getRule()=="factor : variable INCOP"){
            children[0]->codeGeneration(os);
            if(children[0]->isGlobal && !children[0]->isArray) os<< "\tMOV CX, "<< children[0]->name<< "\n";
            else os<< "\tMOV CX, [BP]\n";
            os<< "\tMOV AX, CX\n";
            if(children[1]->name=="++") os<< "\tINC CX\n";
            if(children[1]->name=="--") os<< "\tDEC CX\n";
            
            if(children[0]->isGlobal) os<< "\tMOV "<< children[0]->name<< ", CX\n";
            else{
                os<< "\tMOV [BP], CX\n";
                os<< "\tPOP BP\n";
            }
            os<< "\tMOV CX, AX\n";
            if(isCond){
                os<< "\tJCXZ "<< lFalse<< "\n";
                os<< "\tJMP "<< lTrue<< "\n";
            }
        }
        if(getRule()=="argument_list : arguments"){
            children[0]->codeGeneration(os);
        }
        if(getRule()=="arguments : arguments COMMA logic_expression"){
            children[0]->codeGeneration(os);
            children[2]->codeGeneration(os);
            os<< "\tPUSH CX ;func param\n";
        }
        if(getRule()=="arguments : logic_expression"){
            children[0]->codeGeneration(os);
            os<< "\tPUSH CX ;func param\n";
        }
    }
    static int labelCnt;
    static int tempCnt;
    static vector<SymbolInfo*> globalVars;
};
