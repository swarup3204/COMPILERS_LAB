#include <stdio.h>
extern int yyparse();

extern void yyrestart();


int main(int argc, char **argv)
{

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    else
    {
        printf("File %s opened successfully\n", argv[1]);
    }
    yyrestart(fp);
    printf("Parsing line number 1:\n\n");
    yyparse();

    fclose(fp);
    return 0;
}