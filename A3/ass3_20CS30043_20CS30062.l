%{

#include "header.h"

%}
%option noyywrap
%option yylineno
%x single_line_comment
%x multi_line_comment

keyword                 "auto"|"enum"|"restrict"|"unsigned"|"break"|"extern"|"return"|"void"|"case"|"float"|"short"|"volatile"|"char"|"for"|"signed"|"while"|"const"|"goto"|"sizeof"|"Bool"|"continue"|"if"|"static"|"Complex"|"default"|"inline"|"struct"|"Imaginary"|"do"|"int"|"switch"|"double"|"long"|"typedef"|"else"|"register"|"union"

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

constant                {integer-constant}|{floating-constant}|{character-constant}|{enumeration-constant}

punctuator              "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"="|","|"#"|[\\]

s-char                  {escape-sequence}|[^"\n\\]
s-char-sequence         {s-char}+
string-literal          \"{s-char-sequence}?\"

token                   {punctuator}|{identifier}|{constant}|{string-literal}|{keyword}

ws                      [ \t]

%%


{keyword}               {return KEYWORD;}
{identifier}            {return IDENTIFIER;}
{integer-constant}      {return INTEGER_CONSTANT;}
{floating-constant}     {return FLOATING_CONSTANT;}
{enumeration-constant}  {return ENUMERATION_CONSTANT;}
{character-constant}    {return CHARACTER_CONSTANT;}
{string-literal}        {return STRING_LITERAL;}
{punctuator}            {return PUNCTUATOR;}

"/*"                               {BEGIN(multi_line_comment);}
<multi_line_comment>[^*\n]*        {}
<multi_line_comment>"*"+[^*/\n]*   {}
<multi_line_comment>\n             {return LINEFEED;}
<multi_line_comment>"*"+"/"        {BEGIN(INITIAL);return MULTI_LINE_COMMENT;}

"//"                              {BEGIN(single_line_comment);}
<single_line_comment>[^\n]+        {}               
<single_line_comment>\n            {BEGIN(INITIAL);return SINGLE_LINE_COMMENT;}

{ws}                    {}
[\n]                    {return LINEFEED;}
.                       {return UNKNOWN;}

