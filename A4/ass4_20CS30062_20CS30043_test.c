/*
Compilers 2022 Assignment 4 1test file
20CS30043 Rounak Saha
20CS30062 Swarup Padhi
*/


const int INFINITY=1000007;
enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};


void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void func(){
    node.val++;
    node_add=&node;
    node_add->val--;
    return;
}


inline int checking_some_keywords(int i, ...){   
    //code that makes no sense at all, only meant for testing the parser
    if (i==12) return 12;
    else{
        for(int k=0;k<5;++k){
            if(i==9)
                continue;
            i++;
            break;
        }
    }

    int f=0;
    while(i>=0){
        f+=i;
        i--;
    }

    switch (f)
    {
        case 0:
            func();
            break;
        
        case 1:
            func();
            break;
        default:
            break;
    }
}

void checking_some_storage_types(int arr[], char* chr){
    volatile double cst0;
    auto int cst1=5;
    static double _Complex cst2;
    register double cst3;
    extern int cst4;
    double _Imaginary cst5;

    _Bool cst6=0;
    while(cst6){
        cst6=!cst6;
    }
}

int main(){
    int i1=30;
    long int i2=31;
    unsigned int i3=sizeof(int);
    short i4=2;
    i2+=23;
    i1-=2;
    i3%=i2;

    float f1=4.3787E+9;
    float f2=5*f1+4;
    float f3=.768267E-98;

    double d1=56.329752;
    double d2=d1*5.987-2;
    double d3=4.654e-34;
    d2*=(d2-d1);
    d3/=d2;

    if((d2-d1>d3) && ((f1==f2) || (i2%3 != 2))){
        /* 
        do nothing, this is only for
        checking multiline comment 
        */
    }

    /*
    multiline comment nested with "double quotes"
    and 'single quote'
    */
    float f4=2.e9;
    float f5=0.67e-8;
    float f6= (i1>15)? f4:f5;

    enum week day;
    day = Wed;

    char c1='a';
    char c2='compilerslab2022a';
    char c3='assgn\'number\'3';

    char s0[]="";
    char s1[]="hello\nbye";
    char s2[]="to test \"if this works\" !";

    // comment nested with "double quotes" and 'single quotes'

    int i5,i6,i7=90;
    do{
        i1 >>=2;
        i6=i1&(~i7);
        i7=i6|i1;
        i1=i6^i7;
        i1+=1;
        i1=i1<<2;
        i1>>=2;

    }while(i1>0);

    int idx=0;
    WHILE_LABEL:
    idx++;
    if(idx<10) goto WHILE_LABEL;
}

