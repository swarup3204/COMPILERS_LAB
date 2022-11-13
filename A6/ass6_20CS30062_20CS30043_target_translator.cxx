#include "ass6_20CS30062_20CS30043_translator.h"
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;


extern symbol_table global_symbol_table;
extern symbol_table* ST;
extern quad_array quadList;

void print_global(ofstream& sfile);
void print_strings(ofstream& sfile);
void set_labels();
void generate_prologue(int memBind, ofstream& sfile);
void quad_code(quad q, ofstream& sfile);
void generate_TC(ofstream& sfile);




vector<string> string_constants;
map<int, string> labels;
stack<pair<string, int>> params;
int label_count = 0;
string current_function = "";
string fname;


void generate_TC(ofstream& sfile) {
    /*
    generates targer assembly code
    */
    print_global(sfile);
    print_strings(sfile);
    symbol_table* currFuncTable = NULL;
    symbol* currFunc = NULL;
    set_labels();

    for(int i = 0; i < (int)quadList.quads.size(); i++) {

        if(labels.count(i))
            sfile << labels[i] << ":" << endl;


        if(quadList.quads[i].op == FUNC_BEG) {
            i++;
            if(quadList.quads[i].op != FUNC_END)
                i--;
            else
                continue;
            currFunc = global_symbol_table.searchGlobal(quadList.quads[i].result);
            currFuncTable = currFunc->nestedTable;
            int takingParam = 1, memBind = 16;
            ST = currFuncTable;
            for(int j = 0; j < (int)currFuncTable->symbols.size(); j++) {
                if(currFuncTable->symbols[j]->name == "RETVAL") {
                    takingParam = 0;
                    memBind = 0;
                    if(currFuncTable->symbols.size() > j + 1)
                        memBind = -currFuncTable->symbols[j + 1]->size;
                }
                else {
                    if(!takingParam) {
                        currFuncTable->symbols[j]->offset = memBind;
                        if(currFuncTable->symbols.size() > j + 1)
                            memBind -= currFuncTable->symbols[j + 1]->size;
                    }
                    else {
                        currFuncTable->symbols[j]->offset = memBind;
                        memBind += 8;
                    }
                }
            }
            if(memBind >= 0)
                memBind = 0;
            else
                memBind *= -1;
            current_function = quadList.quads[i].result;
            generate_prologue(memBind, sfile);
        }

        // generate function epilogue
        else if(quadList.quads[i].op == FUNC_END) {
            ST = &global_symbol_table;
            current_function = "";
            sfile << "\tleave" << endl;
            sfile << "\tret" << endl;
            sfile << "\t.size\t" << quadList.quads[i].result << ", .-" << quadList.quads[i].result << endl;
        }

        if(current_function != "")
            quad_code(quadList.quads[i], sfile);
    }
}


void quad_code(quad q, ofstream& sfile) {
    /*
    generates assembly code for given quad
    */
    string strLabel = q.result;
    bool hasStrLabel = (q.result[0] == '.' && q.result[1] == 'L' && q.result[2] == 'C');
    string toPrint1 = "", toPrint2 = "", toPrintRes = "";
    int off1 = 0, off2 = 0, offRes = 0;

    symbol* loc1 = ST->lookup(q.arg1);
    symbol* loc2 = ST->lookup(q.arg2);
    symbol* loc3 = ST->lookup(q.result);
    symbol* glb1 = global_symbol_table.searchGlobal(q.arg1);
    symbol* glb2 = global_symbol_table.searchGlobal(q.arg2);
    symbol* glb3 = global_symbol_table.searchGlobal(q.result);

    if(ST != &global_symbol_table) {
        if(glb1 == NULL)
            off1 = loc1->offset;
        if(glb2 == NULL)
            off2 = loc2->offset;
        if(glb3 == NULL)
            offRes = loc3->offset;

        if(q.arg1[0] < '0' || q.arg1[0] > '9') {
            if(glb1 != NULL)
                toPrint1 = q.arg1 + "(%rip)";
            else
                toPrint1 = to_string(off1) + "(%rbp)";
        }
        if(q.arg2[0] < '0' || q.arg2[0] > '9') {
            if(glb2 != NULL)
                toPrint2 = q.arg2 + "(%rip)";
            else
                toPrint2 = to_string(off2) + "(%rbp)";
        }
        if(q.result[0] < '0' || q.result[0] > '9') {
            if(glb3 != NULL)
                toPrintRes = q.result + "(%rip)";
            else
                toPrintRes = to_string(offRes) + "(%rbp)";
        }
    }
    else {
        toPrint1 = q.arg1;
        toPrint2 = q.arg2;
        toPrintRes = q.result;
    }

    if(hasStrLabel)
        toPrintRes = strLabel;

    if(q.op == ASSIGN) {
        if(q.result[0] != 't' || loc3->type.type == INT || loc3->type.type == POINTER) {
            if(loc3->type.type != POINTER) {
                if(q.arg1[0] < '0' || q.arg1[0] > '9')
                {
                    sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
                    sfile << "\tmovl\t%eax, " << toPrintRes << endl; 
                }
                else
                    sfile << "\tmovl\t$" << q.arg1 << ", " << toPrintRes << endl;
            }
            else {
                sfile << "\tmovq\t" << toPrint1 << ", %rax" << endl;
                sfile << "\tmovq\t%rax, " << toPrintRes << endl; 
            }
        }
        else {
            int temp = q.arg1[0];
            sfile << "\tmovb\t$" << temp << ", " << toPrintRes << endl;
        }
    }
    else if(q.op == U_MINUS) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tnegl\t%eax" << endl;
        sfile << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if(q.op == ADD) {
        if(q.arg1[0] > '0' && q.arg1[0] <= '9')
            sfile << "\tmovl\t$" << q.arg1 << ", %eax" << endl;
        else
            sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl; 
        if(q.arg2[0] > '0' && q.arg2[0] <= '9')
            sfile << "\tmovl\t$" << q.arg2 << ", %edx" << endl;
        else
            sfile << "\tmovl\t" << toPrint2 << ", %edx" << endl; 
        sfile << "\taddl\t%edx, %eax" << endl;
        sfile << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if(q.op == SUB) {
        if(q.arg1[0] > '0' && q.arg1[0] <= '9')
            sfile << "\tmovl\t$" << q.arg1 << ", %edx" << endl;
        else
            sfile << "\tmovl\t" << toPrint1 << ", %edx" << endl; 
        if(q.arg2[0]>'0' && q.arg2[0]<='9')
            sfile << "\tmovl\t$" << q.arg2 << ", %eax" << endl;
        else
            sfile << "\tmovl\t" << toPrint2 << ", %eax" << endl; 
        sfile << "\tsubl\t%eax, %edx" << endl;
        sfile << "\tmovl\t%edx, %eax" << endl;
        sfile << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if(q.op == MULT) {
        if(q.arg1[0] > '0' && q.arg1[0] <= '9')
            sfile << "\tmovl\t$" << q.arg1 << ", %eax" << endl;
        else
            sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl; 
        sfile << "\timull\t";
        if(q.arg2[0] > '0' && q.arg2[0] <= '9')
            sfile << "$" << q.arg2 << ", %eax" << endl;
        else
            sfile << toPrint2 << ", %eax" << endl;
        sfile << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if(q.op == DIV) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcltd\n\tidivl\t" << toPrint2 << endl;
        sfile << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if(q.op == MOD) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcltd\n\tidivl\t" << toPrint2 << endl;
        sfile << "\tmovl\t%edx, " << toPrintRes << endl;
    }
    else if(q.op == GOTO)
        sfile << "\tjmp\t" << q.result << endl;
    else if(q.op == GOTO_LT) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        sfile << "\tjge\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_GT) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        sfile << "\tjle\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_GTE) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        sfile << "\tjl\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_LTE) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        sfile << "\tjg\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_GTE) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        sfile << "\tjl\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_EQ) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        if(q.arg2[0] >= '0' && q.arg2[0] <= '9')
            sfile << "\tcmpl\t$" << q.arg2 << ", %eax" << endl;
        else
            sfile << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        sfile << "\tjne\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_NEQ) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        sfile << "\tje\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == IF_GOTO) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcmpl\t$0" << ", %eax" << endl;
        sfile << "\tje\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == IF_FALSE_GOTO) {
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tcmpl\t$0" << ", %eax" << endl;
        sfile << "\tjne\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == ARR_IDX_ARG) {
        sfile << "\tmovl\t" << toPrint2 << ", %edx" << endl;
        sfile << "cltq" << endl;
        if(off1 < 0) {
            sfile << "\tmovl\t" << off1 << "(%rbp,%rdx,1), %eax" << endl;
            sfile << "\tmovl\t%eax, " << toPrintRes << endl;
        }
        else {
            sfile << "\tmovq\t" << off1 << "(%rbp), %rdi" << endl;
            sfile << "\taddq\t%rdi, %rdx" << endl;
            sfile << "\tmovq\t(%rdx) ,%rax" << endl;
            sfile << "\tmovq\t%rax, " << toPrintRes << endl;
        }
    }
    else if(q.op == ARR_IDX_RES) {
        sfile << "\tmovl\t" << toPrint2 << ", %edx" << endl;
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "cltq" << endl;
        if(offRes > 0) {
            sfile << "\tmovq\t" << offRes << "(%rbp), %rdi" << endl;
            sfile << "\taddq\t%rdi, %rdx" << endl;
            sfile << "\tmovl\t%eax, (%rdx)" << endl;
        }
        else
            sfile << "\tmovl\t%eax, " << offRes << "(%rbp,%rdx,1)" << endl;
    }
    else if(q.op == REFERENCE) {
        if(off1 < 0) {
            sfile << "\tleaq\t" << toPrint1 << ", %rax" << endl;
            sfile << "\tmovq\t%rax, " << toPrintRes << endl;
        }
        else {
            sfile << "\tmovq\t" << toPrint1 << ", %rax" << endl;
            sfile << "\tmovq\t%rax, " << toPrintRes << endl;
        }
    }
    else if(q.op == DEREFERENCE) {
        sfile << "\tmovq\t" << toPrint1 << ", %rax" << endl;
        sfile << "\tmovq\t(%rax), %rdx" << endl;
        sfile << "\tmovq\t%rdx, " << toPrintRes << endl;
    }
    else if(q.op == L_DEREF) {
        sfile << "\tmovq\t" << toPrintRes << ", %rdx" << endl;
        sfile << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        sfile << "\tmovl\t%eax, (%rdx)" << endl;
    }
    else if(q.op == PARAM) {
        int paramSize;
        DataType t;
        if(glb3 != NULL)
            t = glb3->type.type;
        else
            t = loc3->type.type;
        if(t == INT)
            paramSize = __INTEGER_SIZE;
        else if(t == CHAR)
            paramSize = __CHARACTER_SIZE;
        else
            paramSize = __POINTER_SIZE;
        stringstream ss;
        if(q.result[0] == '.')
            ss << "\tmovq\t$" << toPrintRes << ", %rax" <<endl;
        else if(q.result[0] >= '0' && q.result[0] <= '9')
            ss << "\tmovq\t$" << q.result << ", %rax" <<endl;
        else {
            if(loc3->type.type != ARRAY) {
                if(loc3->type.type != POINTER)
                    ss << "\tmovq\t" << toPrintRes << ", %rax" <<endl;
                else if(loc3 == NULL)
                    ss << "\tleaq\t" << toPrintRes << ", %rax" <<endl;
                else
                    ss << "\tmovq\t" << toPrintRes << ", %rax" <<endl;
            }
            else {
                if(offRes < 0)
                    ss << "\tleaq\t" << toPrintRes << ", %rax" <<endl;
                else {
                    ss << "\tmovq\t" << offRes << "(%rbp), %rdi" <<endl;
                    ss << "\tmovq\t%rdi, %rax" <<endl;
                }
            }
        }
        params.push(make_pair(ss.str(), paramSize));
    }
    else if(q.op == CALL) {
        int numParams = atoi(q.arg1.c_str());
        int totalSize = 0, k = 0;


        if(numParams > 6) {
            for(int i = 0; i < numParams - 6; i++) {
                string s = params.top().first;
                sfile << s << "\tpushq\t%rax" << endl;
                totalSize += params.top().second;
                params.pop();
            }
            sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %r9d" << endl;
            totalSize += params.top().second;
            params.pop();
            sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %r8d" << endl;
            totalSize += params.top().second;				
            params.pop();
            sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rcx" << endl;
            totalSize += params.top().second;
            params.pop();
            sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rdx" << endl;
            totalSize += params.top().second;
            params.pop();
            sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rsi" << endl;
            totalSize += params.top().second;
            params.pop();
            sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rdi" << endl;
            totalSize += params.top().second;
            params.pop();
        }
        else {
            while(!params.empty()) {
                if(params.size() == 6) {
                    sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %r9d" << endl;
                    totalSize += params.top().second;
                    params.pop();
                }
                else if(params.size() == 5) {
                    sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %r8d" << endl;
                    totalSize += params.top().second;
                    params.pop();
                }
                else if(params.size() == 4) {
                    sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rcx" << endl;
                    totalSize += params.top().second;
                    params.pop();
                }
                else if(params.size() == 3) {
                    sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rdx" << endl;
                    totalSize += params.top().second;
                    params.pop();
                }
                else if(params.size() == 2) {
                    sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rsi" << endl;
                    totalSize += params.top().second;
                    params.pop();
                }
                else if(params.size() == 1) {
                    sfile << params.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rdi" << endl;
                    totalSize += params.top().second;
                    params.pop();
                }
            }
        }
        sfile << "\tcall\t" << q.result << endl;
        if(q.arg2 != "")
            sfile << "\tmovq\t%rax, " << toPrint2 << endl;
        sfile << "\taddq\t$" << totalSize << ", %rsp" << endl;
    }
    else if(q.op == RETURN) {
        if(q.result != "")
            sfile << "\tmovq\t" << toPrintRes << ", %rax" << endl;
        sfile << "\tleave" << endl;
        sfile << "\tret" << endl;
    }

}


void print_global(ofstream& sfile) {
    for(vector<symbol*>::iterator it = global_symbol_table.symbols.begin(); it != global_symbol_table.symbols.end(); it++) {
        symbol* sym = *it;
        if(sym->type.type == CHAR && sym->name[0] != 't') {
            if(sym->initVal != NULL) {
                sfile << "\t.globl\t" << sym->name << endl;
                sfile << "\t.data" << endl;
                sfile << "\t.type\t" << sym->name << ", @object" << endl;
                sfile << "\t.size\t" << sym->name << ", 1" << endl;
                sfile << sym->name << ":" << endl;
                sfile << "\t.byte\t" << sym->initVal->c << endl;
            }
            else
                sfile << "\t.comm\t" << sym->name << ",1,1" << endl;
        }
        else if(sym->type.type == INT && sym->name[0] != 't') {
            if(sym->initVal != NULL) {
                sfile << "\t.globl\t" << sym->name << endl;
                sfile << "\t.data" << endl;
                sfile << "\t.align\t4" << endl;
                sfile << "\t.type\t" << sym->name << ", @object" << endl;
                sfile << "\t.size\t" << sym->name << ", 4" << endl;
                sfile << sym->name << ":" << endl;
                sfile << "\t.long\t" << sym->initVal->i << endl;
            }
            else
                sfile << "\t.comm\t" << sym->name << ",4,4" << endl;
        }
    }
}


void print_strings(ofstream& sfile) {
    /*
    function to print the list of strings used in the program
    */
    sfile << ".section\t.rodata" << endl;
    int i = 0;
    for(vector<string>::iterator it = string_constants.begin(); it != string_constants.end(); it++) {
        sfile << ".LC" << i++ << ":" << endl;
        sfile << "\t.string " << *it << endl;
    }
}

void set_labels() {
    /*
    generates the labels for goto statements
    */
    int i = 0;
    for(vector<quad>::iterator it = quadList.quads.begin(); it != quadList.quads.end(); it++) {
        if(it->op == GOTO || (it->op >= GOTO_EQ && it->op <= IF_FALSE_GOTO)) {
            int target = atoi((it->result.c_str()));
            if(!labels.count(target)) {
                string labelName = ".L" + to_string(label_count++);
                labels[target] = labelName;
            }
            it->result = labels[target];
        }
    }
}


void generate_prologue(int memBind, ofstream& sfile) {
    /*
    function to print function prologue
    */
    int width = 16;
    sfile << endl << "\t.text" << endl;
    sfile << "\t.globl\t" << current_function << endl;
    sfile << "\t.type\t" << current_function << ", @function" << endl;
    sfile << current_function << ":" << endl;
    sfile << "\tpushq\t" << "%rbp" << endl;
    sfile << "\tmovq\t" << "%rsp, %rbp" << endl;
    sfile << "\tsubq\t$" << (memBind / width + 1) * width << ", %rsp" << endl;
}



int main(int argc, char* argv[]) {
    ST = &global_symbol_table;
    yyparse();

    fname = "ass6_20CS30062_20CS30043_" + string(argv[argc - 1]) + ".s";
    ofstream sfile;
    sfile.open(fname);

    quadList.print();               

    ST->print("ST.global");     

    ST = &global_symbol_table;

    generate_TC(sfile);    

    sfile.close();

    return 0;
}
