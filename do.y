%{
#include <stdio.h>
#include <string.h>
#include <y.tab.h>

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

%token DO DONE NUMBER ASSIGNMENT_OPERATOR SEMICOLON IDENTIFIER

%%

expressions:
	| expressions expression SEMICOLON

literal:
	number
	;

expression:
	literal
	|
	do
	|
	assignment
	|
	identifier
	;

do:
	DO expressions DONE
	{
		printf("do block\n");
	}
	;
	
assignment:
	identifier ASSIGNMENT_OPERATOR expression
	{
		printf("assignment\n");
	}
	;

identifier:
	IDENTIFIER
	{
		printf("identifier\n");
	}
	;

number:
	NUMBER
	{
		printf("number\n");
	}
	;


        

