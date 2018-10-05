cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    AvlTree.cpp
    DisjointSet.cpp
    FenwickTree.cpp
    LeftistTree.cpp
    PrefixTree.cpp
    RedBlackTree.cpp
    SegmentTree.cpp
    BinarySearchTree.cpp)

add_executable(DataStructure-DisjointSet.exe DisjointSetTest.cpp ${SRC_FILE})
add_executable(DataStructure-SegmentTree.exe SegmentTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-LeftistTree.exe LeftistTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-PrefixTree.exe PrefixTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-FenwickTree.exe FenwickTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-BinarySearchTree.exe BinarySearchTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-AvlTree.exe AvlTreeTest.cpp ${SRC_FILE})
add_executable(DataStructure-RedBlackTree.exe RedBlackTreeTest.cpp ${SRC_FILE})
