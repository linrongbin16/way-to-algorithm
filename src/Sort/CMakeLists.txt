cmake_minimum_required(VERSION 3.4)

add_executable(sort-bubble_sort.exe bubble_sort.h bubble_sort.cpp ascend_util.h bubble_sort_test.cpp)
add_executable(sort-insert_sort.exe insert_sort.h insert_sort.cpp ascend_util.h insert_sort_test.cpp)
add_executable(sort-merge_sort.exe merge_sort.h merge_sort.cpp ascend_util.h merge_sort_test.cpp)
add_executable(sort-quick_sort.exe quick_sort.h quick_sort.cpp ascend_util.h quick_sort_test.cpp)
