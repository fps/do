%{
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <vector>

typedef struct node_base {
	std::vector<boost::shared_ptr<node_base> > nodes;

	virtual ~node_base() { }
} node_base;

template <class T>
struct node : node_base {
	T value;

	node(T t) : value(t) { }
};

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
main() 
{
	yyparse();
}

using std::cout;
using std::endl;

%}

%union {
	char *string;
	node_base *node;
}


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

%type <string> IDENTIFIER 

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
		cout << "identifier " << $1 << endl;
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
		printf("number\n");
	}
	|
	FLOATING_POINT_NUMBER
	{
		printf("floating point number\n");
	}
	;


        

