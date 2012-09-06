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

struct expression : node_base {

};

struct identifier;

struct assignment : node_base {
	shared_ptr<node<identifier> > id;
	shared_ptr<node<expression> > exp;

	assignment(shared_ptr<node<identifier> > id, shared_ptr<node<expression> > exp) :
		id(id),
		exp(exp)
	{
		DO_DBG("assignment")
	}
};

template <class T>
struct literal : expression {
	T t;
	literal(T t) : 
		t(t) 
	{
 		DO_DBG("literal: " << t)
	}
};

template <class T>
node_ptr make_literal(T t) {
	return node_ptr(new literal<T>(t));
}

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

