#ifndef DO_AST_HH
#define DO_AST_HH

#include <boost/shared_ptr.hpp>
#include <vector>

using std::vector;
using boost::shared_ptr;
using boost::dynamic_pointer_cast;

struct node_base {
	vector<shared_ptr<node_base> > nodes;
	
	virtual ~node_base() { }
};

template <class T>
struct node : node_base {
	T t;

	node(T t) : t(t) { }
};

template <class T>
shared_ptr<node_base> make_node(T t) {
	return shared_ptr<node_base>(new node<T>(t));
}

#endif

