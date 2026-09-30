%option noyywrap
%{
#include<stdio.h>
%}
literal (true|false|null)
z [0-9]
num [+-]?({z}*\.|{z}*\.{z}*|{z}*)((e|E)[-+]?{z}*)?(f|F|l|L)?
%%
\{ {printf("(BEGIN_OBJECT, \'{\')\n");}
\} {printf("(END_OBJECT, \'}\')\n");}
\[ {printf("(BEGIN_ARRAY, \'[\')\n");}
\] {printf("(END_ARRAY, \']\')\n");}
, {printf("(COMMA, \',\')\n");}
: {printf("(COLON, \':\')\n");}
{literal} {printf("(LITERAL, \'%s\')\n", yytext);}
\"[^\"]*\" {printf("(STRING, \'%s\')\n", yytext);}
{num} {printf("(NUMBER, \'%s\')\n", yytext);}
%%
main()
{
printf("Enter a string\n");
yylex();
}