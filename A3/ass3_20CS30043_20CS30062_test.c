#include <stdio.h>
#include <stdlib.h>

extern int a;

const int INFINITY=1000007;

static int n=17;

void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void func(){
    return;
}
 
typedef struct {
    int data;
    Node* next;
}Node;

struct linkedlist{
    Node* head;
    int size;
};

inline int checking_keywords(int i){   
    //code that makes no sense at all only meant for testing the parset
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

int main(){
    int i1=30;
    long int i2=31;
    unsigned int i3=7;
    short i4=2;

    float f1=4.3787E+9;
    float f2=5*f1+4;
    float f3=.768267E-98;
    /*
    multiline comment nested with "double quotes"
    and 'single quote'
    */
    float f4=2.e9;
    float f5=0.67e-8;
    float f6= (i1>15)? f4:f5;

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
        i6=i1&i7;
        i7=i6|i1;
        i1=i6^i7;
        i1+=1;
    }while(i1>0);
}

