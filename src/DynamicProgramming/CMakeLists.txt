cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Util.cpp
    BagDP/CompleteBag.cpp
    BagDP/TwoDimensionBag.cpp
    BagDP/ZeroOneBag.cpp

    LinearDP/LongestCommonSubsequence.cpp
    LinearDP/LongestIncreasingSubsequence.cpp
    LinearDP/BidirectionalSubsequence.cpp
    LinearDP/LongestContinuousSubsequenceSum.cpp
    LinearDP/LongestPalindromicSubsequence.cpp

    RegionalDP/MinimumMergeCost.cpp
    RegionalDP/UniquePath.cpp
    RegionalDP/TrianglePath.cpp

    TreeDP/MaximumBinaryTree.cpp
    )

add_executable(DynamicProgramming-BagDP-ZeroOneBag.exe BagDP/ZeroOneBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-BagDP-CompleteBag.exe BagDP/CompleteBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-BagDP-TwoDimensionBag.exe BagDP/TwoDimensionBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestCommonSubsequence.exe LinearDP/LongestCommonSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestIncreasingSubsequence.exe LinearDP/LongestIncreasingSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-BidirectionalSubsequence.exe LinearDP/BidirectionalSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestContinuousSubsequenceSum.exe LinearDP/LongestContinuousSubsequenceSumTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestPalindromicSubsequence.exe LinearDP/LongestPalindromicSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-RegionalDP-MinimumMergeCost.exe RegionalDP/MinimumMergeCostTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-RegionalDP-UniquePath.exe RegionalDP/UniquePathTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-RegionalDP-TrianglePath.exe RegionalDP/TrianglePathTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-TreeDP-MaximumBinaryTree.exe TreeDP/MaximumBinaryTreeTest.cpp ${SRC_FILE})

