cmake_minimum_required(VERSION 3.16)
project(Introduction_To_Algorithms)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD)

add_executable(sort_insertion sort_insertion.cpp)
add_executable(sort_merge sort_merge.cpp)
add_executable(sort_selection sort_selection.cpp)
add_executable(search_linear search_linear.cpp)
add_executable(baekjoon_1037 baekjoon_1037.cpp)
add_executable(baekjoon_7785 baekjoon_7785.cpp)
add_executable(SimpleStack SimpleStack.c)
