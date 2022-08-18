#include "myl.h"
#define BUFF 20
#define EPS 1e-6

int printFlt(float f)
{
    char buff[BUFF], zero = '0';
    int i = 0, j, k, bytes;
    if (f == 0)
        buff[i++] = zero;
    // bd <-- before decimal part of f
    // ad <-- after decimal part of f
    else
    {
        if (f < 0)
        {
            buff[i++] = '-';
            f *= -1;
        }
        int bd = (int)f;
        float ad = f - bd;
        while (bd)
        {
            buff[i++] = bd % 10 + '0';
            bd /= 10;
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
        buff[i++] = '.';
        if (i >= BUFF)
            return ERR;
        j = 0;
        while ((ad >= EPS || ad <= -EPS) && j < 6)
        {
            ad *= 10;
            buff[i++] = (int)ad + '0';
            ad -= (int)ad;
            if (i >= BUFF)
                return ERR;
            j++;
        }
    }
    buff[i] = '\n';
    bytes = i + 1;
    // printf("%s\n".buff);
    // The __volatile__ modifier on an __asm__ block forces the compiler's optimizer to execute the code as-is. Without it, the optimizer may think it can be either removed outright, or lifted out of a loop and cached.
    __asm__ __volatile__(
        "movl $1, %%eax\n\t"
        "movq $1, %%rdi\n\t"
        "syscall\n\t"
        :
        : "S"(buff), "d"(bytes));

    return bytes;
}
// returns failure if size passed greater than BUFF
// comment out if not needed

// #include <stdio.h>

// int main()
// {
//     float x = -2.987691;
//     int ret = printFlt(x);
//     if (ret == ERR)
//         printf("FAILURE\n");
//     else
//         printf("The numbers of characters printed = %d\n",ret);
// }