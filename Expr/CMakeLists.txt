project(Expr)

add_library(${PROJECT_NAME} STATIC Expr_node.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include/)
target_link_libraries(${PROJECT_NAME} complex_num)
