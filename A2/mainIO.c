#include <stdio.h>
#include "myl.h"
#define BUFF 10

int main()
{
    // write fail tests
    // Fail tests
    /*  printInt.c ---> cannot print total digits (including '-') >BUFF
        printFlt.c ---> cannot print more than six digits after decimal point,also cannot print total digits(including '.' and '-')>BUFF
        printStr.c ---> cannot print more than size of BUFF,returns ERR on doing so
        readInt.c  ---> if len negative of input (failed input),cannot read in an integer greater than BUFF size(cannot read a long long value etc),also cannot have other characters than numbers in the integer
        readFlt.c  ---> if len negative of input (failed input),cannot read in a floating point value greater than size of BUFF(cannot read a double value etc),also cannot have other characters than numbers in the floating point value
    */
    // not testing greater than BUFF digits as input is not flushed off,spills over to float
    int n,ret;
    float f;
    char *str;
    printf("\n===============FAIL TESTS===============\n");
    printf("Enter an integer which different characters than numbers\n");
    ret = readInt(&n);
    if (ret == ERR)
        printf("\nError in reading\n\n");
    else
    {
        printf("\nSuccess on reading\n");
        printf("The entered integer is\n");
        ret = printInt(n);
        if (ret == ERR)
            printf("\nError on printing\n\n");
        else
            printf("Success in printing,The number of characters printed is %d\n\n", ret);
    }
  

    printf("Enter a floating point number which has different characters than numbers\n");
    ret = readFlt(&f);
    if (ret == ERR)
        printf("\nError in reading\n\n");
    else
    {
        printf("\nSuccess in reading\n");
        printf("The entered floating point number is\n");
        ret = printFlt(f);
        if (ret == ERR)
            printf("Error on printing\n\n");
        else
            printf("Success in printing, The number of characters printed is %d\n\n", ret);
    }
    printf("Enter a floating point number which has more than six decimal digits\n");
    ret = readFlt(&f);
    if (ret == ERR)
        printf("Error\n");
    else
    {
        printf("Success\n");
        printf("The entered floating point number is\n");
        ret = printFlt(f);
        if (ret == ERR)
            printf("Error\n");
        else
            printf("The number of characters printed is %d\n\n", ret);
    }
    str = "Hi this is a specifically designed fail test to show that it cannot print more than 40 characters";
    printf("\nShould display error on trying to print large strings\n");
    ret = printStr(str);
    if (ret == ERR)
        printf("\nError on printing\n\n");
    else
        printf("Success on printing, The number of characters printed is %d\n\n", ret);

    // write pass tests
    // Pass tests
    /*
        printInt.c ---> can print total digits (including '-') <BUFF,can print negative numbers
        printFlt.c ---> can print total digits (including '-' and '.') <BUFF,can print negative numbers,can print upto 6 decimal places
        printStr.c ---> can print string of length<BUFF
        readInt.c ---> can read in an integer ,also can read negative numbers
        readFlt.c ---> can read in a float value(upto 6 decimal places) ,can also can read negative numbers
    */
    printf("\n==================PASS TESTS========================\n");
    printf("\nEnter an integer to read\n");
    ret = readInt(&n);
    if (ret == ERR)
        printf("\nError in reading\n\n");
    else
    {
        printf("\nSuccess on reading\n");
        printf("The entered integer is\n");
        ret = printInt(n);
        if (ret == ERR)
            printf("\nError on printing\n\n");
        else
            printf("Success in printing,The number of characters printed is %d\n\n", ret);
    }
    printf("\nEnter a floating point number to read\n");
    ret = readFlt(&f);
    if (ret == ERR)
        printf("\nError in reading\n\n");
    else
    {
        printf("\nSuccess in reading\n");
        printf("The entered floating point number is\n");
        ret = printFlt(f);
        if (ret == ERR)
            printf("Error on printing\n\n");
        else
            printf("Success in printing, The number of characters printed is %d\n\n", ret);
    }
    str = "Hello World";
    ret = printStr(str);
    if (ret == ERR)
        printf("\nError on printing\n\n");
    else
        printf("Success on printing, The number of characters printed is %d\n\n", ret);

    return 0;
}