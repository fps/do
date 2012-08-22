%{
#include <stdio.h>
#include <y.tab.h>
%}
%%
do     return DO;
done   return DONE;
[0-9]+ return INTEGER;
:=     return ASSIGNMENT_OPERATOR;
;      return SEMICOLON;
\n     /* ignore newlines */;
[ \t]+ /* ignore tabs and spaces */;
%%

