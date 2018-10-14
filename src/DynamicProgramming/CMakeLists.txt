cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Util.cpp
    BagDP/CompleteBag.cpp
    BagDP/TwoDimensionBag.cpp
    BagDP/ZeroOneBag.cpp

    LinearDP/LongestCommonSubsequence.cpp
    LinearDP/LongestIncreasingSubsequence.cpp
    LinearDP/BidirectionalSubsequence.cpp
    LinearDP/MaxContinuousSubsequenceSum.cpp
    LinearDP/LongestPalindromicSubsequence.cpp

    RegionalDP/MinMergeCost.cpp
    RegionalDP/UniquePath.cpp
    RegionalDP/TrianglePath.cpp

    TreeDP/MaxBinaryTree.cpp
    TreeDP/MaxMultipleTree.cpp
    )

add_executable(DynamicProgramming-BagDP-ZeroOneBag.exe BagDP/ZeroOneBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-BagDP-CompleteBag.exe BagDP/CompleteBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-BagDP-TwoDimensionBag.exe BagDP/TwoDimensionBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestCommonSubsequence.exe LinearDP/LongestCommonSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestIncreasingSubsequence.exe LinearDP/LongestIncreasingSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-BidirectionalSubsequence.exe LinearDP/BidirectionalSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-MaxContinuousSubsequenceSum.exe LinearDP/MaxContinuousSubsequenceSumTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestPalindromicSubsequence.exe LinearDP/LongestPalindromicSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-RegionalDP-MinMergeCost.exe RegionalDP/MinMergeCostTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-RegionalDP-UniquePath.exe RegionalDP/UniquePathTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-RegionalDP-TrianglePath.exe RegionalDP/TrianglePathTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-TreeDP-MaxBinaryTree.exe TreeDP/MaxBinaryTreeTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-TreeDP-MaxMultipleTree.exe TreeDP/MaxMultipleTreeTest.cpp ${SRC_FILE})

