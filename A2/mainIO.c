#include <stdio.h>
#include "myl.h"
int main()
{
    //write fail tests 
    //Fail tests
    /*  printInt.c ---> cannot print total digits (including '-') >BUFF
        printFlt.c ---> cannot print more than six digits after decimal point,also cannot print total digits(including '.' and '-')>BUFF
        printStr.c ---> cannot print more than size of BUFF,returns ERR on doing so
        readInt.c  ---> if len negative of input (failed input),cannot read in an integer greater than BUFF size(cannot read a long long value etc),also cannot have other characters than numbers in the integer
        readFlt.c  ---> if len negative of input (failed input),cannot read in a floating point value greater than size of BUFF(cannot read a double value etc),also cannot have other characters than numbers in the floating point value
    */
    

    //write pass tests
    //Pass tests
    /*
        printInt.c ---> can print total digits (including '-') <BUFF,can print negative numbers
        printFlt.c ---> can print total digits (including '-' and '.') <BUFF,can print negative numbers,can print upto 6 decimal places
        printStr.c ---> can print string of length<BUFF
        readInt.c ---> can read in an integer ,also can read negative numbers
        readFlt.c ---> can read in a float value(upto 6 decimal places) ,can also can read negative numbers
    */

    int n;
    printf("Enter an integer to read\n");
    readInt(&n);
    printf("The entered integer is\n");
    printInt(n);
    float f;
    printf("Enter a floating point number to read\n");
    readFlt(&f);
    printf("The entered floating point number is\n");
    printFlt(f);
    char *str="Hello World";
    printStr(str);
}