cmake_minimum_required(VERSION 2.8.9)
project(matrix)
add_library(matrix_header.h INTERFACE)
target_include_directories(matrix_header.h INTERFACE include)
include_directories(include)
install(FILES matrix_header.h DESTINATION include)
set(SOURCES src/matrix.cpp)
add_executable(testmatrix ${SOURCES})

