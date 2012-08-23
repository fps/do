%{
#include <stdio.h>
#include <y.tab.h>
%}
%%
do                   return DO;
done                 return DONE; 
[a-zA-Z][a-zA-Z0-9]* return IDENTIFIER;
[0-9]+               return NUMBER;
":="                 return ASSIGNMENT_OPERATOR;
";"                  return SEMICOLON;
\n     /* ignore newlines */;
[ \t]+ /* ignore tabs and spaces */;
.      /* ignore no-matches */;
%%

