cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    CompleteKnapsack.cpp
    GroupKnapsack.cpp
    FenwickTree.cpp
    LeftistTree.cpp
    PrefixTree.cpp
    RedBlackTree.cpp
    SegmentTree.cpp
    SuffixTree.cpp)


add_executable(DynamicProgramming-KnapsackDP-CompleteKnapsack.exe CompleteKnapsack.cpp CompleteKnapsack.hpp)
add_executable(DynamicProgramming-KnapsackDP-GroupKnapsack.exe GroupKnapsack.cpp GroupKnapsack.hpp)
add_executable(DynamicProgramming-KnapsackDP-TwoDimensionKnapsack.exe TwoDimensionKnapsack.cpp TwoDimensionKnapsack.hpp)
add_executable(DynamicProgramming-KnapsackDP-ZeroOneKnapsack.exe ZeroOneKnapsack.cpp ZeroOneKnapsack.hpp)
add_executable(DynamicProgramming-KnapsackDP-ZeroOneKnapsackExtension.exe ZeroOneKnapsackExtension.cpp ZeroOneKnapsackExtension.hpp)
