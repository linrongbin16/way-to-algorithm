cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    BidirectionalSubsequence.cpp
    LongestCommonSubsequence.cpp
    LongestIncreasingSubsequence.cpp
    LongestIncreasingSubsequenceExtension.cpp)

add_executable(DynamicProgramming-BidirectionalSubsequence.exe BidirectionalSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LongestCommonSubsequence.exe LongestCommonSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LongestIncreasingSubsequence.exe LongestIncreasingSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LongestIncreasingSubsequenceExtension.exe LongestIncreasingSubsequenceExtensionTest.cpp ${SRC_FILE})
