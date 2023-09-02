cmake_minimum_required(VERSION 3.9)
project(calculator)
add_executable(calculator main.cpp calculator/calculator.cpp translator/translator.cpp Expr/Expr_node.cpp
 complex_num/complex_num.cpp)