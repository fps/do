do: main.cc parser.h parser.cc
	g++ -g -o do -I . ${CXXFLAGS} main.cc
