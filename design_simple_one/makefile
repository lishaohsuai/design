one:main.o design_simple_one.o
	g++ -o $@ $^

design_simple_one.o: design_simple_one.cpp design_simple_one.h
	g++  -c $@ $^

main.o:main.cpp design_simple_one.h
	g++ -c  $@ $^