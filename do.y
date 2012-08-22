%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *str)
{
	fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
	return 1;
} 

main() 
{
	yyparse();
}

%}

%token DO DONE INTEGER ASSIGNMENT_OPERATOR SEMICOLON

expressions:
	| expressions expression SEMICOLON
	;

expression:
	INTEGER
	;
         
