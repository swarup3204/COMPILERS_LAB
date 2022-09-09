#include <stdio.h>
#include <stdlib.h>
#include "header.h"

extern int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyout;
extern void yyrestart();
extern int linecount, wordcount, charcount;

int main(int argc, char **argv)
{

    FILE *fp = fopen(argv[1], "r");
    FILE *ptr = fopen("output.txt", "w");
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
    int token;
    while (token = yylex())
    {
        switch (token)
        {
        case KEYWORD:
            printf("<KEYWORD, %s> ", yytext);
            fprintf(ptr,"<KEYWORD, %s> ", yytext);
            break;
        case IDENTIFIER:
            printf("<IDENTIFIER, %s> ", yytext);
            fprintf(ptr,"<IDENTIFIER, %s> ", yytext);
            break;
        case INTEGER_CONSTANT:
            printf("<INTEGER_CONSTANT, %s> ", yytext);
            fprintf(ptr,"<INTEGER_CONSTANT, %s> ", yytext);
            break;
        case FLOATING_CONSTANT:
            printf("<FLOATING_CONSTANT, %s> ", yytext);
            fprintf(ptr,"<FLOATING_CONSTANT, %s> ", yytext);
            break;
        case ENUMERATION_CONSTANT:
            printf("<ENUMERATION_CONSTANT, %s> ", yytext);
            fprintf(ptr,"<ENUMERATION_CONSTANT, %s> ", yytext);
            break;
        case CHARACTER_CONSTANT:
            printf("<CHARACTER_CONSTANT, %s> ", yytext);
            fprintf(ptr,"<CHARACTER_CONSTANT, %s> ", yytext);
            break;
        case STRING_LITERAL:
            printf("<STRING_LITERAL, %s> ", yytext);
            fprintf(ptr,"<STRING_LITERAL, %s> ", yytext);
            break;
        case PUNCTUATOR:
            printf("<PUNCTUATOR, %s> ", yytext);
            fprintf(ptr,"<PUNCTUATOR, %s> ", yytext);
            break;
        case SINGLE_LINE_COMMENT:
            printf("<SINGLE_LINE_COMMENT>\n");
            fprintf(ptr,"<SINGLE_LINE_COMMENT>\n");
            break;
        case MULTI_LINE_COMMENT:
            printf("<MULTI_LINE_COMMENT>\n");
            fprintf(ptr,"<MULTI_LINE_COMMENT>\n");
            break;
        case LINEFEED:
            printf("\n");
            fprintf(ptr,"\n");
            break;
        case UNKNOWN:
            printf("<UNKNOWN, %s> ", yytext);
            fprintf(ptr,"<UNKNOWN, %s> ", yytext);
            break;
        }
    }

    fclose(fp);
    fclose(ptr);
    return 0;
}
