project(complex_num)

add_library(${PROJECT_NAME} STATIC complex_num.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include/)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)