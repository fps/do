#do: main.cc parser.h parser.cc
#	g++ -g -o do -I . ${CXXFLAGS} main.cc

do: lex.yy.c y.tab.c
	gcc ${CFLAGS} -o do lex.yy.c y.tab.c -lfl

lex.yy.c: do.l
	lex do.l

y.tab.h y.tab.c: do.y
	yacc -d do.y

.PHONY: clean

clean:
	rm -rf lex.yy.c y.tab.c y.tab.h do
