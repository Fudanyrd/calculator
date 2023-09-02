calculator: main.o calculator.o translator.o Expr_node.o complex_num.o
	$(CXX) -o calculator main.o calculator.o translator.o Expr_node.o complex_num.o

main.o: main.cpp
	$(CXX) -c main.cpp
calculator.o: calculator\calculator.h
	$(CXX) -c calculator\calculator.cpp
translator.o: translator\translator.h
	$(CXX) -c translator\translator.cpp
Expr_node.o: Expr\Expr_node.h
	$(CXX) -c Expr\Expr_node.cpp
complex_num.o: complex_num\complex_num.h
	$(CXX) -c complex_num\complex_num.cpp

clean:
	rm main.o calculator.o translator.o Expr_node.o \
	complex_num.o
