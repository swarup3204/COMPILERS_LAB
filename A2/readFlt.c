#include "myl.h"
#define BUFF 20 // BUFF different for each

int readFlt(float *f)
{
    char input[BUFF];
    int len;
    __asm__ __volatile__(
        "movl $0, %%eax \n\t"
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=a"(len)
        : "S"(input), "d"(BUFF));

    if (len < 0)
        return ERR;
    // in stores the float value as a string
    int i = 0;
    int sign = 1;
    if (input[i] == '-' || input[i] == '+')
    {
        sign = (input[i] == '-') ? -1 : 1;
        i++;
    }
    int bd = 0; /// before decimal
    while (i < len && input[i] != '.' && input[i] != '\n')
    {
        if (input[i] < '0' || input[i] > '9') // return error if anything other than number entered at any place
            return ERR;
        bd = (bd)*10 + input[i++] - '0';
    }
    float ad = 0.0; // value after decimal
    if (input[i] == '.')
    {
        i++;
        float p = 10.0;
        while (i < len && input[i] != '\n')
        {
            if (input[i] < '0' || input[i] > '9') // return error if anything other than number entered at any place
                return ERR;
            ad = ad + (input[i++] - '0') / p;
            p *= 10;
        }
    }
    *f = sign * (bd + ad);
    return OK;
}
// comment out if not needed

// int main()
// {
//     float f;
//     int ret = readFlt(&f);
//     if (ret == OK)
//         printf("The entered value is %f\n", f);
//     else
//         printf("Error\n");
// }
