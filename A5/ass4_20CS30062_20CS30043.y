%{
    #include <string.h>
    #include <stdio.h>
    extern int yylex();
    extern int yylineno;
    void yyerror(char *);
%}

%union{
    int intval;
    double doubleval;
    char charval;
    char* stringval;    
}

%token<stringval> IDENTIFIER 
%token<intval> INT_CONSTANT
%token<doubleval> FLOAT_CONSTANT
%token<charval> CHAR_CONSTANT
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
%token<stringval> ELSE
%token<stringval> SWITCH
%token<stringval> WHILE
%token<stringval> DO
%token<stringval> FOR
%token<stringval> GOTO
%token<stringval> CONTINUE
%token<stringval> BREAK
%token<stringval> RETURN
%token UNKNOWN


%nonassoc RIGHT_ROUND_BRACKET
%nonassoc ELSE

%start translation-unit


%%
/*expressions*/
primary-expression:IDENTIFIER
                        {printf("\t\tprimary-expression -> identifier(%s)\n",$1);}
    | constant
                        {printf("\t\tprimary-expression -> constant\n");}
    | STRING_LITERAL
                        {printf("\t\tprimary-expression -> string-literal(%s)\n",$1);}
    | LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET
                        {printf("\t\tprimary-expression -> %s expression %s\n",$1,$3);}
    ;


constant:INT_CONSTANT
                        {printf("\t\tconstant -> integer-constant(%d)\n",$1);}
    | FLOAT_CONSTANT
                        {printf("\t\tconstant -> float-constant(%f)\n",$1);} 
    | CHAR_CONSTANT
                        {printf("\t\tconstant -> char-constant(%c)\n",$1);}
    ;

postfix-expression:primary-expression
                        {printf("\t\tpostfix-expression -> primary-expression\n");}
    | postfix-expression LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET
                        {printf("\t\tpostfix-expression -> postfix-expression %s expression %s\n",$2,$4);}
    | postfix-expression LEFT_ROUND_BRACKET argument-expression-list-opt RIGHT_ROUND_BRACKET
                        {printf("\t\tpostfix-expression -> postfix-expression %s argument-expression-list-opt %s\n",$2,$4);}
    | postfix-expression DOT IDENTIFIER
                        {printf("\t\tpostfix-expression -> postfix-expression %s identifier(%s)\n",$2,$3);}
    | postfix-expression ARROW IDENTIFIER
                        {printf("\t\tpostfix-expression -> postfix-expression %s identifier(%s)\n",$2,$3);}
    | postfix-expression UNARY_INCREMENT
                        {printf("\t\tpostfix-expression -> postfix-expression %s\n",$2);}
    | postfix-expression UNARY_DECREMENT
                        {printf("\t\tpostfix-expression -> postfix-expression %s\n",$2);}
    | LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET initializer-list RIGHT_CURLY_BRACKET
                        {printf("\t\tpostfix-expression -> %s type-name %s %s initializer-list %s\n",$1,$3,$4,$6);}
    | LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET initializer-list COMMA RIGHT_CURLY_BRACKET
                        {printf("\t\tpostfix-expression -> %s type-name %s %s initializer-list %s %s\n",$1,$3,$4,$6,$7);}
    ;

argument-expression-list-opt:argument-expression-list
                        {printf("\t\targument-expression-list-opt -> argument-expression-list\n");}
    | /* empty */   
                        {printf("\t\targument-expression-list-opt -> epsilon\n");}
    ;
argument-expression-list:assignment-expression
                        {printf("\t\targument-expression-list -> assignment-expression\n");}
    | argument-expression-list COMMA assignment-expression
                        {printf("\t\targument-expression-list -> argument-expression-list %s assignment-expression\n",$2);}
    ;

unary-expression:postfix-expression
                        {printf("\t\tunary-expression -> postfix-expression\n");}
    | UNARY_INCREMENT unary-expression
                        {printf("\t\tunary-expression -> %s unary-expression\n",$1);}
    | UNARY_DECREMENT unary-expression
                        {printf("\t\tunary-expression -> %s unary-expression\n",$1);}
    | unary-operator cast-expression 
                        {printf("\t\tunary-expression -> unary-operator cast-expression\n");}
    | SIZEOF unary-expression
                        {printf("\t\tunary-expression -> %s unary-expression\n",$1);}
    | SIZEOF LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET
                        {printf("\t\tunary-expression -> %s %s type-name %s\n",$1,$2,$4);}
    ;
unary-operator:AMPERSAND
                        {printf("\t\tunary-operator -> %s\n",$1);}
    | ASTERISK
                        {printf("\t\tunary-operator -> %s\n",$1);}
    | PLUS
                        {printf("\t\tunary-operator -> %s\n",$1);}
    | MINUS
                        {printf("\t\tunary-operator -> %s\n",$1);}
    | TILDE
                        {printf("\t\tunary-operator -> %s\n",$1);}
    | EXCLAMATION
                        {printf("\t\tunary-operator -> %s\n",$1);}
    ;

cast-expression:unary-expression
                        {printf("\t\tcast-expression -> unary-expression\n");}
    | LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET cast-expression
                        {printf("\t\tcast-expression -> %s type-name %s cast-expression\n",$1,$3);}
    ;

multiplicative-expression:cast-expression
                        {printf("\t\tmultiplicative-expression -> cast-expression\n");}
    | multiplicative-expression ASTERISK cast-expression
                        {printf("\t\tmultiplicative-expression -> multiplicative-expression %s cast-expression\n",$2);}
    | multiplicative-expression DIVIDE cast-expression
                        {printf("\t\tmultiplicative-expression -> multiplicative-expression %s cast-expression\n",$2);}
    | multiplicative-expression PERCENT cast-expression
                        {printf("\t\tmultiplicative-expression -> multiplicative-expression %s cast-expression\n",$2);}
    ;

additive-expression:multiplicative-expression
                        {printf("\t\tadditive-expression -> multiplicative-expression\n");}
    | additive-expression PLUS multiplicative-expression
                        {printf("\t\tadditive-expression -> additive-expression %s multiplicative-expression\n",$2);}
    | additive-expression MINUS multiplicative-expression
                        {printf("\t\tadditive-expression -> additive-expression %s multiplicative-expression\n",$2);}
    ;
shift-expression:additive-expression
                        {printf("\t\tshift-expression -> additive-expression\n");}
    | shift-expression LEFT_SHIFT additive-expression
                        {printf("\t\tshift-expression -> shift-expression %s additive-expression\n",$2);}
    | shift-expression RIGHT_SHIFT additive-expression
                        {printf("\t\tshift-expression -> shift-expression %s additive-expression\n",$2);}
    ;
relational-expression:shift-expression
                        {printf("\t\trelational-expression -> shift-expression\n");}
    | relational-expression LESS_THAN shift-expression
                        {printf("\t\trelational-expression -> relational-expression %s shift-expression\n",$2);}
    | relational-expression GREATER_THAN shift-expression
                        {printf("\t\trelational-expression -> relational-expression %s shift-expression\n",$2);}
    | relational-expression LESS_THAN_EQUAL shift-expression
                        {printf("\t\trelational-expression -> relational-expression %s shift-expression\n",$2);}
    | relational-expression GREATER_THAN_EQUAL shift-expression
                        {printf("\t\trelational-expression -> relational-expression %s shift-expression\n",$2);}
    ;
equality-expression:relational-expression
                        {printf("\t\tequality-expression -> relational-expression\n");}
    | equality-expression DOUBLE_EQUAL relational-expression
                        {printf("\t\tequality-expression -> equality-expression %s relational-expression\n",$2);}
    | equality-expression NOT_EQUAL relational-expression
                        {printf("\t\tequality-expression -> equality-expression %s relational-expression\n",$2);}
    ;
AND-expression:equality-expression
                        {printf("\t\tAND-expression -> equality-expression\n");}
    | AND-expression AMPERSAND equality-expression
                        {printf("\t\tAND-expression -> AND-expression %s equality-expression\n",$2);}
    ;
exclusive-OR-expression:AND-expression
                        {printf("\t\texclusive-OR-expression -> AND-expression\n");}
    | exclusive-OR-expression CARET AND-expression
                        {printf("\t\texclusive-OR-expression -> exclusive-OR-expression %s AND-expression\n",$2);}
    ;
inclusive-OR-expression:exclusive-OR-expression
                        {printf("\t\tinclusive-OR-expression -> exclusive-OR-expression\n");}
    | inclusive-OR-expression PIPE exclusive-OR-expression
                        {printf("\t\tinclusive-OR-expression -> inclusive-OR-expression %s exclusive-OR-expression\n",$2);}
    ;
logical-OR-expression:logical-AND-expression
                        {printf("\t\tlogical-OR-expression -> logical-AND-expression\n");}
    | logical-OR-expression LOGICAL_OR logical-AND-expression
                        {printf("\t\tlogical-OR-expression -> logical-OR-expression %s logical-AND-expression\n",$2);}
    ;
logical-AND-expression:inclusive-OR-expression
                        {printf("\t\tlogical-AND-expression -> inclusive-OR-expression\n");}
    |logical-AND-expression LOGICAL_AND inclusive-OR-expression
                        {printf("\t\tlogical-AND-expression -> logical-AND-expression %s inclusive-OR-expression\n",$2);}
    ;
conditional-expression:logical-OR-expression
                        {printf("\t\tconditional-expression -> logical-OR-expression\n");}
    | logical-OR-expression QUESTION expression COLON conditional-expression
                        {printf("\t\tconditional-expression -> logical-OR-expression %s expression %s conditional-expression\n",$2,$4);}
    ;
assignment-expression:conditional-expression
                        {printf("\t\tassignment-expression -> conditional-expression\n");}
    | unary-expression assignment-operator assignment-expression
                        {printf("\t\tassignment-expression -> unary-expression assignment-operator assignment-expression\n");}
    ;
assignment-expression-opt:assignment-expression
                        {printf("\t\tassignment-expression-opt -> assignment-expression\n");}
    |/* empty */
                        {printf("\t\tassignment-expression-opt -> epsilon\n");}
    ;
assignment-operator:EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | ASTERISK_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | DIVIDE_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | PERCENT_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | PLUS_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | MINUS_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | LEFT_SHIFT_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | RIGHT_SHIFT_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | AMPERSAND_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | CARET_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    | PIPE_EQUAL
                        {printf("\t\tassignment-operator -> %s\n",$1);}
    ;
expression-opt:expression
                        {printf("\t\texpression-opt -> expression\n");}
    | /* empty */
                        {printf("\t\texpression-opt -> epsilon\n");}
    ;

expression:assignment-expression
                        {printf("\t\texpression -> assignment-expression\n");}
    | expression COMMA assignment-expression
                        {printf("\t\texpression -> expression %s assignment-expression\n",$2);}
    ;
constant-expression:conditional-expression
                        {printf("\t\tconstant-expression -> conditional-expression\n");}
    ;
/*Declarations*/
declaration:declaration-specifiers init-declarator-list-opt SEMI_COLON
                        {printf("\t\tdeclaration -> declaration-specifiers init-declarator-list-opt %s\n",$3);}
    ;

init-declarator-list-opt:init-declarator-list
                        {printf("\t\tinit-declaration-list-opt -> init-declarator-list\n");}
    | /* empty */
                        {printf("\t\tinit-declaration-list-opt -> epsilon\n");}
    ;
declaration-specifiers-opt:declaration-specifiers
                        {printf("\t\tdeclaration-specifiers-opt -> declaration-specifiers\n");}
    | /* empty */
                        {printf("\t\tdeclaration-specifiers-opt -> epsilon\n");}
    ;
declaration-specifiers:storage-class-specifier declaration-specifiers-opt
                        {printf("\t\tdeclaration-specifiers -> storage-class-specifier declaration-specifiers-opt\n");}
    | type-specifier declaration-specifiers-opt
                        {printf("\t\tdeclaration-specifiers -> type-specifier declaration-specifiers-opt\n");}
    | type-qualifier declaration-specifiers-opt
                        {printf("\t\tdeclaration-specifiers -> type-qualifier declaration-specifiers-opt\n");}
    | function-specifier declaration-specifiers-opt
                        {printf("\t\tdeclaration-specifiers -> function-specifier declaration-specifiers-opt\n");}
    ;
init-declarator-list:init-declarator
                        {printf("\t\tinit-declarator-list -> init-declarator\n");}
    | init-declarator-list COMMA init-declarator
                        {printf("\t\tinit-declarator-list -> init-declarator-list %s init-declarator\n",$2);}
    ;
init-declarator:declarator
                        {printf("\t\tinit-declarator -> declarator\n");}
    | declarator EQUAL initializer
                        {printf("\t\tinit-declarator -> declarator %s initializer\n",$2);}
    ;

storage-class-specifier:EXTERN
                        {printf("\t\tstorage-class-specifier -> %s\n",$1);}
    | STATIC
                        {printf("\t\tstorage-class-specifier -> %s\n",$1);}
    | AUTO
                        {printf("\t\tstorage-class-specifier -> %s\n",$1);}
    | REGISTER
                        {printf("\t\tstorage-class-specifier -> %s\n",$1);}
    ;

type-specifier:VOID
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | CHAR
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | SHORT
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | INT
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | LONG
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | FLOAT
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | DOUBLE
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | SIGNED
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | UNSIGNED
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | BOOL
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | COMPLEX
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | IMAGINARY
                        {printf("\t\ttype-specifier -> %s\n",$1);}
    | enum-specifier
                        {printf("\t\ttype-specifier -> enum-specifier\n");}
    ;

specifier-qualifier-list:type-specifier specifier-qualifier-list-opt
                        {printf("\t\tspecifier-qualifier-list -> type-specifier specifier-qualifier-list-opt\n");}
    | type-qualifier specifier-qualifier-list-opt
                        {printf("\t\tspecifier-qualifier-list -> type-qualifier specifier-qualifier-list-opt\n");}
    ;
specifier-qualifier-list-opt:specifier-qualifier-list
                        {printf("\t\tspecifier-qualifier-list-opt -> specifier-qualifier-list\n");}
    | /* empty */
                        {printf("\t\tspecifier-qualifier-list-opt -> epsilon\n");}
    ;
enum-specifier:ENUM identifier-opt LEFT_CURLY_BRACKET enumerator-list RIGHT_CURLY_BRACKET
                        {printf("\t\tenum-specifier -> %s identifier-opt %s enumerator-list %s\n",$1,$3,$5);}
    | ENUM identifier-opt LEFT_CURLY_BRACKET enumerator-list COMMA RIGHT_CURLY_BRACKET
                        {printf("\t\tenum-specifier -> %s identifier-opt %s enumerator-list %s %s\n",$1,$3,$5,$6);}
    | ENUM IDENTIFIER
                        {printf("\t\tenum-specifier -> %s identifier(%s)\n",$1,$2);}
    ;
identifier-opt:IDENTIFIER
                        {printf("\t\tidentifier-opt -> identifier(%s)\n",$1);}
    |/*empty*/
                        {printf("\t\tidentifier-opt -> epsilon\n");}
    ;
enumerator-list:enumerator
                        {printf("\t\tenumerator-list -> enumerator\n");}
    | enumerator-list COMMA enumerator
                        {printf("\t\tenumerator-list -> enumerator-list %s enumerator\n",$2);}
    ;

enumerator:IDENTIFIER
                        {printf("\t\tenumerator -> enumerator-constant(%s)\n",$1);}
    | IDENTIFIER  EQUAL constant-expression
                        {printf("\t\tenumerator -> enumeration-constant(%s) %s constant-expression\n",$1,$2);}
    ;

type-qualifier:CONST
                        {printf("\t\ttype-qualifier -> %s\n",$1);}
    | RESTRICT
                        {printf("\t\ttype-qualifier -> %s\n",$1);}
    | VOLATILE
                        {printf("\t\ttype-qualifier -> %s\n",$1);}
    ;

function-specifier:INLINE
                        {printf("\t\tfunction-specifier -> %s\n",$1);}
    ;
declarator:pointer-opt direct-declarator
                        {printf("\t\tdeclarator -> pointer-opt direct-declarator\n");}
    ;
pointer-opt:pointer
                        {printf("\t\tpointer-opt -> pointer\n");}
    | /* empty */
                        {printf("\t\tpointer-opt -> epsilon\n");}
    ;
direct-declarator:IDENTIFIER    
                        {printf("\t\tdirect-declarator -> identifier(%s)\n",$1);}
    | LEFT_ROUND_BRACKET declarator RIGHT_ROUND_BRACKET
                        {printf("\t\tdirect-declarator -> %s declarator %s\n",$1,$3);}
    | direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list-opt assignment-expression-opt RIGHT_SQUARE_BRACKET
                        {printf("\t\tdirect-declarator -> direct-declarator %s type-qualifier-list-opt assignment-expression-opt %s\n",$2,$5);}
    | direct-declarator LEFT_SQUARE_BRACKET STATIC type-qualifier-list-opt assignment-expression RIGHT_SQUARE_BRACKET
                        {printf("\t\tdirect-declarator -> direct-declarator %s %s type-qualifier-list-opt assignment-expression %s\n",$2,$3,$6);}
    | direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list STATIC assignment-expression RIGHT_SQUARE_BRACKET
                        {printf("\t\tdirect-declarator -> direct-declarator %s type-qualifier-list %s assignment-expression %s\n",$2,$4,$6);}
    | direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list-opt ASTERISK RIGHT_SQUARE_BRACKET
                        {printf("\t\tdirect-declarator -> direct-declarator %s type-qualifier-list-opt %s %s\n",$2,$4,$5);}
    | direct-declarator LEFT_ROUND_BRACKET parameter-type-list RIGHT_ROUND_BRACKET
                        {printf("\t\tdirect-declarator -> direct-declarator %s parameter-type-list %s\n",$2,$4);}
    | direct-declarator LEFT_ROUND_BRACKET identifier-list-opt RIGHT_ROUND_BRACKET
                        {printf("\t\tdirect-declarator -> direct-declarator %s identifier-list-opt %s\n",$2,$4);}
    ;
identifier-list-opt:identifier-list
                        {printf("\t\tidentifier-list-opt -> identifier-list\n");}
    | /* empty */
                        {printf("\t\tidentifier-list-opt -> epsilon\n");}
    ;
pointer:ASTERISK type-qualifier-list-opt
                        {printf("\t\tpointer -> %s type-qualifier-list-opt\n",$1);}
    | ASTERISK type-qualifier-list-opt pointer
                        {printf("\t\tpointer -> %s type-qualifier-list-opt pointer\n",$1);}
    ;
type-qualifier-list-opt:type-qualifier-list
                        {printf("\t\ttype-qualifier-list-opt -> type-qualifier-list\n");}
    | /* empty */
                        {printf("\t\ttype-qualifier-list-opt -> epsilon\n");}
    ;
type-qualifier-list:type-qualifier
                        {printf("\t\ttype-qualifier-list -> type-qualifier\n");}
    | type-qualifier-list type-qualifier
                        {printf("\t\ttype-qualifier-list -> type-qualifier-list type-qualifier\n");}
    ;
parameter-type-list:parameter-list
                        {printf("\t\tparameter-type-list -> parameter-list\n");}
    | parameter-list COMMA ELLIPSIS
                        {printf("\t\tparameter-type-list -> parameter-list %s %s\n",$2,$3);}
    ;
parameter-list:parameter-declaration
                        {printf("\t\tparameter-list -> parameter-declaration\n");}
    | parameter-list COMMA parameter-declaration
                        {printf("\t\tparameter-list -> parameter-list %s parameter-declaration\n",$2);}
    ;
parameter-declaration:declaration-specifiers declarator
                        {printf("\t\tparameter-declaration -> declaration-specifiers declarator\n");}
    | declaration-specifiers
                        {printf("\t\tparameter-declaration -> declaration-specifiers\n");}
    ;

identifier-list:IDENTIFIER
                        {printf("\t\tidentifier-list -> identifier(%s)\n",$1);}
    | identifier-list COMMA IDENTIFIER
                        {printf("\t\tidentifier-list -> identifier-list %s identifier(%s)\n",$2,$3);}
    ;

type-name:specifier-qualifier-list
                        {printf("\t\ttype-name -> specifier-qualifier-list\n");}
    ;
initializer:assignment-expression
                        {printf("\t\tinitializer -> assignment-expression\n");}
    | LEFT_CURLY_BRACKET initializer-list RIGHT_CURLY_BRACKET 
                        {printf("\t\tinitializer -> %s initializer-list %s\n",$1,$3);}
    | LEFT_CURLY_BRACKET initializer-list COMMA RIGHT_CURLY_BRACKET 
                        {printf("\t\tinitializer -> %s initializer-list %s %s\n",$1,$3,$4);}
    ;
initializer-list:designation-opt initializer
                        {printf("\t\tinitializer-list -> designation-opt initializer\n");}
    | initializer-list COMMA designation-opt initializer
                        {printf("\t\tinitializer-list -> initializer-list %s designation-opt initializer\n",$2);}
    ;
designation-opt:designation
                        {printf("\t\tdesignation-opt -> designation\n");}
    | /* empty */
                        {printf("\t\tdesignation-opt -> epsilon\n");}
    ;
designation:designator-list EQUAL
                        {printf("\t\tdesignation -> designator-list %s\n",$2);}
    ;
designator-list:designator
                        {printf("\t\tdesignator-list -> designator\n");}
    | designator-list designator
                        {printf("\t\tdesignator-list -> designator-list designator\n");}
    ;
designator:LEFT_SQUARE_BRACKET constant-expression RIGHT_SQUARE_BRACKET
                        {printf("\t\tdesignator -> %s constant-expression %s\n",$1,$3);}
    | DOT IDENTIFIER
                        {printf("\t\tdesignator -> %s identifier(%s)\n",$1,$2);}
    ;
/*Statements*/

statement:labeled-statement
                        {printf("\t\tstatement -> labeled-statement\n");}
    | compound-statement
                        {printf("\t\tstatement -> compound-statement\n");}
    | expression-statement
                        {printf("\t\tstatement -> expression-statement\n");}
    | selection-statement
                        {printf("\t\tstatement -> selection-statement\n");}
    | iteration-statement
                        {printf("\t\tstatement -> iteration-statement\n");}
    | jump-statement
                        {printf("\t\tstatement -> jump-statement\n");}
    ;
labeled-statement:IDENTIFIER COLON statement
                        {printf("\t\tlabeled-statement -> identifier(%s) %s statement\n",$1,$2);}
    | CASE constant-expression COLON statement
                        {printf("\t\tlabeled-statement -> %s constant-expression %s statement\n",$1,$3);}
    | DEFAULT COLON statement
                        {printf("\t\tlabeled-statement -> %s %s statement\n",$1,$2);}
    ;
compound-statement:LEFT_CURLY_BRACKET block-item-list-opt RIGHT_CURLY_BRACKET
                        {printf("\t\tcompound-statement -> %s block-item-list-opt %s\n",$1,$3);}
    ;
block-item-list-opt:block-item-list
                        {printf("\t\tblock-item-list-opt -> block-item-list\n");}
    | /* empty */
                        {printf("\t\tblock-item-list-opt -> epsilon\n");}
    ;
block-item-list:block-item
                        {printf("\t\tblock-item-list -> block-item\n");}
    | block-item-list block-item
                        {printf("\t\tblock-item-list -> block-item-list block-item\n");}
    ;
block-item:declaration
                        {printf("\t\tblock-item -> declaration\n");}
    | statement
                        {printf("\t\tblock-item -> statement\n");}
    ;  
expression-statement:expression-opt SEMI_COLON
                        {printf("\t\texpression-statement -> expression-opt %s\n",$2);}
    ;
selection-statement:IF LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement
                        {printf("\t\tselection-statement -> %s %s expression %s statement\n",$1,$2,$4);}
    | IF LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement ELSE statement
                        {printf("\t\tselection-statement -> %s %s expression %s statement %s statement\n",$1,$2,$4,$6);}
    | SWITCH LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement
                        {printf("\t\tselection-statement -> %s %s expression %s statement\n",$1,$2,$4);}
    ;
iteration-statement:WHILE LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement
                        {printf("\t\titeration-statement -> %s %s expression %s statement\n",$1,$2,$4);}
    | DO statement WHILE LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET SEMI_COLON
                        {printf("\t\titeration-statement -> %s statement %s %s expression %s %s\n",$1,$3,$4,$6,$7);}
    | FOR LEFT_ROUND_BRACKET expression-opt SEMI_COLON expression-opt SEMI_COLON expression-opt RIGHT_ROUND_BRACKET statement
                        {printf("\t\titeration-statement -> %s %s expression-opt %s expression-opt %s expression-opt %s statement\n",$1,$2,$4,$6,$8);}
    | FOR LEFT_ROUND_BRACKET declaration expression-opt SEMI_COLON expression-opt RIGHT_ROUND_BRACKET statement
                        {printf("\t\titeration-statement -> %s %s declaration expression-opt %s expression-opt %s statement\n",$1,$2,$5,$7);}
    ;
jump-statement:GOTO IDENTIFIER SEMI_COLON
                        {printf("\t\tjump-statement -> %s identifier(%s) %s\n",$1,$2,$3);}
    | CONTINUE SEMI_COLON
                        {printf("\t\tjump-statement -> %s %s\n",$1,$2);}
    | BREAK SEMI_COLON
                        {printf("\t\tjump-statement -> %s %s\n",$1,$2);}
    | RETURN expression-opt SEMI_COLON
                        {printf("\t\tjump-statement -> %s expression-opt %s\n",$1,$3);}
    ;
/*External Definitions*/
translation-unit:external-declaration
                        {printf("\t\ttranslation-unit -> external-declaration\n");}
    | translation-unit external-declaration
                        {printf("\t\ttranslation-unit -> translation-unit external-declaration\n");}
    ;
external-declaration:function-definition
                        {printf("\t\texternal-declaration -> function-definition\n");}
    | declaration
                        {printf("\t\texternal-declaration -> declaration\n");}
    ;
function-definition:declaration-specifiers declarator declaration-list-opt compound-statement
                        {printf("\t\tfunction-definition -> declaration-specifiers declarator declaration-list-opt compound-statement\n");}
    ;
declaration-list-opt:declaration-list
                        {printf("\t\tdeclaration-list-opt -> declaration-list\n");}
    | /* empty */
                        {printf("\t\tdeclaration-list-opt -> epsilon\n");}
    ;
declaration-list:declaration
                        {printf("\t\tdeclaration-list -> declaration\n");}
    | declaration-list declaration
                        {printf("\t\tdeclaration-list -> declaration-list declaration\n");}
    ;

%%
void yyerror(char* s) {
    printf("\t\tERROR in line %d : %s\n", yylineno, s);
}
