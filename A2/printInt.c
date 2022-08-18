#include "myl.h"
#define BUFF 20
int printInt(int n)
{
    char buff[BUFF], zero = '0';
    int i = 0, j, k, bytes;
    if (n == 0)
        buff[i++] = zero;

    else
    {
        if (n < 0)
        {
            buff[i++] = '-';
            n *= -1;
        }
        while (n)
        {
            buff[i++] = n % 10 + '0';
            n /= 10;
            if (i >= BUFF)
                return ERR;
        }
        if (buff[0] == '-')
            j = 1;
        else
            j = 0;

        k = i - 1;
        while (j < k)
        {
            char temp = buff[j];
            buff[j++] = buff[k];
            buff[k--] = temp;
        }
    }
    buff[i] = '\n';
    bytes = i + 1;
    // The __volatile__ modifier on an __asm__ block forces the compiler's optimizer to execute the code as-is. Without it, the optimizer may think it can be either removed outright, or lifted out of a loop and cached.
    __asm__ __volatile__(
        "movl $1, %%eax\n\t"
        "movq $1, %%rdi\n\t"
        "syscall\n\t"
        :
        : "S"(buff), "d"(bytes));

    return bytes;
}

// comment out if not needed
// #include <stdio.h>

// int main()
// {
//     int x = -25;
//     int ret = printInt(x);
//     if (ret == ERR)
//         printf("FAILURE\n");
//     else
//         printf("The number of characters printed = %d\n",ret);
// }