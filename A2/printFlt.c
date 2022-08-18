#include "myl.h"
#define BUFF 10 /*to limit size of output to 10 characters*/
#define EPS 1e-6
/*EPS to check conditon to
terminate adding decimal values if they are close enough to 0*/
int printFlt(float f)
{
    char buff[BUFF], zero = '0';
    // buff stores the resultant string from float
    int i = 0, j, k, bytes;
    if (f == 0)
    {
        buff[i++] = zero;
        buff[i++] = '.';
        buff[i++] = zero;
        buff[i]= '\n';
    }
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
        // extracting part before decimal
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
        buff[i++] = '.'; // adding decimal point
        if (i >= BUFF)
            return ERR;
        j = 0;
        // extracting part after decimal point upto 6 digits
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
    if (buff[i - 1] == '.') // if nothing after decimal point,add a 0
        buff[i++] = '0';
    buff[i] = '\n'; // add linefeed at end of string
    bytes = i + 1;
    // The __volatile__ modifier on an __asm__ block forces the compiler's optimizer to execute the code as-is. Without it, the optimizer may think it can be either removed outright, or lifted out of a loop and cached.
    // calls function write to write to stdout
    __asm__ __volatile__(
        "movl $1, %%eax\n\t"
        "movq $1, %%rdi\n\t"
        "syscall\n\t"
        :
        : "S"(buff), "d"(bytes));

    return bytes;
    // returns number of characters on successful execution
}
