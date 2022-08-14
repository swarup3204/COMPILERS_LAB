#include "myl.h"
#define BUFF 20
int printInt(int *n)
{
    char buff[BUFF], zero = '0';
    int i = 0, j, k, bytes;
    if (*n == 0)
        buff[i++] = zero;

    else
    {
        if (*n < 0)
        {
            buff[i++] = '-';
            *n *= -1;
        }
        while (*n)
        {
            buff[i++] = *n % 10 + '0';
            *n /= 10;
        }
        if(buff[0] == '-')
            j = 1;
        else
            j = 0;
        
        k=i-1;
        while(j < k)
        {
            char temp = buff[j];
            buff[j++] = buff[k];
            buff[k--] = temp;
        }
    }
    buff[i]='\n';
    bytes = i+1;

    __asm____volatile__(
    );

    return ERR;
}