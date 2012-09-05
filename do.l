%{
#include <stdio.h>
#include <ast.h>
#include <y.tab.hh>
%}
%%
do                   return DO;
done                 return DONE; 
[a-zA-Z][a-zA-Z0-9]* /*yylval = (char*)yytext; */ return IDENTIFIER;
[0-9]+               return NUMBER;
[0-9]+\.[0-9]+       return FLOATING_POINT_NUMBER;
":="                 return ASSIGNMENT_OPERATOR;
";"                  return SEMICOLON;
"\."                 return DOT;
"{"                  return OPEN_WIGGLY_BRACKET;
"}"                  return CLOSING_WIGGLY_BRACKET;
"["                  return OPEN_SQUARE_BRACKET;
"]"                  return CLOSING_SQUARE_BRACKET;
"("                  return OPEN_BRACKET;
")"                  return CLOSING_BRACKET;
\n                   /* ignore newlines */;
[ \t]+               /* ignore tabs and spaces */;
.                    /* ignore no-matches */;
%%

