cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    MaximumBinaryTreeMerge.cpp
    MinimumMergeCost.cpp
    MinimumMergeCostExtension.cpp
    )

add_executable(DynamicProgramming-MaximumBinaryTreeMerge.exe MaximumBinaryTreeMergeTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-MinimumMergeCost.exe MinimumMergeCostTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-MinimumMergeCostExtension.exe MinimumMergeCostExtensionTest.cpp ${SRC_FILE})
