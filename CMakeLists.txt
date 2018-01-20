cmake_minimum_required(VERSION 3.8)
project(imp_c)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/test/main.c src/list/linkedlist.c src/list/arraylist.c src/test/minunit.h src/test/linkedlist_test.c)
add_executable(imp_c ${SOURCE_FILES})