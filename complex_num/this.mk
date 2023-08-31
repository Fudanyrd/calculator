a: example.o complex_num.o
	g++ -o a example.o complex_num.o

main.o: example.cpp complex_num.h
	g++ -c example.cpp
complex_num.o: complex_num.h
	g++ -c complex_num.cpp

clean :
	rm a.exe example.o complex_num.o
