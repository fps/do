%{
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <vector>

#include <ast.h>

#define YYSTYPE shared_ptr<node_base>

extern "C" {
	#include <y.tab.hh>
	int yyparse(void);
	int yylex(void);  
}

extern "C" {
void yyerror(const char *str)
	{
		fprintf(stderr,"error: %s\n",str);
	}
 
	int yywrap()
	{
		return 1;
	} 

}

int main() 
{
	yyparse();
}

using std::cout;
using std::endl;
using std::string;

%}

//%union {
//	char *string;
//	ast* node;
//}


%token DO 
%token DONE 
%token FLOATING_POINT_NUMBER 
%token NUMBER 
%token ASSIGNMENT_OPERATOR 
%token SEMICOLON 
%token IDENTIFIER
%token DOT
%token OPEN_BRACKET
%token CLOSING_BRACKET
%token OPEN_SQUARE_BRACKET
%token CLOSING_SQUARE_BRACKET
%token OPEN_WIGGLY_BRACKET
%token CLOSING_WIGGLY_BRACKET


%%

expressions:
	| 
	expressions expression SEMICOLON

literal:
	number
	;

expression:
	literal | do | assignment | identifier
	;

do:
	DO expressions DONE
	{
		cout << "do block " << endl;
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
		cout << "identifier " << dynamic_pointer_cast<node<string> >($1)->t << endl;
	}
	|
	identifier DOT IDENTIFIER
	{
		printf("dot\n");
	}
	;

number:
	NUMBER
	{
		cout << "number: " << dynamic_pointer_cast<node<int> >($1)->t << endl;
		$$ = $1;
	}
	|
	FLOATING_POINT_NUMBER
	{
		cout << "floating point number: " << dynamic_pointer_cast<node<double> >($1)->t << endl;
		$$ = $1;
	}
	;


        

