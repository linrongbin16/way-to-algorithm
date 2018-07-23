cmake_minimum_required(VERSION 3.4)

add_executable(Sort-BubbleSort.exe BubbleSort.h BubbleSort.cpp AscendUtil.h BubbleSortTest.cpp)
add_executable(Sort-InsertSort.exe InsertSort.h InsertSort.cpp AscendUtil.h InsertSortTest.cpp)
add_executable(Sort-MergeSort.exe MergeSort.h MergeSort.cpp AscendUtil.h MergeSortTest.cpp)
add_executable(Sort-QuickSort.exe QuickSort.h QuickSort.cpp AscendUtil.h QuickSortTest.cpp)
