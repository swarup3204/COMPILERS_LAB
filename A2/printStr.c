#include "myl.h"
#define BUFF 20

int printStr(char *str)
{
    char buff[BUFF];
    int i = 0, bytes;
    // assume str is null terminated
    while (str[i] != '\0')
    {
        buff[i] = str[i];
        i++;
        if (i >= BUFF) // can read maximum of BUFF-1 characters as last character is '\n'
            return ERR;
    }
    buff[i] = '\n'; // add newline at the end of the string
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
//     char *str="HI boi I am";
//     int ret = printStr(str);
//     if (ret == ERR)
//         printf("FAILURE\n");
//     else
//         printf("The number of characters printed = %d\n",ret);
// }