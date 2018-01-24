cmake_minimum_required(VERSION 2.8)
project(imp_c)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES test/main.c src/list/linkedlist.c src/list/arraylist.c test/minunit.h src/queue/deque.h src/queue/deque.c test/linkedlist_test.hpp src/tree/arraybinarytree.h src/tree/linkedbinarytree.c src/tree/linkedbinarytree.h src/tree/arraybinarytree.cpp src/tree/tree.h src/tree/tree.cpp)

include_directories(src/list src/queue)

add_executable(imp_c ${SOURCE_FILES})