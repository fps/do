// #include <boost/spirit/include/qi.hpp>

#include <iostream>

#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

template<class Iterator, class Skipper>
struct do_grammar : qi::grammar<Iterator, Skipper>{
	do_grammar() : 
		do_grammar::base_type(start, "do") 
	{
		expr = qi::double_;
		start = expr >> *(';' >> expr);

	}

	qi::rule<Iterator, Skipper> start;
	qi::rule<Iterator, Skipper> expr;
};

