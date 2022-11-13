%{
    #include <iostream>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>

    #include "ass5_20CS30062_20CS30043_translator.h"
    using namespace std;

    extern int yylex();
    extern int yylineno;
    void yyerror(string);
    extern char* yytext;
    extern string var_type; // store the last encountered variable type
%}

%union{
    int intval;
    float floatval;
    char charval;
    char* stringval;
    int instr;
    int func_param_cnt;
    symbol* sym_entry;
    symbol_type* sym_type;
    expression* expr;
    statement* stmnt;
    Arr* L;
}

/*TERMINAL SYMBOLS*/

/* attribute against an identifier is a the respective symbol table entry which is created immediately on 
encountering the identifier for the first time by the lexer*/
%token<sym_entry> IDENTIFIER 

/* attributes for the terminals specifying constants contain the respective constant values*/
%token<intval> INT_CONSTANT
%token<floatval> FLOAT_CONSTANT
%token<charval> CHAR_CONSTANT

/* all types of operators have attribute stringval which stores the respective lexeme */
%token<stringval> LEFT_ROUND_BRACKET
%token<stringval> RIGHT_ROUND_BRACKET
%token<stringval> STRING_LITERAL
%token<stringval> LEFT_SQUARE_BRACKET
%token<stringval> RIGHT_SQUARE_BRACKET
%token<stringval> DOT
%token<stringval> ARROW
%token<stringval> UNARY_INCREMENT
%token<stringval> UNARY_DECREMENT
%token<stringval> COMMA
%token<stringval> SIZEOF
%token<stringval> AMPERSAND
%token<stringval> ASTERISK
%token<stringval> PLUS
%token<stringval> MINUS
%token<stringval> TILDE
%token<stringval> EXCLAMATION
%token<stringval> DIVIDE
%token<stringval> PERCENT
%token<stringval> LEFT_SHIFT
%token<stringval> RIGHT_SHIFT
%token<stringval> LESS_THAN
%token<stringval> GREATER_THAN
%token<stringval> LESS_THAN_EQUAL  
%token<stringval> GREATER_THAN_EQUAL
%token<stringval> DOUBLE_EQUAL
%token<stringval> NOT_EQUAL
%token<stringval> PIPE
%token<stringval> CARET
%token<stringval> LOGICAL_AND
%token<stringval> LOGICAL_OR
%token<stringval> QUESTION
%token<stringval> COLON
%token<stringval> EQUAL
%token<stringval> ASTERISK_EQUAL
%token<stringval> DIVIDE_EQUAL
%token<stringval> PERCENT_EQUAL
%token<stringval> PLUS_EQUAL
%token<stringval> MINUS_EQUAL
%token<stringval> LEFT_SHIFT_EQUAL
%token<stringval> RIGHT_SHIFT_EQUAL
%token<stringval> AMPERSAND_EQUAL
%token<stringval> CARET_EQUAL
%token<stringval> PIPE_EQUAL
%token<stringval> SEMI_COLON
%token<stringval> EXTERN
%token<stringval> STATIC
%token<stringval> AUTO
%token<stringval> REGISTER
%token<stringval> VOID
%token<stringval> CHAR
%token<stringval> SHORT
%token<stringval> INT
%token<stringval> LONG
%token<stringval> FLOAT
%token<stringval> DOUBLE
%token<stringval> SIGNED
%token<stringval> UNSIGNED
%token<stringval> BOOL
%token<stringval> COMPLEX
%token<stringval> IMAGINARY
%token<stringval> ENUM
%token<stringval> CONST
%token<stringval> RESTRICT
%token<stringval> VOLATILE
%token<stringval> INLINE
%token<stringval> ELLIPSIS
%token<stringval> CASE
%token<stringval> DEFAULT
%token<stringval> LEFT_CURLY_BRACKET
%token<stringval> RIGHT_CURLY_BRACKET
%token<stringval> IF
%token<stringval> SWITCH
%token<stringval> WHILE
%token<stringval> DO
%token<stringval> FOR
%token<stringval> GOTO
%token<stringval> CONTINUE
%token<stringval> BREAK
%token<stringval> RETURN
%token UNKNOWN


/*NON-TERMINALS*/

%type <stringval> unary-operator

/*
the following attributes are for boolean expressions
truelist will be a list of jump or conditional jump instructions into which, we must insert the label to which control goes if the expression evaluates to true
falselist will be a list of jump or conditional jump instructions into which, we must insert the label to which control goes if the expression evaluates to true

for statements and non-boolean expressions
nextlist is a list of all conditional and unconditional jumps to the instruction following the code for that expression/statement  in execution order
*/

/*attributes of following expressions are of expression* type which gives information about
the type of the expression (Boolean/Non-boolean), pointer to symbol table entry, truelist, falselist and nextlist where
truelist, falselist and nextlist have standard meanings */
%type <expr> expression
%type <expr> primary-expression 
%type <expr> multiplicative-expression
%type <expr> additive-expression
%type <expr> shift-expression
%type <expr> relational-expression
%type <expr> equality-expression
%type <expr> AND-expression
%type <expr> exclusive-OR-expression
%type <expr> inclusive-OR-expression
%type <expr> logical-AND-expression
%type <expr> logical-OR-expression
%type <expr> conditional-expression
%type <expr> assignment-expression
%type <expr> expression-statement

/*attributes of the following are of statement* type which stores nextlist information where nextlist has standard meaning*/
%type <stmnt> statement
%type <stmnt> compound-statement
%type <stmnt> loop-statement
%type <stmnt> selection-statement
%type <stmnt> iteration-statement
%type <stmnt> labeled-statement 
%type <stmnt> jump-statement
%type <stmnt> block-item
%type <stmnt> block-item-list
%type <stmnt> block-item-list-opt

/*attribute stores number of parameters encounterd during preparation phase of calling a function*/
%type <func_param_cnt> argument-expression-list 
%type <func_param_cnt> argument-expression-list-opt

/*attribute used for retrieving type of pointer type expressions*/
%type <sym_type> pointer

/*following attributes store respective symbol table entries*/
%type <sym_entry> constant
%type <sym_entry> initializer
%type <sym_entry> direct-declarator
%type <sym_entry> init-declarator
%type <sym_entry> declarator

/* arrays and function calls are derived from the following non-terminals
   the Arr type attribute has the following attributes:
   category: differentiates between array and pointer types
   array_entry: pointer to symbol table entry of the respective array, needed for retrieving the base address while TAC generation
   addr: pointer to symbol table entry to temporary variable containing offset of the derived array expression from the array base address
   array_type: type of the array (array_type->arrType is the type of individual elements of the array)
*/
%type <L> postfix-expression
%type <L> unary-expression
%type <L> cast-expression

/*special marker non terminal*/
%type <instr> M /* stores intermediate line numbers midway down a production to be used for backpatching at the time reduction happens*/
%type <stmnt> N /* similar purpose as M with an additional use of generating a goto statement for exiting from the current block */

/* following attributes have no attributes, only required for creating new scopes for blocks, switching to nested tables and naming of the blocks*/
%type F W D X switch-table

%right THEN ELSE

%start translation-unit

%%

primary-expression:  IDENTIFIER
                        {
                            $$=new expression();  
                            $$->loc=$1;           
                            $$->expr_type="NORMAL";
                        }
                    | constant
                        {
                            $$ = new expression();
                            $$->loc = $1;
                        }
                    | STRING_LITERAL
                        {
                            $$ = new expression();
                            $$->loc = symbol_table::gentemp(new symbol_type("ptr"), $1);
                            $$->loc->type->arrType = new symbol_type("char");
                            
                        }
                    | LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET
                        {
                            $$ = $2;
                        }
                    ;

constant: INT_CONSTANT
            {
                $$ = symbol_table::gentemp(new symbol_type("int"), to_string($1));  
                emit("=", $$->name, $1);
            }
        | FLOAT_CONSTANT
            {
                $$ = symbol_table::gentemp(new symbol_type("float"), to_string($1));     
                emit("=", $$->name, $1);
            }
        | CHAR_CONSTANT
            {
                $$ = symbol_table::gentemp(new symbol_type("char"), string(1,$1));    
                
                emit("=", $$->name, $1);
            }
            ;

postfix-expression: primary-expression
                        {
                            $$ = new Arr();           
                            $$->array_entry = $1->loc;        
                            $$->array_type = $1->loc->type;   
                            $$->addr = $$->array_entry;
                            // $$->category not set
                        }
                    | postfix-expression LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET
                        {
                            $$ = new Arr();               // Create a new Arr
                            $$->array_type = $1->array_type->arrType;   // L.type=L1.type.elem
                            $$->array_entry = $1->array_entry;          // L.array=L1.array
                            $$->addr = symbol_table::gentemp(new symbol_type("int"));  // L.addr=gentemp()
                            $$->category = "arr";              

                            if($1->category == "arr") {        
                                symbol* sym = symbol_table::gentemp(new symbol_type("int")); 
                                int sz = width_of_type($$->array_type);
                                emit("*", sym->name, $3->loc->name, to_string(sz)); // temp=sizeof(L.type)*expression.addr
                                emit("+", $$->addr->name, $1->addr->name, sym->name); // L.adder=L1.addr+temp
                            }
                            else {                          
                            // branch entered if $1->category is not set to "arr", this happens when the postfix-expression $1 is reduced from the first rule above i.e from primary expression which is the name of the array
                                int sz = width_of_type($$->array_type);
                                emit("*", $$->addr->name, $3->loc->name, to_string(sz));
                            }
                        }
                    | postfix-expression LEFT_ROUND_BRACKET argument-expression-list-opt RIGHT_ROUND_BRACKET
                        {   
                            
                            $$ = new Arr();
                            $$->array_entry = symbol_table::gentemp($1->array_type); 
                            emit("call", $$->array_entry->name, $1->array_entry->name, to_string($3));
                        }
                    | postfix-expression DOT IDENTIFIER
                        { /* skipped, only applicable for struct and class */ }
                    | postfix-expression ARROW IDENTIFIER
                        { /* skipped, only applicable for struct and class */ }
                    | postfix-expression UNARY_INCREMENT
                        {   
                            $$ = new Arr();
                            $$->array_entry = symbol_table::gentemp($1->array_entry->type);      
                            emit("=", $$->array_entry->name, $1->array_entry->name);            
                            emit("+", $1->array_entry->name, $1->array_entry->name, "1");       
                        }
                    | postfix-expression UNARY_DECREMENT
                        {
                            $$ = new Arr();
                            $$->array_entry = symbol_table::gentemp($1->array_entry->type);      
                            emit("=", $$->array_entry->name, $1->array_entry->name);            
                            emit("-", $1->array_entry->name, $1->array_entry->name, "1");       
                        }
                    | LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET initializer-list RIGHT_CURLY_BRACKET
                        { /* Skipped */ }
                    | LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET initializer-list COMMA RIGHT_CURLY_BRACKET
                        { /* Skipped */ }
                    ;

argument-expression-list-opt: argument-expression-list
                                {
                                    $$ = $1;    // simply propagate
                                }
                            | /* empty */
                                {
                                    $$ = 0;     // argument count set to zero
                                }
                            ;

argument-expression-list: 
        assignment-expression
        {
            $$ = 1;                         // first argument, set argument count to 1
            emit("param", $1->loc->name);   // prepare first parameter to function call
        }
        | argument-expression-list COMMA assignment-expression
        {
            $$ = $1 + 1;                    // expand parameter list by 1
            emit("param", $3->loc->name);   // keep adding param codes to quad array
        }
        ;

unary-expression:postfix-expression
                        {
                            $$=$1; // simply propagate
                        }
    | UNARY_INCREMENT unary-expression
                        {
                            $$=$2; // simply propagate, generating new temporary not required
                            emit("+",$2->array_entry->name,$2->array_entry->name,"1");
                        }
    | UNARY_DECREMENT unary-expression
                        {
                            $$=$2; // simply propagate, generating new temporary not required
                            emit("-",$2->array_entry->name,$2->array_entry->name,"1");
                        }
    | unary-operator cast-expression 
                        {
                            $$=new Arr();

                            if(string($1)=="&"){
                                $$->array_entry=symbol_table::gentemp(new symbol_type("ptr"));    // Generate a pointer temporary
                                $$->array_entry->type->arrType=$2->array_entry->type;                 // Assign corresponding type
                                emit("= &", $$->array_entry->name, $2->array_entry->name); 
                            }

                            else if(string($1)=="*"){
                                $$->category="ptr";
                                $$->addr=symbol_table::gentemp($2->array_entry->type->arrType);   // Generate a temporary of the appropriate type
                                $$->array_entry=$2->array_entry;                                      
                                emit("= *", $$->addr->name, $2->array_entry->name);    
                            }

                            else if(string($1)=="+"){
                                $$=$2; // simply propagate   
                            }

                            else if(string($1)=="~"){
                                $$->array_entry = symbol_table::gentemp(new symbol_type($2->array_entry->type->type));    // Generate temporary of the same base type
                                emit("= ~", $$->array_entry->name, $2->array_entry->name);       
                            }

                            else if(string($1)=="!"){
                                $$->array_entry = symbol_table::gentemp(new symbol_type($2->array_entry->type->type));    // Generate temporary of the same base type
                                emit("= !", $$->array_entry->name, $2->array_entry->name);         
                            }
                            else if(string($1)=="-"){
                            $$->array_entry = symbol_table::gentemp(new symbol_type($2->array_entry->type->type));    // Generate temporary of the same base type
                            emit("= -", $$->array_entry->name, $2->array_entry->name);    
                            }                          // Emit the quad
                            else{
                                cout<<"Unary operator not recognized"<<$1<<"\n";
                                exit(1);
                            }
                        }
    | SIZEOF unary-expression
                        {/* sizeof operator skipped */}
    | SIZEOF LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET
                        {/* sizeof operator skipped */}
    ;

unary-operator:AMPERSAND
                        {/* no semantic rule */}
    | ASTERISK
                        {/* no semantic rule */}
    | PLUS
                        {/* no semantic rule */}
    | MINUS
                        {/* no semantic rule */}
    | TILDE
                        {/* no semantic rule */}
    | EXCLAMATION
                        {/* no semantic rule */}
    ;

cast-expression:unary-expression
                        {
                            $$=$1; // simply propagate
                        }
    | LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET cast-expression
                        {
                            $$=new Arr();
                            $$->array_entry = change_type($4->array_entry, var_type);    // apparently generates a new symbol of the appropriate type
                            /*
                            scope for change, can be implemented using gentemp
                            */
                        }
    ;

multiplicative-expression:cast-expression
                        {
                            $$ = new expression();          
                            if($1->category == "arr") {        
                                $$->loc = symbol_table::gentemp($1->addr->type); 
                                
                                emit("=[]", $$->loc->name, $1->array_entry->name, $1->addr->name);   
                            }
                            else if($1->category == "ptr") {  
                                $$->loc = $1->addr;          
                            }
                            else {
                                $$->loc = $1->array_entry;
                            }
                        }
    | multiplicative-expression ASTERISK cast-expression
                        {
                            if(typecheck($1->loc, $3->array_entry)) {     // Check for type compatibility
                                $$ = new expression();                                                 
                                $$->loc = symbol_table::gentemp(new symbol_type($1->loc->type->type));  
                                emit("*", $$->loc->name, $1->loc->name, $3->array_entry->name);           
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    | multiplicative-expression DIVIDE cast-expression
                        {
                            if(typecheck($1->loc, $3->array_entry)) {     // Check for type compatibility
                                $$ = new expression();                                                 
                                $$->loc = symbol_table::gentemp(new symbol_type($1->loc->type->type));    
                                emit("/", $$->loc->name, $1->loc->name, $3->array_entry->name);              
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    | multiplicative-expression PERCENT cast-expression
                        {
                            if(typecheck($1->loc, $3->array_entry)) {  
                                $$ = new expression();                                                 
                                $$->loc = symbol_table::gentemp(new symbol_type($1->loc->type->type));   
                                emit("%", $$->loc->name, $1->loc->name, $3->array_entry->name);              
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    ;

additive-expression:multiplicative-expression
                        {
                            $$=$1; // simply propagate
                        }
    | additive-expression PLUS multiplicative-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {       // Check for type compatibility
                                $$ = new expression();                                                 
                                $$->loc = symbol_table::gentemp(new symbol_type($1->loc->type->type));   
                                emit("+", $$->loc->name, $1->loc->name, $3->loc->name);                
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    | additive-expression MINUS multiplicative-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {       // Check for type compatibility
                                $$ = new expression();                                                  
                                $$->loc = symbol_table::gentemp(new symbol_type($1->loc->type->type));  
                                emit("-", $$->loc->name, $1->loc->name, $3->loc->name);              
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    ;

shift-expression:additive-expression
                        {
                            $$=$1; // simply propagate
                        }
    | shift-expression LEFT_SHIFT additive-expression
                        {
                            if($3->loc->type->type == "int") {      // Check for type compatibility (int)
                                $$ = new expression();                                     
                                $$->loc = symbol_table::gentemp(new symbol_type("int"));      
                                emit("<<", $$->loc->name, $1->loc->name, $3->loc->name);    
                            }
                            else {
                                yyerror("Type Error");
            }
                        }
    | shift-expression RIGHT_SHIFT additive-expression
                        {
                            if($3->loc->type->type == "int") {      // Check for type compatibility (int)
                                $$ = new expression();                                     
                                $$->loc = symbol_table::gentemp(new symbol_type("int"));      
                                emit(">>", $$->loc->name, $1->loc->name, $3->loc->name);    
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    ;

relational-expression:shift-expression
                        {
                            $$=$1; // simply propagate
                        }
    | relational-expression LESS_THAN shift-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                   // Check for type compatibility
                                $$ = new expression();                         
                                $$->expr_type = "BOOL";
                                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                                emit("<", "", $1->loc->name, $3->loc->name);    // Emit "if x < y goto ___"
                                emit("goto", "");                               // Emit "goto ___"
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    | relational-expression GREATER_THAN shift-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                   // Check for type compatibility
                                $$ = new expression();                          
                                $$->expr_type = "BOOL";
                                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                                emit(">", "", $1->loc->name, $3->loc->name);    // Emit "if x > y goto ___"
                                emit("goto", "");                               // Emit "goto ___"
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    | relational-expression LESS_THAN_EQUAL shift-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                   // Check for type compatibility
                                $$ = new expression();                       
                                $$->expr_type = "BOOL";
                                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                                emit("<=", "", $1->loc->name, $3->loc->name);   // Emit "if x <= y goto ___"
                                emit("goto", "");                               // Emit "goto ___"
                            }
                            else {
                                yyerror("Type Error");
            }
                        }
    | relational-expression GREATER_THAN_EQUAL shift-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                   // Check for type compatibility
                                $$ = new expression();                     
                                $$->expr_type = "BOOL";
                                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                                emit(">=", "", $1->loc->name, $3->loc->name);   // Emit "if x >= y goto ___"
                                emit("goto", "");                               // Emit "goto ___"
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    ;

equality-expression:relational-expression
                        {
                            $$=$1;
                        }
    | equality-expression DOUBLE_EQUAL relational-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                   // Check for type compatibility
                                conv_Bool_int($1);                           // Convert bool to int
                                conv_Bool_int($3);
                                $$ = new expression();                       
                                $$->expr_type = "BOOL";
                                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                                emit("==", "", $1->loc->name, $3->loc->name);   // Emit "if x == y goto ___"
                                emit("goto", "");                               // Emit "goto ___"
                            }
                            else {
                                yyerror("Type Error");
            }
                        }
    | equality-expression NOT_EQUAL relational-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                   // Check for type compatibility
                                conv_Bool_int($1);                           // Convert bool to int
                                conv_Bool_int($3);
                                $$ = new expression();                         
                                $$->expr_type = "BOOL";
                                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                                emit("!=", "", $1->loc->name, $3->loc->name);   // Emit "if x != y goto ___"
                                emit("goto", "");                               // Emit "goto ___"
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    ;

AND-expression:equality-expression
                        {
                            $$=$1; // simply propagate
                        }
    | AND-expression AMPERSAND equality-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                               // Check for type compatibility
                                conv_Bool_int($1);                                       // Convert bool to int
                                conv_Bool_int($3);
                                $$ = new expression();
                                $$->expr_type = "NORMAL";                                      // The new result is not bool
                                $$->loc = symbol_table::gentemp(new symbol_type("int"));      // Create a new temporary
                                emit("&", $$->loc->name, $1->loc->name, $3->loc->name);     
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    ;

exclusive-OR-expression:AND-expression
                        {
                            $$=$1;
                        }
    | exclusive-OR-expression CARET AND-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                               // Check for type compatibility
                                conv_Bool_int($1);                                       // Convert bool to int
                                conv_Bool_int($3);
                                $$ = new expression();
                                $$->expr_type = "NORMAL";                                      // The new result is not bool
                                $$->loc = symbol_table::gentemp(new symbol_type("int"));      // Create a new temporary
                                emit("^", $$->loc->name, $1->loc->name, $3->loc->name);     
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    ;

inclusive-OR-expression:exclusive-OR-expression
                        {
                            $$=$1;
                        }
    | inclusive-OR-expression PIPE exclusive-OR-expression
                        {
                            if(typecheck($1->loc, $3->loc)) {                               // Check for type compatibility
                                conv_Bool_int($1);                                       // Convert bool to int
                                conv_Bool_int($3);
                                $$ = new expression();
                                $$->expr_type = "NORMAL";                                      // The new result is not bool
                                $$->loc = symbol_table::gentemp(new symbol_type("int"));      // Create a new temporary
                                emit("|", $$->loc->name, $1->loc->name, $3->loc->name);     
                            }
                            else {
                                yyerror("Type Error");
                            }
                        }
    ;

logical-AND-expression:inclusive-OR-expression
                        {
                            $$=$1;
                        }
    |logical-AND-expression LOGICAL_AND M inclusive-OR-expression
                        {
                            /*M is a special marker non terminal, M.instr provides the label to backpatch for true list for the logical-AND-expression*/
                            conv_int_Bool($1);                                   // Convert the expressions from int to bool
                            conv_int_Bool($4);
                            $$ = new expression();                                  // Create a new bool expression for the result
                            $$->expr_type = "BOOL";
                            backpatch($1->truelist, $3);                            // Backpatching
                            $$->truelist = $4->truelist;                            // Generate truelist from truelist of $4
                            $$->falselist = merge($1->falselist, $4->falselist);    // Generate falselist by merging the falselists of $1 and $4
                        }
    ;

logical-OR-expression:logical-AND-expression
                        {
                            $$=$1;
                        }
    | logical-OR-expression LOGICAL_OR M logical-AND-expression
                        {
                            /*M is a special marker non terminal, M.instr provides the label to backpatch for false list for the logical-OR-expression*/
                            conv_int_Bool($1);                                   // Convert the expressions from int to bool
                            conv_int_Bool($4);
                            $$ = new expression();                                  // Create a new bool expression for the result
                            $$->expr_type = "BOOL";
                            backpatch($1->falselist, $3);                           // Backpatching
                            $$->falselist = $4->falselist;                          // Generate falselist from falselist of $4
                            $$->truelist = merge($1->truelist, $4->truelist);       // Generate truelist by merging the truelists of $1 and $4

                        }
    ;

conditional-expression:logical-OR-expression
                        {
                            $$=$1;
                        }
    | logical-OR-expression N QUESTION M expression N COLON M conditional-expression
                        {
                            $$->loc = symbol_table::gentemp($5->loc->type);     
                            $$->loc->update($5->loc->type);
                            emit("=", $$->loc->name, $9->loc->name);           
                            int L1=nextinstr()+3;
                            emit("goto", to_string(L1));                                  
                            backpatch($6->nextlist, nextinstr());               // Make list with next instruction
                            emit("=", $$->loc->name, $5->loc->name);
                            int L2=nextinstr()+1;
                            emit("goto", to_string(L2));                                   // Prevent fall-through
                            backpatch($2->nextlist, nextinstr());              
                            conv_int_Bool($1);                              
                            backpatch($1->truelist, $4);                        // When $1 is true, control goes to $4 (expression)
                            backpatch($1->falselist, $8);                       // When $1 is false, control goes to $8 (conditional_expression)
                        }
    ;

M: /* epsilon */
    {   
        // Stores the next instruction value, and helps in backpatching
        $$ = nextinstr();
    }
    ;

N: /* epsilon */
    {
        // Helps in control flow
        $$ = new statement();
        $$->nextlist = makelist(nextinstr());
        emit("goto", "");
    }
    ;

assignment-expression:conditional-expression
                        {
                            $$=$1;
                        }
    | unary-expression assignment-operator assignment-expression
                        {
                            if($1->category == "arr") {        // If category is "arr", convert and emit
                                $3->loc = change_type($3->loc, $1->array_type->type);
                                emit("[]=", $1->array_entry->name, $1->addr->name, $3->loc->name);
                            }
                            else if($1->category == "ptr") {   // If category is "ptr", emit 
                                emit("*=", $1->array_entry->name, $3->loc->name);
                            }
                            else {
                                $3->loc = change_type($3->loc, $1->array_entry->type->type);
                                emit("=", $1->array_entry->name, $3->loc->name);
                            }
                            $$ = $3;
                        }
                        ;

assignment-operator:EQUAL
                        {/* this is the only valid production from assignment operator since other types of assignment operations are skipped */}
    | ASTERISK_EQUAL
                        {/* skipped */}
    | DIVIDE_EQUAL
                        {/* skipped */}
    | PERCENT_EQUAL
                        {/* skipped */}
    | PLUS_EQUAL
                        {/* skipped */}
    | MINUS_EQUAL
                        {/* skipped */}
    | LEFT_SHIFT_EQUAL
                        {/* skipped */}
    | RIGHT_SHIFT_EQUAL
                        {/* skipped */}
    | AMPERSAND_EQUAL
                        {/* skipped */}
    | CARET_EQUAL
                        {/* skipped */}
    | PIPE_EQUAL
                        {/* skipped */}
    ;

expression:assignment-expression
                        {
                            $$=$1;
                        }
    | expression COMMA assignment-expression
                        {
                            /* usage of comma operator is skipped */
                        }
    ;
constant-expression:conditional-expression
                        {
                            /* skipped */
                        }
    ;

/* swarups part */
declaration:declaration-specifiers init-declarator-list SEMI_COLON
                        {/*skipped*/}
            | declaration-specifiers SEMI_COLON
                        {/*skipped*/}
    ;

declaration-specifiers:storage-class-specifier declaration-specifiers
                        {/*skipped*/}
    | storage-class-specifier
                        {/*skipped*/}
    | type-specifier declaration-specifiers
                        {/*skipped*/}
    | type-specifier
                        {/*skipped*/}
    | type-qualifier declaration-specifiers
                        {/*skipped*/}
    | type-qualifier
                        {/*skipped*/}
    | function-specifier declaration-specifiers
                        {/*skipped*/}
    | function-specifier
                        {/*skipped*/}
    ;

init-declarator-list:init-declarator
                        {/*skipped*/}
    | init-declarator-list COMMA init-declarator
                        {/*skipped*/}
    ;

init-declarator:declarator
                        {$$=$1;}
    | declarator EQUAL initializer
                        {
                            if($3->sym_val != "") {
                                $1->sym_val = $3->sym_val;
                            }
                            emit("=", $1->name, $3->name);
                        }
    ;

storage-class-specifier:EXTERN
                        {/*skipped*/}
    | STATIC
                        {/*skipped*/}
    | AUTO
                        {/*skipped*/}
    | REGISTER
                        {/*skipped*/}
    ;

type-specifier:VOID
                        {var_type="void";}
    | CHAR
                        {var_type="char";}
    | SHORT
                        {/*skipped*/}
    | INT
                        {var_type="int";}
    | LONG
                        {/*skipped*/}
    | FLOAT
                        {var_type="float";}
    | DOUBLE
                        {/*skipped*/}
    | SIGNED
                        {/*skipped*/}
    | UNSIGNED
                        {/*skipped*/}
    | BOOL
                        {/*skipped*/}
    | COMPLEX
                        {/*skipped*/}
    | IMAGINARY
                        {/*skipped*/}
    | enum-specifier
                        {/*skipped*/}
    ;

specifier-qualifier-list:type-specifier specifier-qualifier-list-opt
                        {/*skipped*/}
    | type-qualifier specifier-qualifier-list-opt
                        {/*skipped*/}
    ;
specifier-qualifier-list-opt:specifier-qualifier-list
                        {/*skipped*/}
    | /* empty */
                        {/*skipped*/}
    ;
enum-specifier:ENUM identifier-opt LEFT_CURLY_BRACKET enumerator-list RIGHT_CURLY_BRACKET
                        {/*skipped*/}
    | ENUM identifier-opt LEFT_CURLY_BRACKET enumerator-list COMMA RIGHT_CURLY_BRACKET
                        {/*skipped*/}
    | ENUM IDENTIFIER
                        {/*skipped*/}
    ;
identifier-opt:IDENTIFIER
                        {/*skipped*/}
    |/*empty*/
                        {/*skipped*/}
    ;
enumerator-list:enumerator
                        {/*skipped*/}
    | enumerator-list COMMA enumerator
                        {/*skipped*/}
    ;

enumerator:IDENTIFIER
                        {/*skipped*/}
    | IDENTIFIER  EQUAL constant-expression
                        {/*skipped*/}
    ;

type-qualifier:CONST
                        {/*skipped*/}
    | RESTRICT
                        {/*skipped*/}
    | VOLATILE
                        {/*skipped*/}
    ;

function-specifier:INLINE
                        {/*skipped*/}
    ;

declarator:pointer direct-declarator
                        {
                            // if the direct declarator is preceded by pointer need to update its datatype in the symbol table

                            symbol_type* temp=$1;
                            while(temp->arrType!=NULL){
                                temp=temp->arrType;
                            }
                            temp->arrType=$2->type;
                            $$=$2->update($1);
                        }
    
    | direct-declarator
            {
                /* no need to update if pointer not found*/
            }
    ;

direct-declarator:IDENTIFIER    
                        {
                            $$ = $1->update(new symbol_type(var_type));  
                            present_symbol= $$;
                        }
    | LEFT_ROUND_BRACKET declarator RIGHT_ROUND_BRACKET
                        {
                            $$=$2;
                        }   
    | direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list assignment-expression RIGHT_SQUARE_BRACKET
                        {
                            /*skipped*/
                        }
    | direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list RIGHT_SQUARE_BRACKET
                        {
                            /*skipped*/
                        }
    | direct-declarator LEFT_SQUARE_BRACKET assignment-expression RIGHT_SQUARE_BRACKET
                        {
                            symbol_type* temp = $1->type;
                            symbol_type* prev = NULL;
                            
                            while(temp->type == "arr") {
                                prev = temp;
                                temp = temp->arrType;
                            }
                            if(prev == NULL) {
                                int temp_1 = atoi($3->loc->sym_val.c_str());            
                                symbol_type* type_found = new symbol_type("arr", $1->type, temp_1); 
                                $$ = $1->update(type_found);                                    
                            }
                            else {
                                int temp2 = atoi($3->loc->sym_val.c_str());                
                                prev->arrType = new symbol_type("arr", temp, temp2);
                                $$ = $1->update($1->type);                              
                            }
                        }
    
    | direct-declarator LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET
                        {
                            symbol_type* temp = $1->type;
                            symbol_type* prev = NULL;
                            
                            while(temp->type == "arr") {
                                prev = temp;
                                temp= temp->arrType;
                            }
                            if(prev == NULL) {
                                symbol_type* type_found = new symbol_type("arr", $1->type, 0);
                                $$ = $1->update(type_found);
                            }
                            else {
                                prev->arrType = new symbol_type("arr", temp, 0);
                                $$ = $1->update($1->type);
                            }
                        }
    | direct-declarator LEFT_SQUARE_BRACKET STATIC type-qualifier-list assignment-expression RIGHT_SQUARE_BRACKET
        { /* Ignored */ }
    | direct-declarator LEFT_SQUARE_BRACKET STATIC assignment-expression RIGHT_SQUARE_BRACKET
        { /* Ignored */ }
    | direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list STATIC assignment-expression RIGHT_SQUARE_BRACKET
        { /* Ignored */ }
    | direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list ASTERISK RIGHT_SQUARE_BRACKET
        { /* Ignored */ }
    | direct-declarator LEFT_SQUARE_BRACKET ASTERISK RIGHT_SQUARE_BRACKET
        { /* Ignored */ }
    | direct-declarator LEFT_ROUND_BRACKET switch-table parameter-type-list RIGHT_ROUND_BRACKET
                        {
                            present_symbol_table->name = $1->name;
                            if($1->type->type != "void") {
                                symbol* s = present_symbol_table->lookup("return");   
                                s->update($1->type);
                            }
                            $1->nested_table = present_symbol_table;
                            present_symbol_table->parent = glbl_symbol_table;   // Update parent symbol table
                            change_table(glbl_symbol_table);          // Switch current table to point to the global symbol table
                            present_symbol = $$;             // Update current symbol
                        }
    | direct-declarator LEFT_ROUND_BRACKET identifier-list RIGHT_ROUND_BRACKET
                        {/*skipped*/}
    | direct-declarator LEFT_ROUND_BRACKET switch-table RIGHT_ROUND_BRACKET
                        {
                            present_symbol_table->name = $1->name;
                            if($1->type->type != "void") {
                                symbol* s = present_symbol_table->lookup("return");  
                                s->update($1->type);
                            }
                            $1->nested_table = present_symbol_table;
                            present_symbol_table->parent = glbl_symbol_table;   // Update parent symbol table
                            change_table(glbl_symbol_table);          // Switch current table to point to the global symbol table
                            present_symbol = $$;             // Update current symbol
                        }
                        ;

pointer:ASTERISK type-qualifier-list-opt
                        {
                            $$=new symbol_type("ptr");
                        }
    | ASTERISK type-qualifier-list-opt pointer
                        {
                            $$=new symbol_type("ptr",$3);
                        }
    ;

type-qualifier-list-opt:type-qualifier-list
                        {/*skipped*/}
    | /* empty */
                        {/*skipped*/}
    ;
type-qualifier-list:type-qualifier
                        {/*skipped*/}
    | type-qualifier-list type-qualifier
                        {/*skipped*/}
    ;
parameter-type-list:parameter-list
                        {/*skipped*/}
    | parameter-list COMMA ELLIPSIS
                        {/*skipped*/}
    ;
parameter-list:parameter-declaration
                        {/*skipped*/}
    | parameter-list COMMA parameter-declaration
                        {/*skipped*/}
    ;
parameter-declaration:declaration-specifiers declarator
                        {/*skipped*/}
    | declaration-specifiers
                        {/*skipped*/}
    ;

identifier-list:IDENTIFIER
                        {/*skipped*/}
    | identifier-list COMMA IDENTIFIER
                        {/*skipped*/}
    ;

type-name:specifier-qualifier-list
                        {/*skipped*/}
    ;

initializer:assignment-expression
                        {
                            $$=$1->loc;
                        }
    | LEFT_CURLY_BRACKET initializer-list RIGHT_CURLY_BRACKET 
                        {/*skipped*/}
    | LEFT_CURLY_BRACKET initializer-list COMMA RIGHT_CURLY_BRACKET 
                        {/*skipped*/}
    ;

initializer-list:designation-opt initializer
                        {/*skipped*/}
    | initializer-list COMMA designation-opt initializer
                        {/*skipped*/}
    ;
designation-opt:designation
                        {/*skipped*/}
    | /* empty */
                        {/*skipped*/}
    ;
designation:designator-list EQUAL
                        {/*skipped*/}
    ;
designator-list:designator
                        {/*skipped*/}
    | designator-list designator
                        {/*skipped*/}
    ;
designator:LEFT_SQUARE_BRACKET constant-expression RIGHT_SQUARE_BRACKET
                        {/*skipped*/}
    | DOT IDENTIFIER
                        {/*skipped*/}
    ;


statement:labeled-statement
                        {/*skipped*/}
    | compound-statement
                        {$$=$1;}
    | expression-statement
                        {
                            $$ = new statement();          
                            $$->nextlist = $1->nextlist;    
                        }
    | selection-statement
                        {$$=$1;}
    | iteration-statement
                        {$$=$1;}
    | jump-statement
                        {$$=$1;}
    ;

/* New non-terminal that has been added to facilitate the structure of loops */
loop-statement:
        labeled-statement
        {/*skipped*/}
        | expression-statement
        {
            $$ = new statement();         
            $$->nextlist = $1->nextlist;   
        }
        | selection-statement
        {
            $$ = $1;    // Simple assignment
        }
        | iteration-statement
        {
            $$ = $1;    // Simple assignment
        }
        | jump-statement
        {
            $$ = $1;    // Simple assignment
        }
        ;

labeled-statement:IDENTIFIER COLON statement
                        {/*skipped*/}
    | CASE constant-expression COLON statement
                        {/*skipped*/}
    | DEFAULT COLON statement
                        {/*skipped*/}
    ;

compound-statement:LEFT_CURLY_BRACKET X switch-table block-item-list-opt RIGHT_CURLY_BRACKET
                        {
                            $$=$4;
                            change_table(present_symbol_table->parent);
                        }
    ;
block-item-list-opt:block-item-list
                        {$$=$1;}
    | /* empty */
                        {$$=new statement();}
    ;
block-item-list:block-item
                        {$$=$1;}
    | block-item-list M block-item
                        {
                            $$=$3;
                            backpatch($1->nextlist, $2);
                        }
    ;
block-item:declaration
                        {
                            $$ = new statement();
                        }
    | statement
                        {
                            $$=$1;
                        }
    ;  
expression-statement:expression SEMI_COLON
                        {
                            $$ = $1;    
                        }
                        | SEMI_COLON
                        {
                            $$ = new expression();  
                        }
    ;
selection-statement:IF LEFT_ROUND_BRACKET expression N RIGHT_ROUND_BRACKET M statement N %prec THEN
                        {
                            backpatch($4->nextlist, nextinstr());                   // assign to N->nextlist the point of exit
                            conv_int_Bool($3);                                   
                            $$ = new statement();                                   
                            backpatch($3->truelist, $6);                            // Backpatching - goto M if expression is True
                            list<int> temp = merge($3->falselist, $7->nextlist);
                            $$->nextlist = merge($8->nextlist, temp);
                        }
    | IF LEFT_ROUND_BRACKET expression N RIGHT_ROUND_BRACKET M statement N ELSE M statement
                        {
                            backpatch($4->nextlist, nextinstr());                   // assign to N->nextlist the point of exit
                            conv_int_Bool($3);                                   
                            $$ = new statement();                                   
                            backpatch($3->truelist, $6);                            // if expression==True goto M1 else goto M2
                            backpatch($3->falselist, $10);
                            list<int> temp = merge($7->nextlist, $8->nextlist);
                            $$->nextlist = merge($11->nextlist, temp);
                        }
    | SWITCH LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement
                        {/*skipped*/}
    ;

iteration-statement:WHILE W LEFT_ROUND_BRACKET X switch-table M expression RIGHT_ROUND_BRACKET M loop-statement
                        {
                            $$ = new statement();                   
                            conv_int_Bool($7);                   
                            backpatch($10->nextlist, $6);           // after each iteration goto M1.instr to check the loop condition for the next iteration
                            backpatch($7->truelist, $9);            // assign the true exit of expression to M2
                            $$->nextlist = $7->falselist;           // Exit loop if expression is false
                            emit("goto", to_string($6));   // Emit to prevent fall-through
                            block_name = "";
                            change_table(present_symbol_table->parent);
                        }
    | WHILE W LEFT_ROUND_BRACKET X switch-table M expression RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET M block-item-list-opt RIGHT_CURLY_BRACKET
        {
            $$ = new statement();                   
            conv_int_Bool($7);                   
            backpatch($11->nextlist, $6);           // after each iteration goto M1.instr to check the loop condition for the next iteration
            backpatch($7->truelist, $10);           // assign the true exit of expression to M2
            $$->nextlist = $7->falselist;           // Exit loop if expression is false
            emit("goto", to_string($6));   // Emit to prevent fall-through
            block_name = "";
            change_table(present_symbol_table->parent);
        }
    | DO D X switch-table M loop-statement M WHILE LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET SEMI_COLON
                        {
                            $$ = new statement();                      
                            conv_int_Bool($10);                   
                            backpatch($10->truelist, $5);            // after each iteration goto M1.instr to check the loop condition for the next iteration
                            backpatch($6->nextlist, $7);            // assign the true exit of expression to M2
                            $$->nextlist = $10->falselist;           // Exit loop if expression is false  
                            block_name = "";
                            change_table(present_symbol_table->parent);
                        }
    | DO D X switch-table LEFT_CURLY_BRACKET M block-item-list-opt RIGHT_CURLY_BRACKET M WHILE LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET SEMI_COLON
        {

            $$ = new statement();                   
            conv_int_Bool($12);                  
            backpatch($12->truelist, $6);           // after each iteration goto M1.instr to check the loop condition for the next iteration
            backpatch($7->nextlist, $9);            // assign the true exit of expression to M2
            $$->nextlist = $12->falselist;          // Exit loop if expression is false  
            block_name = "";
            change_table(present_symbol_table->parent);
        }
    | FOR F LEFT_ROUND_BRACKET X switch-table declaration M expression-statement M expression N RIGHT_ROUND_BRACKET M loop-statement
                        {
                            $$ = new statement();                   
                            conv_int_Bool($8);                   
                            backpatch($8->truelist, $13);           // Go to M3 if expression is true
                            backpatch($11->nextlist, $7);           // Go back to M1 after N
                            backpatch($14->nextlist, $9);           // Go back to expression after loop_statement
                            emit("goto", to_string($9));   // Emit to prevent fall-through
                            $$->nextlist = $8->falselist;           // Exit loop if expression_statement is false
                            block_name = "";
                            change_table(present_symbol_table->parent);
                        }
    | FOR F LEFT_ROUND_BRACKET X switch-table expression-statement M expression-statement M expression N RIGHT_ROUND_BRACKET M loop-statement
                        {
                            $$ = new statement();                   
                            conv_int_Bool($8);                   
                            backpatch($8->truelist, $13);           // Go to M3 if expression is true
                            backpatch($11->nextlist, $7);           // Go back to M1 after N
                            backpatch($14->nextlist, $9);           // Go back to expression after loop_statement
                            emit("goto", to_string($9));   // Emit to prevent fall-through
                            $$->nextlist = $8->falselist;           // Exit loop if expression_statement is false
                            block_name = "";
                            change_table(present_symbol_table->parent);
                        }
    | FOR F LEFT_ROUND_BRACKET X switch-table declaration M expression-statement M expression N RIGHT_ROUND_BRACKET M LEFT_CURLY_BRACKET block-item-list-opt RIGHT_CURLY_BRACKET
                        {
                            $$ = new statement();                   
                            conv_int_Bool($8);                   
                            backpatch($8->truelist, $13);           // goto M3 if expression is true
                            backpatch($11->nextlist, $7);           // loop back to M1 after N
                            backpatch($15->nextlist, $9);           
                            emit("goto", to_string($9));   // Emit to prevent fall-through
                            $$->nextlist = $8->falselist;           // Exit loop if expression_statement is false
                            block_name = "";
                            change_table(present_symbol_table->parent);
                        }
    | FOR F LEFT_ROUND_BRACKET X switch-table expression-statement M expression-statement M expression N RIGHT_ROUND_BRACKET M LEFT_CURLY_BRACKET block-item-list-opt RIGHT_CURLY_BRACKET
                        {
                            $$ = new statement();                  
                            conv_int_Bool($8);                   
                            backpatch($8->truelist, $13);           // goto M3 if expression is true
                            backpatch($11->nextlist, $7);           // loop back to M1 after N
                            backpatch($15->nextlist, $9);          
                            emit("goto", to_string($9));   // Emit to prevent fall-through
                            $$->nextlist = $8->falselist;           // Exit loop if expression_statement is false
                            block_name = "";
                            change_table(present_symbol_table->parent);
                        }
        ;
jump-statement:GOTO IDENTIFIER SEMI_COLON
                        {/*skipped*/}
    | CONTINUE SEMI_COLON
                        {
                            /*skipped, should work on skipping*/
                            $$ = new statement();
                        }
    | BREAK SEMI_COLON
                        {
                            /* skipped, should work on skipping*/
                            $$ = new statement();
                        }
    | RETURN expression SEMI_COLON
                        {
                            $$ = new statement();
                            emit("return", $2->loc->name);  
                        }
    | RETURN SEMI_COLON
        {
            $$ = new statement();
            emit("return", "");           
        }
    ;

translation-unit:external-declaration
                        {/*skipped*/}
    | translation-unit external-declaration
                        {/*skipped*/}
    ;
external-declaration:function-definition
                        {/*skipped*/}
    | declaration
                        {/*skipped*/}
    ;
function-definition:declaration-specifiers declarator declaration-list-opt switch-table LEFT_CURLY_BRACKET block-item-list-opt RIGHT_CURLY_BRACKET
                        {
                            present_symbol_table->parent = glbl_symbol_table;
                            count_ST = 0;
                            change_table(glbl_symbol_table);
                        }
    ;
declaration-list-opt:declaration-list
                        {/*skipped*/}
    | /* empty */
                        {/*skipped*/}
    ;
declaration-list:declaration
                        {/*skipped*/}
    | declaration-list declaration
                        {/*skipped*/}
    ;

F: %empty
        {   
            block_name = "FOR_BLOCK";
        }
        ;

W: %empty
        {
            block_name = "WHILE_BLOCK";
        }
        ;

D: %empty
        {
            block_name = "DO_WHILE_BLOCK";
        }
        ;

X: %empty
        {   
            string newST = present_symbol_table->name + "." + block_name + "$" + to_string(count_ST++);  
            symbol* sym = present_symbol_table->lookup(newST);
            sym->nested_table = new symbol_table(newST);  // Create new symbol table
            sym->name = newST;
            sym->nested_table->parent = present_symbol_table;
            sym->type = new symbol_type("block");    // The type will be "block"
            present_symbol= sym;    // Change the current symbol pointer
        }
        ;

switch-table: %empty
        {   
            if(present_symbol->nested_table != NULL) {
                change_table(present_symbol->nested_table);
                emit("LABEL", present_symbol_table->name);
            }
            else {
                change_table(new symbol_table(""));
            }
        }
        ;

%%

void yyerror(string s){
    cout<<s<<endl;
}