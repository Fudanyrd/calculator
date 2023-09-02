project(translator)

add_library(${PROJECT_NAME} STATIC translator.cpp)
include_directories(${PROJCET_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} Expr)