cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    AStarSearch.cpp
    BidirectionalBreadthSearch.cpp
    BinarySearch.cpp
    BreadthFirstSearch.cpp
    BruteForce.cpp
    DancingLink.cpp
    Recursion.cpp
    Util.cpp)

add_executable(DataStructure-AVLTree.exe AVLTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-FenwickTree.exe FenwickTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-DisjointSet.exe DisjointSetTest.cpp ${SRC_FILE})
add_executable(DataStructure-LeftistTree.exe LeftistTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-PrefixTree.exe PrefixTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-RedBlackTree.exe RedBlackTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-SegmentTree.exe SegmentTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-SuffixTree.exe SuffixTreeTest.cpp ${SRC_FILE})
