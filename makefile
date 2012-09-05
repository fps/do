#do: main.cc parser.h parser.cc
#	g++ -g -o do -I . ${CXXFLAGS} main.cc

INCLUDES=-I .

CFLAGS ?= -g

do: lex.yy.o y.tab.o
	g++ ${CFLAGS} -Wall ${INCLUDES} -o do lex.yy.o y.tab.o 

lex.yy.o: lex.yy.cc
	g++ ${CFLAGS} -Wall ${INCLUDES} -c lex.yy.cc

lex.yy.cc: do.l y.tab.hh ast.h
	lex -o lex.yy.cc do.l 

y.tab.o: y.tab.cc
	g++ ${CFLAGS} -Wall ${INCLUDES} -c y.tab.cc

y.tab.hh y.tab.cc: do.y ast.h
	yacc -d do.y -o y.tab.cc

.PHONY: clean

clean:
	rm -rf lex.yy.cc y.tab.cc y.tab.hh *.o do
