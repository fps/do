#include <parser.h>

#include <string>
#include <iostream>
#include <iterator>

#include <boost/spirit/include/support_istream_iterator.hpp>


int main() {
	std::cin >> std::noskipws;	

	namespace spirit = boost::spirit;

	typedef spirit::istream_iterator iterator_type;
	typedef do_grammar<iterator_type> grammar;

	grammar g;

	iterator_type iter(std::cin);
	iterator_type end;

	// std::string::const_iterator iter = str.begin();
	// std::string::const_iterator end = str.end();

	bool r = qi::parse(iter, end, g);

	if (true == r) { std::cout << "yay" << std::endl; }
	else { std::cout << "nay" << std::endl; }
}

