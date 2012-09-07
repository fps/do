#ifndef DO_AST_HH
#define DO_AST_HH

#include <boost/shared_ptr.hpp>
#include <vector>
#include <string>
#include <iostream>

#define DO_DBG(x) cout << x << endl;

using std::vector;
using boost::shared_ptr;
using boost::dynamic_pointer_cast;
using std::string;
using std::cout;
using std::endl;

struct node_base {
	virtual ~node_base() { }
};

template <class T>
struct node : node_base {
	T t;

	node(T t) : t(t) { }
};

typedef shared_ptr<node_base> node_ptr;

template <class T>
node_ptr make_node(T t) {
	return node_ptr(new node<T>(t));
}

struct expression;
typedef shared_ptr<node<expression> > expression_ptr;

struct identifier;
typedef shared_ptr<node<identifier> > identifier_ptr;

struct number;
typedef shared_ptr<node<number> > number_ptr;

struct assignment;
typedef shared_ptr<node<assignment> > assignment_ptr;

struct expression : node_base {

};

struct assignment {
	shared_ptr<node<identifier> > id;
	shared_ptr<node<expression> > exp;

	assignment(shared_ptr<node<identifier> > id, shared_ptr<node<expression> > exp) :
		id(id),
		exp(exp)
	{
		DO_DBG("assignment")
	}
};


struct identifier {
	string name;
	shared_ptr<node<identifier> > selector;

	identifier(
		const string& name, 
		shared_ptr<node<identifier> > selector = shared_ptr<node<identifier> >()
	) : 
		name(name), 
		selector(selector) 
	{ 
		DO_DBG("identifier: " << get_name())
	}

	string get_name() {
		string n = name;
		if (selector) {
			n = n + "." + selector->t.get_name();
		}
		return n;
	}
};

struct number {
	double t;
	number(double t) : t(t) 
	{
		DO_DBG("number: " << t) 
	}
};

#endif

