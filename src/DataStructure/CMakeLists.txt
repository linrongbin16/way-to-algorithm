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

add_executable(DataStructure-AVLTree.exe AVLTree.cpp AVLTree.hpp)
add_executable(DataStructure-FenwickTree.exe FenwickTree.cpp FenwickTree.hpp)
add_executable(DataStructure-DisjointSet.exe DisjointSet.cpp DisjointSet.hpp)
add_executable(DataStructure-LeftistTree.exe LeftistTree.cpp LeftistTree.hpp)
add_executable(DataStructure-PrefixTree.exe PrefixTree.cpp PrefixTree.hpp)
add_executable(DataStructure-RedBlackTree.exe RedBlackTree.cpp RedBlackTree.hpp)
add_executable(DataStructure-SegmentTree.exe SegmentTree.cpp SegmentTree.hpp)
# add_executable(SuffixTree.exe SuffixTree.cpp)
