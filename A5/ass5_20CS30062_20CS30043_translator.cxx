/*
Name : Swarup Padhi
Roll : 20CS30072
Name : Rounak Saha
Roll : 20CS30043
*/

# include "ass5_20CS30062_20CS30043_translator.h"
# include <iostream>
# include <iomanip>
using namespace std;


/*
    variables declared by bison and
    therefore external
*/
extern char* yytext;
extern int yyparse();

symbol* present_symbol; 
/* this is a pointer to the symbol
we are currently using in our rules */

symbol_table* present_symbol_table;
/* this is a pointer to the symbol table
we are currently in */

symbol_table* glbl_symbol_table;
/* this is a pointer to the global symbol table ,why needed add here*/

int count_ST;
/* this is a counter to keep track of the number of symbol tables*/

string block_name;
/* this is a string to keep track of the name of the block we are in*/


string var_type;
/* this is a string to keep track of the type of the symbol we are currently using*/

vector <quad> quad_array;



/* 
    symbol class implementation
*/
symbol::symbol(string name_, string t, symbol_type* arrType, int width): name(name_), sym_val("-"), offset(0), nested_table(NULL) {
    type = new symbol_type(t, arrType, width);
    size = width_of_type(type);
}

symbol* symbol::update(symbol_type* type)
{
    this->type = type;
    this->size = width_of_type(type);
    return this;
}
/*
     symbol_type class implementation
*/
symbol_type::symbol_type(string type_, symbol_type* arrType_, int width_):
type(type_), arrType(arrType_), width(width_)
{}

/*
    symbol_table class implementation
*/


/* when created default parent is null*/
symbol_table::symbol_table(string name_):name(name_),tmp_cnt(0)
{}

symbol* symbol_table::lookup(string name)
{
    for (list<symbol>::iterator it = table.begin(); it != table.end(); it++)
    {
        if (it->name == name)
        {
            return &(*it);
        }
    }
    /*
        not found so search in parent ST and keep going up till parent is null
        global ST
    */
    symbol* x = NULL;
    if (parent != NULL)
    {
         x = parent->lookup(name);
    }

    if(x!=NULL)
    {   /*
        returning if found in any of the parent ST's
        */
        return x;
    }

    else if(present_symbol_table == this && x == NULL)
    {
        // not found in any symbol table
        // create a new entry in the current symbol table
        symbol* s = new symbol(name);
        table.push_back(*s);
        return &(table.back());
    }
    //debug statement
    // cout<<name<<" lookup unsuccessful\n";
    return NULL;

}

symbol* symbol_table::gentemp(symbol_type* type,string initial_val)
{
    string name = "t" + to_string(present_symbol_table->tmp_cnt);
    (present_symbol_table->tmp_cnt)++;
    symbol* temp = new symbol(name);

    temp->type = type;
    temp->sym_val = initial_val;
    temp->size = width_of_type(type); 
    //adding temporary to present table
    present_symbol_table->table.push_back(*temp);
    //returning the pointer to the entry
    return &(present_symbol_table->table.back());

}


void symbol_table::print()
{                     
    cout<<"=================================================================================================================\n"; 
    cout<<"Symbol Table : "<<name;         
    if(parent != NULL )
            cout<<"                                                       Parent Table : "<<parent->name<<"\n";
    else
            cout<<"                                                                          NULL          \n";

    cout<<"==================================================================================================================\n";


    //assigning a space of 24 spaces left aligned
    
    cout<<left<<setw(24)<<"Name";
    cout<<left<<setw(24)<<"Type";
    cout<<left<<setw(24)<<"Size";
    cout<<left<<setw(24)<<"Initial Value";
    cout<<left<<setw(24)<<"Offset";
    cout<<left<<setw(24)<<"Nested Table";
    cout<<"\n";

    cout<<"===================================================================================================================\n"; 

    list<symbol_table*> list_of_symbol_tables;
    for(list<symbol>::iterator it= this-> table.begin(); it!= this-> table.end(); it++)
    {
        cout<<left<<setw(24)<<it->name;
        cout<<left<<setw(24)<<get_type(it->type);
        cout<<left<<setw(24)<<it->size;
        if(it->sym_val == "")
            it->sym_val = "-";
        cout<<left<<setw(24)<<it->sym_val;
        cout<<left<<setw(24)<<it->offset;
        if(it-> nested_table != NULL)
        {
            cout<<left<<setw(24)<<it->nested_table->name;
            list_of_symbol_tables.push_back(it->nested_table);
        }
        else
        {
            cout<<left<<setw(24)<<"null";
        }
        cout<<"\n";
    }
    /*recursive calling to print the nested ST's*/
    for(list<symbol_table*>::iterator it = list_of_symbol_tables.begin(); it!= list_of_symbol_tables.end(); it++)
    {
        (*it)->print();
    }
}
void symbol_table:: update()
{
    list<symbol_table*> list_of_tables;
    int offset_;
    /*parents are already updated*/

    /*updating offsets*/

    for(list<symbol>::iterator it = table.begin(); it != table.end(); it++)
    {
        if(it == table.begin())
        {
           it->offset = 0;
           offset_ = it->size;
        }
        else{
            it->offset = offset_;
            offset_ = it->offset + it->size;
        }
        if(it->nested_table != NULL)
        {
            list_of_tables.push_back(it->nested_table);
        }
        
    }

    /*update offset of nested tables*/

    for(list<symbol_table*>::iterator it = list_of_tables.begin(); it != list_of_tables.end(); it++)
    {
        (*it)->update();
    }
}
/*
    quad class implementation
*/
quad::quad(string res, string arg1_, string operation, string arg2_): result(res), arg1(arg1_), op(operation), arg2(arg2_) {}

quad::quad(string res, int arg1_, string operation, string arg2_): result(res), op(operation), arg2(arg2_) {
    arg1 = to_string(arg1_);
}

quad::quad(string res, float arg1_, string operation, string arg2_): result(res), op(operation), arg2(arg2_) {
    arg1 = to_string(arg1_);
}

void quad::print()
{
    // considering different type of operands and therefore prinitng accordingly operator and operands
    if(op == "=")            // assignment operator     
        cout << result << " = " << arg1;
    else if(op == "*=")     // assign value to pointer *y=x
        cout << "*" << result << " = " << arg1; 
    else if(op == "[]=")   // assign value to array element y[x]=z
        cout << result << "[" << arg1 << "]" << " = " << arg2;
    else if(op == "=[]")    // assign value to array element from a another variable y=x[z]
        cout << result << " = " << arg1 << "[" << arg2 << "]";
    else if(op == "goto" || op == "param" || op == "return")   // goto, param, return statements
        cout << op << " " << result;
    else if(op == "call")   // function call
        cout << result << " = " << "call " << arg1 << ", " << arg2;
    else if(op == "LABEL")  // label for indicating start of a function
        cout << result << ": ";
    else if(op == "==" || op == "!=" || op == "<" || op == ">" || op == "<=" || op == ">=") // relational operators --> if x relop y goto z
        cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << result;
    else if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "^" || op == "|" || op == "&" || op == "<<" || op == ">>")// arithmetic operators
        cout << result << " = " << arg1 << " " << op << " " << arg2;
    else if(op == "= &" || op == "= *" || op == "= -" || op == "= ~" || op == "= !") // unary operators x = op y
        cout << result << " " << op << arg1;
    else
        cout << "Unknown Operator";
}

/*
    print_quad_list() implementation
*/


void print_quad_list()
{
    cout<<"===================================================================================================================\n";

    cout<<"Generating three address codes\n";

    cout<<"===================================================================================================================\n";

    cout<<"\n";

    
    /*print quads*/

    int cnt = 0;
    for(vector<quad>::iterator it = quad_array.begin(); it != quad_array.end(); it++)
    {

        cout<<"L"<<left<<setw(4)<<cnt<<": ";
        cout<<left<<setw(4);
        it->print();
        cnt++;
        cout<<"\n";
    }

}
int width_of_type(symbol_type*  type)
{
    if(type->type == "void")
    {
        return size_of_void;
    }
    else if(type->type == "char")
    {
        return size_of_char;
    }
    else if(type->type == "int")
    {
        return size_of_int;
    }
    else if(type->type == "float")
    {
        return size_of_float;
    }
    else if(type->type == "ptr")
    {
        return size_of_ptr;
    }
    else if(type->type == "func")
    {
        return size_of_func;
    }
    else if(type->type == "arr")
    {        
        return type->width * width_of_type(type->arrType);
    }
    else
    {
        return -1;
    }
}

string  get_type(symbol_type* type)
{
    if(type == NULL)
    {
        return "null"; 
    }
    else if(type->type == "void" || type->type == "char" || type->type == "int" || type->type == "float" || type->type == "func" || type->type == "block")
    {
        return type->type;
    }
    else if(type->type == "ptr")
    {
        return type->type + "(" + get_type(type->arrType) + ")";
    }
    else if(type->type == "arr")
    {
        return type->type + "(" + to_string(type->width) + ", " + get_type(type->arrType)+")";
    }
    else
    {
        cout<<"type is not supported and is "<<type->type<<endl;
        return "invalid";
    }
}

/*
    string type is a basic type which is either of what I have written(in other words it is not a basic type 
    as in the sense of slides)
    and arrType is like the type of the elements of the array(which can be another array or int or float)
*/

symbol* change_type(symbol* s,string t)
{
    symbol* temp = symbol_table::gentemp(new symbol_type(t));

    if(s->type->type == "char") {
        if(t == "float") {
            emit("=", temp->name, "char_to_flt(" + s->name + ")");
            return temp;
        }
        else if(t == "int") {
            emit("=", temp->name, "char_to_int(" + s->name + ")");
            return temp;
        }
        return s;
    }

    else if(s->type->type == "float") {
        if(t == "int") {
            emit("=", temp->name, "flt_to_int(" + s->name + ")");
            return temp;
        }
        else if(t == "char") {
            emit("=", temp->name, "flt_to_char(" + s->name + ")");
            return temp;
        }
        return s;
    }


    else if(s->type->type == "int") {
        if(t == "float") {
            emit("=", temp->name, "int_to_flt(" + s->name + ")");
            return temp;
        }
        else if(t == "char") {
            emit("=", temp->name, "int_to_char(" + s->name + ")");
            return temp;
        }
        return s;
    }

    return s;
}

void change_table(symbol_table *table)
{
    present_symbol_table = table;
}

int nextinstr()
{
    return quad_array.size();
}

/*
    global functions implemented as asked in question:
    1.makelist(i)
    2.merge(p1,p2)
    3.backpath(p,i)
    4.typecheck(E1,E2)
    5.conv<type1><type2>(E)
*/

list <int> makelist(int instr_addr)
{
    list<int> l(1,instr_addr);
    return l;
}

list <int> merge(list<int> p1, list<int> p2)
{
    p1.merge(p2);
    return p1;
}

void backpatch(list<int> p, int instr_addr)
{
    for(list<int>::iterator it = p.begin(); it != p.end(); it++)
    {
        quad_array[*it].result = to_string(instr_addr);
    }
}
/*
    Implementation of the typecheck functions
*/
bool typecheck(symbol* &s1, symbol* &s2) {
    symbol_type* t1 = s1->type;
    symbol_type* t2 = s2->type;

    if(compare_types(t1, t2))
        return true;
    else if(s1 = change_type(s1, t2->type))
        return true;
    else if(s2 = change_type(s2, t1->type))
        return true;
    else
        return false;
}
/*
    another function to check actual types
*/
bool compare_types(symbol_type* t1, symbol_type* t2) {
    if(t1 == NULL && t2 == NULL)
        return true;
    else if(t1 == NULL || t2 == NULL)
        return false;
    else if(t1->type != t2->type)
        return false;

    return compare_types(t1->arrType, t2->arrType);
}


/*
    implementation of emit functions

    creating quads for each type

*/
void emit(string op, string result, string arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quad_array.push_back(*q);
}

void emit(string op, string result, int arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quad_array.push_back(*q);
}

void emit(string op, string result, float arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quad_array.push_back(*q);
}


expression* conv_int_Bool(expression* expr)
{
    if (expr->expr_type != "BOOL")
    {
        expr->falselist = makelist(nextinstr());
        emit("==",expr->loc->name,"0");
        expr->truelist = makelist(nextinstr());
        emit("goto","");
    }
    return expr;
}

expression* conv_Bool_int(expression* expr)
{
    if (expr->expr_type == "BOOL")
    {
        expr->loc = symbol_table::gentemp(new symbol_type("int"));
        backpatch(expr->truelist,nextinstr());
        emit("=",expr->loc->name,"true");
        int next = nextinstr();
        emit("goto",to_string(next+1));
        backpatch(expr->falselist,nextinstr());
        emit("=",expr->loc->name,"false");
    }
    return expr;
}

int main()
{
    //initialising the global table
    count_ST = 0;
    //global ST created
    glbl_symbol_table = new symbol_table("global");
    //present ST created
    present_symbol_table = glbl_symbol_table;


    block_name = "";
    yyparse();

    glbl_symbol_table -> update();
    print_quad_list();              //TAC generation
    cout<<"=================================================================================================================\n";
    cout<<"                                                 SYMBOL TABLES                                                   \n"; 
    glbl_symbol_table -> print();   //printing symbol table
    return 0;
}

