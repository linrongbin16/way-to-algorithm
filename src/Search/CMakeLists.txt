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

add_executable(search-AStarSearch.exe AStarSearch.hpp AStarSearch.cpp)
add_executable(search-BidirectionalBreadthSearch.exe BidirectionalBreadthSearch.hpp BidirectionalBreadthSearch.cpp)
add_executable(search-BinarySearch.exe BinarySearch.hpp BinarySearch.cpp)
add_executable(search-BreadthFirstSearch.exe BreadthFirstSearch.hpp BreadthFirstSearch.cpp)
add_executable(Search-BruteForce.exe BruteForceTest.cpp ${SRC_FILE})
add_executable(search-DancingLinks.exe DancingLinks.hpp DancingLinks.cpp)
add_executable(search-Recursion.exe Recursion.hpp Recursion.cpp)
