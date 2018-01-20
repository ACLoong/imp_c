cmake_minimum_required(VERSION 3.8)
project(imp_c)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES test/main.c src/list/linkedlist.c src/list/arraylist.c test/minunit.h src/queue/deque.h src/queue/deque.c test/linkedlist_test.hpp)

include_directories(src/list)

add_executable(imp_c ${SOURCE_FILES})