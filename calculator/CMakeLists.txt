project(Calculator)

add_library(${PROJECT_NAME} STATIC calculator.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include/)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(${PROJECT_NAME} translator)