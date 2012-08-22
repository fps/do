// #include <boost/spirit/include/qi.hpp>

#include <iostream>

#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

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

