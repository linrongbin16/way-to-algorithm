cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    #AStarSearch.cpp
    #BidirectionalBreadthSearch.cpp
    #BinarySearch.cpp
    BreadthFirstSearch.cpp
    BruteForce.cpp
    #DancingLink.cpp
    Recursion.cpp
    Util.cpp)

#add_executable(Search-AStarSearch.exe AStarSearchTest.cpp ${SRC_FILE})
#add_executable(Search-BidirectionalBreadthSearch.exe BidirectionalBreadthSearchTest.cpp ${SRC_FILE})
#add_executable(Search-BinarySearch.exe BinarySearchTest.cpp ${SRC_FILE})
add_executable(Search-BreadthFirstSearch.exe BreadthFirstSearchTest.cpp ${SRC_FILE})
add_executable(Search-BruteForce.exe BruteForceTest.cpp ${SRC_FILE})
#add_executable(Search-DancingLink.exe DancingLinkTest.cpp ${SRC_FILE})
#add_executable(Search-Recursion.exe RecursionTest.cpp ${SRC_FILE})
