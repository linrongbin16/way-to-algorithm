cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Traverse/DepthFirstSearch.cpp
    Traverse/BreadthFirstSearch.cpp
    Traverse/TopologicSort.cpp
    )

add_executable(GraphTheory-Traverse-DepthFirstSearch.exe Traverse/DepthFirstSearchTest.cpp ${SRC_FILE})
add_executable(GraphTheory-Traverse-BreadthFirstSearch.exe Traverse/BreadthFirstSearchTest.cpp ${SRC_FILE})
add_executable(GraphTheory-Traverse-TopologicSort.exe Traverse/TopologicSortTest.cpp ${SRC_FILE})
