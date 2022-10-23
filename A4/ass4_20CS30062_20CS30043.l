%{

#include <stdio.h>
#include "ass4_20CS30062_20CS30043.tab.h"
extern YYSTYPE yylval;
%}
%option noyywrap
%option yylineno
%x single_line_comment
%x multi_line_comment


digit                   [0-9]
nonzero-digit           [1-9]
identifier-nondigit     [a-zA-Z_]
identifier              {identifier-nondigit}({identifier-nondigit}|{digit})*

integer-constant        {nonzero-digit}{digit}*|"0"

enumeration-constant    {identifier}

sign                    [+-]
digit-sequence          {digit}+
fractional-constant     (({digit-sequence})?\.{digit-sequence})|{digit-sequence}\.
exponent-part           (e|E)({sign})?{digit-sequence}
floating-constant       {fractional-constant}({exponent-part})?|{digit-sequence}{exponent-part}

escape-sequence         "\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"

c-char                  {escape-sequence}|[^'\n\\]
c-char-sequence         {c-char}+
character-constant      \'{c-char-sequence}\'



s-char                  {escape-sequence}|[^"\n\\]
s-char-sequence         {s-char}+
string-literal          \"{s-char-sequence}?\"


ws                      [ \t]

%%

"sizeof"                {yylval.stringval=strdup(yytext);return SIZEOF;}
"extern"                {yylval.stringval=strdup(yytext);return EXTERN;}
"static"                {yylval.stringval=strdup(yytext);return STATIC;}
"auto"                  {yylval.stringval=strdup(yytext);return AUTO;}
"register"              {yylval.stringval=strdup(yytext);return REGISTER;}
"void"                  {yylval.stringval=strdup(yytext);return VOID;}
"char"                  {yylval.stringval=strdup(yytext);return CHAR;}
"short"                 {yylval.stringval=strdup(yytext);return SHORT;}
"int"                   {yylval.stringval=strdup(yytext);return INT;}
"long"                  {yylval.stringval=strdup(yytext);return LONG;}
"float"                 {yylval.stringval=strdup(yytext);return FLOAT;}
"double"                {yylval.stringval=strdup(yytext);return DOUBLE;}
"signed"                {yylval.stringval=strdup(yytext);return SIGNED;}
"unsigned"              {yylval.stringval=strdup(yytext);return UNSIGNED;}
"_Bool"                 {yylval.stringval=strdup(yytext);return BOOL;}
"_Complex"              {yylval.stringval=strdup(yytext);return COMPLEX;}
"_Imaginary"            {yylval.stringval=strdup(yytext);return IMAGINARY;}
"enum"                  {yylval.stringval=strdup(yytext);return ENUM;}
"const"                 {yylval.stringval=strdup(yytext);return CONST;}
"restrict"              {yylval.stringval=strdup(yytext);return RESTRICT;}
"volatile"              {yylval.stringval=strdup(yytext);return VOLATILE;}
"inline"                {yylval.stringval=strdup(yytext);return INLINE;}
"case"                  {yylval.stringval=strdup(yytext);return CASE;}
"default"               {yylval.stringval=strdup(yytext);return DEFAULT;}
"if"                    {yylval.stringval=strdup(yytext);return IF;}
"else"                  {yylval.stringval=strdup(yytext);return ELSE;}
"switch"                {yylval.stringval=strdup(yytext);return SWITCH;}
"while"                 {yylval.stringval=strdup(yytext);return WHILE;}
"do"                    {yylval.stringval=strdup(yytext);return DO;}
"for"                   {yylval.stringval=strdup(yytext);return FOR;}
"goto"                  {yylval.stringval=strdup(yytext);return GOTO;}
"continue"              {yylval.stringval=strdup(yytext);return CONTINUE;}
"break"                 {yylval.stringval=strdup(yytext);return BREAK;}
"return"                {yylval.stringval=strdup(yytext);return RETURN;}

{identifier}            {yylval.stringval=strdup(yytext);return IDENTIFIER;}
{integer-constant}      {yylval.intval=atoi(yytext);return INT_CONSTANT;}
{floating-constant}     {yylval.doubleval=atof(yytext);return FLOAT_CONSTANT;}
{character-constant}    {yylval.charval=yytext[0];;return CHAR_CONSTANT;}
{string-literal}        {yylval.stringval=strdup(yytext);return STRING_LITERAL;}

"["                     {yylval.stringval=strdup(yytext);return LEFT_SQUARE_BRACKET;}
"]"                     {yylval.stringval=strdup(yytext);return RIGHT_SQUARE_BRACKET;}
"."                     {yylval.stringval=strdup(yytext);return DOT;}
"->"                    {yylval.stringval=strdup(yytext);return ARROW;}
"++"                    {yylval.stringval=strdup(yytext);return UNARY_INCREMENT;}
"--"                    {yylval.stringval=strdup(yytext);return UNARY_DECREMENT;}
","                     {yylval.stringval=strdup(yytext);return COMMA;}
":"                     {yylval.stringval=strdup(yytext);return COLON;}
";"                     {yylval.stringval=strdup(yytext);return SEMI_COLON;}
"&"                     {yylval.stringval=strdup(yytext);return AMPERSAND;}
"*"                     {yylval.stringval=strdup(yytext);return ASTERISK;}
"+"                     {yylval.stringval=strdup(yytext);return PLUS;}
"-"                     {yylval.stringval=strdup(yytext);return MINUS;}
"~"                     {yylval.stringval=strdup(yytext);return TILDE;}
"!"                     {yylval.stringval=strdup(yytext);return EXCLAMATION;}
"/"                     {yylval.stringval=strdup(yytext);return DIVIDE;}
"%"                     {yylval.stringval=strdup(yytext);return PERCENT;}
"<<"                    {yylval.stringval=strdup(yytext);return LEFT_SHIFT;}
">>"                    {yylval.stringval=strdup(yytext);return RIGHT_SHIFT;}
"<"                     {yylval.stringval=strdup(yytext);return LESS_THAN;}
">"                     {yylval.stringval=strdup(yytext);return GREATER_THAN;}
"<="                    {yylval.stringval=strdup(yytext);return LESS_THAN_EQUAL;}
">="                    {yylval.stringval=strdup(yytext);return GREATER_THAN_EQUAL;}
"=="                    {yylval.stringval=strdup(yytext);return DOUBLE_EQUAL;}
"!="                    {yylval.stringval=strdup(yytext);return NOT_EQUAL;}
"|"                     {yylval.stringval=strdup(yytext);return PIPE;}
"^"                     {yylval.stringval=strdup(yytext);return CARET;}
"&&"                    {yylval.stringval=strdup(yytext);return LOGICAL_AND;}
"||"                    {yylval.stringval=strdup(yytext);return LOGICAL_OR;}
"?"                     {yylval.stringval=strdup(yytext);return QUESTION;}
"="                     {yylval.stringval=strdup(yytext);return EQUAL;}
"*="                    {yylval.stringval=strdup(yytext);return ASTERISK_EQUAL;}
"/="                    {yylval.stringval=strdup(yytext);return DIVIDE_EQUAL;}
"%="                    {yylval.stringval=strdup(yytext);return PERCENT_EQUAL;}
"+="                    {yylval.stringval=strdup(yytext);return PLUS_EQUAL;}
"-="                    {yylval.stringval=strdup(yytext);return MINUS_EQUAL;}
"<<="                   {yylval.stringval=strdup(yytext);return LEFT_SHIFT_EQUAL;}
">>="                   {yylval.stringval=strdup(yytext);return RIGHT_SHIFT_EQUAL;}
"&="                    {yylval.stringval=strdup(yytext);return AMPERSAND_EQUAL;}
"^="                    {yylval.stringval=strdup(yytext);return CARET_EQUAL;}
"|="                    {yylval.stringval=strdup(yytext);return PIPE_EQUAL;}
"..."                   {yylval.stringval=strdup(yytext);return ELLIPSIS;}
"{"                     {yylval.stringval=strdup(yytext);return LEFT_CURLY_BRACKET;}
"}"                     {yylval.stringval=strdup(yytext);return RIGHT_CURLY_BRACKET;}
"("                     {yylval.stringval=strdup(yytext);return LEFT_ROUND_BRACKET;}
")"                     {yylval.stringval=strdup(yytext);return RIGHT_ROUND_BRACKET;}

"/*"                               {BEGIN(multi_line_comment);}
<multi_line_comment>[^*\n]*        {}
<multi_line_comment>"*"+[^*/\n]*   {}
<multi_line_comment>\n             {printf("Parsing line number %d:\n\n", yylineno);}
<multi_line_comment>"*"+"/"        {BEGIN(INITIAL);}

"//"                               {BEGIN(single_line_comment);}
<single_line_comment>[^\n]+        {}               
<single_line_comment>\n            {BEGIN(INITIAL);printf("Parsing line number %d:\n\n", yylineno);}

{ws}                    {}
[\n]                    {
                            printf("Parsing line number %d:\n\n", yylineno);
                        }
.                       {
                            printf("Invalid token: %s | syntax error detected at line number %d\n", yytext, yylineno);
                            return UNKNOWN;
                        }

