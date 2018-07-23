cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    BubbleSort.cpp
    InsertSort.cpp
    MergeSort.cpp
    QuickSort.cpp
    Util.cpp)

add_executable(Sort-BubbleSort.exe BubbleSortTest.cpp ${SRC_FILE})
add_executable(Sort-InsertSort.exe InsertSortTest.cpp ${SRC_FILE})
add_executable(Sort-MergeSort.exe MergeSortTest.cpp ${SRC_FILE})
add_executable(Sort-QuickSort.exe QuickSortTest.cpp ${SRC_FILE})
