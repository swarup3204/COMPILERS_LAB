#include "myl.h"
#define BUFF 10
#include <stdio.h>
// keeping buff size max 10 to prevent overflow

int readInt(int *n)
{
    char input[BUFF];
    int len;
    // len stores total length of input 
    int val = 0;
    // val stores the integer read

    /* calls READ function to read from STDIN*/
    __asm__ __volatile__(
        "movl $0, %%eax \n\t"
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=a"(len)
        : "S"(input), "d"(BUFF));

    if (len < 0 || len > BUFF)
        return ERR;

    // in stores the integer value as a string
    int i = 0;

    int sign = 1;
    if (input[i] == '-' || input[i] == '+')
    {
        sign = (input[i] == '-') ? -1 : 1;
        i++;
    }
    while (i < len && input[i] != '\n')
    {
        if (input[i] < '0' || input[i] > '9') // return error if anything other than number entered at any place
            return ERR;
        val = (val)*10 + input[i++] - '0';
    }
    val = sign * (val);
    *n = (int)val;
    return OK;
}
