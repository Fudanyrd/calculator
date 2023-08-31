calculator: main.o calculator.o translator.o Expr_node.o complex_num.o
	g++ -o calculator main.o calculator.o translator.o Expr_node.o complex_num.o

main.o: main.cpp
	g++ -c main.cpp
calculator.o: calculator\calculator.h
	g++ -c calculator\calculator.cpp
translator.o: translator\translator.h
	g++ -c translator\translator.cpp
Expr_node.o: Expr\Expr_node.h
	g++ -c Expr\Expr_node.cpp
complex_num.o: complex_num\complex_num.h
	g++ -c complex_num\complex_num.cpp

clean:
	rm main.o calculator.o translator.o Expr_node.o \
	complex_num.o
