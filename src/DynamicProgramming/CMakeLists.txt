cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Util.cpp
    BagDP/CompleteBag.cpp
    BagDP/TwoDimensionBag.cpp
    BagDP/ZeroOneBag.cpp

    LinearDP/LongestCommonSubsequence.cpp
    LinearDP/LongestIncreasingSubsequence.cpp
    LinearDP/BidirectionalSubsequence.cpp
    LinearDP/GreatestContinuousSubsequenceSum.cpp
    )

add_executable(DynamicProgramming-BagDP-ZeroOneBag.exe BagDP/ZeroOneBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-BagDP-CompleteBag.exe BagDP/CompleteBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-BagDP-TwoDimensionBag.exe BagDP/TwoDimensionBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestCommonSubsequence.exe LinearDP/LongestCommonSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-LongestIncreasingSubsequence.exe LinearDP/LongestIncreasingSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-BidirectionalSubsequence.exe LinearDP/BidirectionalSubsequenceTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-LinearDP-GreatestContinuousSubsequenceSum.exe LinearDP/GreatestContinuousSubsequenceSumTest.cpp ${SRC_FILE})

