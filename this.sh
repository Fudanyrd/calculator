this(){

    #get the object file.
    g++ -c complex_num/complex_num.cpp
    g++ -c Expr/Expr_node.cpp
    g++ -c translator/translator.cpp
    g++ -c calculator/calculator.cpp
    g++ -c main.cpp

    #link object file
    g++ -o calculator main.o calculator.o translator.o Expr_node.o complex_num.o

    #delete the object file
    rm *.o

    #done
    echo "done."
}