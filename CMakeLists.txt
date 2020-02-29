cmake_minimum_required(VERSION 3.12)
project(DataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructure src/list/LinkedList.cpp src/list/LinkedList.h src/tree/BinaryTree.cpp src/tree/BinaryTree.h src/sort/FastOrder.cpp src/sort/FastOrder.h src/sort/HeadSort.h src/sort/HeapSort.cpp)