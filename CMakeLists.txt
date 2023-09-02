cmake_minimum_required(VERSION 3.9)

project(calculator)

add_subdirectory(complex_num)
add_subdirectory(Expr)
add_subdirectory(translator)
add_subdirectory(calculator)

#generate .exe
add_executable(${PROJECT_NAME}, main.cpp)

#link operation
target_link_libraries(${PROJECT_NAME} Calculator translator Expr complex_num)