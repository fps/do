#do: main.cc parser.h parser.cc
#	g++ -g -o do -I . ${CXXFLAGS} main.cc

INCLUDES=-I .

do: lex.yy.o y.tab.o
	g++ ${CFLAGS} ${INCLUDES} -o do lex.yy.o y.tab.o 

lex.yy.o: lex.yy.c
	gcc ${CFLAGS} ${INCLUDES} -c lex.yy.c

lex.yy.c: do.l y.tab.hh
	lex do.l

y.tab.o: y.tab.cc
	g++ ${CFLAGS} ${INCLUDES} -c y.tab.cc

y.tab.hh y.tab.cc: do.y
	yacc -d do.y -o y.tab.cc

.PHONY: clean

clean:
	rm -rf lex.yy.c y.tab.cc y.tab.h *.o do
