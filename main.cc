#include <parser.h>

#include <string>
#include <iostream>
#include <iterator>

#include <boost/spirit/include/support_istream_iterator.hpp>


int main() {
	std::cin >> std::noskipws;	

	namespace spirit = boost::spirit;

	typedef ascii::space_type skipper_type;
	typedef spirit::istream_iterator iterator_type;
	typedef do_grammar<iterator_type, skipper_type> grammar;

	grammar g;

	iterator_type iter(std::cin);
	iterator_type end;

	bool r = qi::phrase_parse(iter, end, g, skipper_type());

	if (true == r && iter == end) { std::cout << "yay" << std::endl; }
	else { std::cout << "nay" << std::endl; }
}

