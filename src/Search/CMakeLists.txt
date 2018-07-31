cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    AStarSearch.cpp
    BidirectionalBreadthSearch.cpp
    BinarySearch.cpp
    BreadthFirstSearch.cpp
    BruteForce.cpp
    DancingLinks.cpp
    Recursion.cpp
    Util.cpp)

add_executable(Search-AStarSearch.exe AStarSearchTest.cpp ${SRC_FILE})
add_executable(Search-BidirectionalBreadthSearch.exe BidirectionalBreadthSearch.hpp BidirectionalBreadthSearch.cpp)
add_executable(Search-BinarySearch.exe BinarySearchTest.cpp ${SRC_FILE})
add_executable(Search-BreadthFirstSearch.exe BreadthFirstSearch.hpp BreadthFirstSearch.cpp)
add_executable(Search-BruteForce.exe BruteForceTest.cpp ${SRC_FILE})
add_executable(Search-DancingLinks.exe DancingLinks.hpp DancingLinks.cpp)
add_executable(Search-Recursion.exe RecursionTest.cpp ${SRC_FILE})
