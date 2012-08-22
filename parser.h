// #include <boost/spirit/include/qi.hpp>

#include <iostream>

#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

/*
	forward declaration to allow circular dependencies
*/

template<class Iterator, class Skipper>
struct do_expression;

template<class Iterator, class Skipper>
struct do_expression_list;

template<class Iterator, class Skipper>
struct do_block;

template<class Iterator, class Skipper>
struct do_grammar;

/*
	grammars
*/

#if 0
template<class Iterator, class Skipper>
struct do_expression : qi::grammar<Iterator, Skipper>{
	do_expression(do_expression_list<Iterator, Skipper> *exp_list) : 
		do_expression::base_type(expression, "do"), 
		expression_list(exp_list)
	{
		expression =      do_expression<Iterator, Skipper>(*exp_list) 
		                | *expression_list 
		                | do_block<Iterator, Skipper>()
		                | qi::double_;
	}

	qi::rule<Iterator, Skipper> expression;
	do_expression_list<Iterator, Skipper> *expression_list;
};


template<class Iterator, class Skipper>
struct do_expression_list : qi::grammar<Iterator, Skipper>{
	do_expression_list() : 
		do_expression_list::base_type(expression_list, "do") 
	{
		expression_list = -(do_expression<Iterator, Skipper>(this) >> *(';' >> -do_expression<Iterator, Skipper>(this)));
	}

	qi::rule<Iterator, Skipper> expression_list;
};

template<class Iterator, class Skipper>
struct do_block : qi::grammar<Iterator, Skipper>{
	do_block() : 
		do_block::base_type(block, "do") 
	{
		block = qi::lit("do") >> do_expression_list<Iterator, Skipper>() >> "done";
	}

	qi::rule<Iterator, Skipper> block;
};

template<class Iterator, class Skipper>
struct do_grammar : qi::grammar<Iterator, Skipper>{
	do_grammar() : 
		do_grammar::base_type(expression, "do") 
	{
		expression = do_expression_list<Iterator, Skipper>();
	}

	qi::rule<Iterator, Skipper> expression;
};
#endif 

template<class Iterator, class Skipper>
struct do_grammar : qi::grammar<Iterator, Skipper>{
	do_grammar() : 
		do_grammar::base_type(expression, "do") 
	{
		identifier = +qi::alpha;
		literal = qi::double_ | qi::int_;
		assignment = identifier >> ":=" >> expression;
		expression_list = -(expression >> *(';' >> -expression));
		do_expression = qi::lit("do") >> expression_list >> "done";
		expression = (qi::double_ | do_expression | assignment) >> *(";" >>  expression) >> -qi::lit(";");
	}

	qi::rule<Iterator, Skipper> identifier;
	qi::rule<Iterator, Skipper> literal;
	qi::rule<Iterator, Skipper> assignment;
	qi::rule<Iterator, Skipper> expression;
	qi::rule<Iterator, Skipper> do_expression;
	qi::rule<Iterator, Skipper> expression_list;
};

