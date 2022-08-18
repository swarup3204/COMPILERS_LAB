#include "myl.h"
#define BUFF 20
#include <stdio.h>

int readInt(int *n)
{
    char in[BUFF];
    int len;
    int val = 0;

    __asm__ __volatile__(
        "movl $0, %%eax \n\t"
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=a"(len)
        : "S"(in), "d"(BUFF));

    if (len < 0)
        return ERR;

    // in stores the integer value as a string
    int i = 0;

    int sign = 1;
    if (in[i] == '-' || in[i] == '+')
    {
        sign = (in[i] == '-') ? -1 : 1;
        i++;
    }
    while (i < len && in[i] != '\n')
    {
        if (in[i] < '0' || in[i] > '9') // return error if anything other than number entered at any place
            return ERR;
        val = (val)*10 + in[i++] - '0';
    }
    val = sign * (val);
    *n = (int)val;
    return OK;
}
// comment out if not needed

// int main()
// {
//     int n;
//     int ret = readInt(&n);
//     if (ret == OK)
//         printf("The entered value is %d\n", n);
//     else
//         printf("Error\n");
// }
