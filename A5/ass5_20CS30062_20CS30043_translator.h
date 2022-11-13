/*
Name : Swarup Padhi
Roll : 20CS30072
Name : Rounak Saha
Roll : 20CS30043
*/

#ifndef __ASS5_20CS30062_20CS30043_H
#define __ASS5_20CS30062_20CS30043_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <string>


using namespace std;


/*
 Sizes for basic types are listed here

 defining these size as macros as keeping them hard coded removes their machine independence
 

 as given in question these are the sizes(in bytes) to be taken for x86_64 target machine
   
 void       ------------>    undefined  (will define it be of 0 to 
                                        signify that it's size is not contributing anyway)
 char       ------------>    1
 int        ------------>    4
 pointer    ------------>    4
 float      ------------>    8


 function   ------------>    0
 some entries in ST will be function names , however size of it will be 0 
 and therefore declared a zero size for simplicity


*/
 

#define size_of_void     0
#define size_of_func     0
#define size_of_char     1
#define size_of_int      4
#define size_of_ptr      8
#define size_of_float    4


/*
    defining the operand types of TAC in an enum
*/

class symbol;
class symbol_type;
class symbol_table;
class quad;
class expression;
class statement;
class Arr;



/*
    Global variables declaration
*/
    extern symbol* present_symbol;
    extern symbol_table* present_symbol_table;
    extern symbol_table* glbl_symbol_table;
    extern vector <quad> quad_array;
    extern int count_ST;
    extern string block_name;
    extern string var_type;

// may not be needed

/*
    Class which represents a symbol in the symbol table

    symbol

    =======

    Attributes:
        name:                   string              :  name of the symbol
        type:                   symbol_type*        :  type of the symbol
        sym_val:                string              :  initial value of the symbol(null if none)
        size:                   int                 :  size of the symbol(in bytes)
        offset:                 int                 :  offset of symbol in the symbol table
        nested_table:           symbol_table*       :  pointer to nested symbol table
                                                       (needed for functions and blocks)

    Methods:
        symbol(string, symbol_type*, string, int, int, symbol_table*)
        ---> parameterized constructor
        symbol* update(symbol_type* t)      
        ----> update content of existing symbol and return a pointer to its entry in ST
*/
class symbol
{
    public:
        string name;
        symbol_type* type;
        string sym_val; 
        //declared as string because we cannot handle easily multiple types
        int size;
        int offset;
        symbol_table* nested_table;
        symbol(string name_, string t = "int", symbol_type* arrType = NULL, int width = 0);
        symbol* update(symbol_type* t);
};

/*
    Class which represents a symbol type

    symbol_type

    ===========

    Attributes:
        type:                   string              :  type of the symbol(actual type of symbol)
        width:                  int                 :  width of the symbol
                                                       (for arrays -> number of elements in array)
                                                        kept as 1 for other types
        arrType:                symbol_type*        :  type of array elements(useful for arrays)

    Methods:
        symbol_type(string, symbol_type*)
        ---> parameterized constructor
*/


class symbol_type
{
    public:
        string type;
        int width;
        symbol_type* arrType;

        symbol_type(string, symbol_type* arrType_ = NULL, int width_ = 1);
};

/*
    Class to store a symbol table structure

    symbol_table

    ============

    Attributes:
        name:                   string              :  name of the symbol table
        table:                  list<symbol*>       :  list of symbols in the symbol table
        parent:                 symbol_table*       :  pointer to parent symbol table
        tmp_cnt:                int                 :  count of temporary variables for the ST


    Methods:
        symbol_table(string name_)
        ---> parameterized constructor
        symbol* lookup(string)
        ---> returns a pointer to the symbol if found in the symbol table else new entry created
        static symbol* gentemp(symbol_type*,string*):
        ---> generates a temporary variable of the given type and initial value and returns a pointer to its entry
        void update()
        ---> updates the fileds of symbol in the symbol table
        void print()
        ----> prints the symbol table in apt format
*/
class symbol_table
{
    public:
        string name;
        int tmp_cnt;
        symbol_table* parent;
        list<symbol> table;

        // not clear
        symbol_table(string name_="null" );
        symbol* lookup(string name_);
        static symbol* gentemp(symbol_type* type_,string initValue = "");

        void print();
        void update();
};
/*

    index of quad in quad_array is address of TAC

    quads stored in format

    ==========================
    | op | arg1 | arg2 | arg3|
    ==========================
    | ...|  ... | ...  | ... |
    ==========================

    arg1 (and/or) arg2 may be a variable(address) or constant
    result is variable(address) only
    arg2 may be null

    They are represented as follows:
    =====================================
    Index || op || arg1 || arg2 || result
    =====================================
    100  || ... || ... || ... || ...
    =====================================
    101  || ... || ... || ... || ...
    =====================================

    quad

    ==========================

    Attributes:
        op:                     string              :  operator of the quad
        arg1:                   symbol*             :  first argument of the quad
        arg2:                   symbol*             :  second argument of the quad
        result:                 symbol*             :  result of the quad

    Methods:
        quad(string, string, string, string)
        ---> parameterized constructor
        quad(string, int, string, string)
        ---> parameterized constructor
        quad(string , float , string , string)
        ---> parameterized constructor
        void print()
        ---> prints the quad in apt format
*/

class quad
{
    public:
        string op;
        string arg1;
        string arg2;
        string result;

        quad(string result, string arg1, string arg2 = "", string op = "=");
        /* t = 5 */
        quad(string result, int arg1, string arg2 = "", string op = "=");
        /* t = 5.6 */
        quad(string result, float arg1, string arg2 = "", string op = "=");

        void print();
};

/*
    Arr

    ==============

    Attributes:
        category:               string              :  category of the array("ptr" or "arr")
        array_type:             symbol_type*        :  type of the array
        addr:                   symbol*             :  temp that stores 
                                                       offset of the location 
                                                       from base address
        array_entry:            symbol*             :  entry of the array in the symbol table            

*/
class Arr
{
    public:
        string category;
        symbol* addr;
        symbol* array_entry;
        symbol_type* array_type;
        
};

/*
    statement

    ==============

    Attributes:
        nextlist:               list<int>           :  list of next statements
*/
class statement
{
    public:
        list<int> nextlist;
};
/*
    expression

    =================

    Attributes:
        expr_type:                   symbol_type*        :  type of the expression
        loc:                    symbol*             :  location of the expression (pointer to symbol table entry)
        true_list:              list<int>           :  list of addresses of TACs to be executed if expression is true
        false_list:             list<int>           :  list of addresses of TACs to be executed if expression is false
        next_list:              list<int>           :  list of addresses of TACs to be executed after the expression
    
*/
class expression{
    public:
        symbol* loc;
        list<int> truelist;
        list<int> falselist;
        list<int> nextlist;
        string expr_type;
};

/*
    our printing of 3 address codes will be of the form as given in question
    i.e, L100:t1=i-1;
    where L100 is the label, t1 is the target variable
    and i-1 is the expression
*/


/*
list of global functions as required by question
in comments the i/p,o/p.algorithm and purpose explained
at function top
*/

//will put all explainations in .h only for declarations

/*
makelist(i)
merge(p1,p2)
backpatch(p,i)
typecheck(E1,E2)
conv<type1><type2>(E)
*/
list <int> makelist (int instr_addr);


list <int> merge (list <int> p1, list <int> p2);

/*
    for the addresses stored in l resolves their target address
    as instr_addr
*/

/*
    3 types of emit
    1.when everything present , result = arg1 op arg2
    2.when arg2 ,missing , unary , result = op arg1
    3.when op missing, result = arg


    overloaded for quads having integer and floating constant
*/
void emit(string op, string result, string arg1 = "", string arg2 = "");
void emit(string op, string result, int arg1, string arg2 = "");
void emit(string op, string result, float arg1, string arg2 = "");

void backpatch(list<int> l, int instr_addr);

/*
    typecheck(E1,E2)
    returns the type of the expression after type checking
    if type mismatch error is thrown
*/

bool typecheck(symbol* &s1, symbol* &s2);

/*
    function to compare actual types of two expressions
*/
bool compare_types(symbol_type* t1, symbol_type* t2);

/*
    function to change type of a symbol to a particular type
*/
symbol* change_type(symbol* sym, string typ);

/*
    converts an integer expression to a boolean expression
*/
expression* conv_int_Bool(expression* expr);
/*
    converts a boolean expression to an integer expression
*/
expression* conv_Bool_int(expression* expr);

/* 
    function to goto another table
*/
void change_table(symbol_table* table);

/*
    function to get type of a symbol in apt string format to be stored in it's type attribute
*/
string get_type(symbol_type* type);

/*
 returns address of next instruction
*/
int nextinstr();

/*
    function to print the quad_array in suitable format
*/ 

void print_quad_list();

/*
    function to return width of type in bytes
*/
int width_of_type(symbol_type*  type);

#endif
