cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    CompleteBag.cpp
    GroupBag.cpp
    TwoDimensionBag.cpp
    ZeroOneBag.cpp
    ZeroOneBagExtension.cpp)

add_executable(DynamicProgramming-CompleteBag.exe CompleteBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-GroupBag.exe GroupBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-TwoDimensionBag.exe TwoDimensionBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-ZeroOneBag.exe ZeroOneBagTest.cpp ${SRC_FILE})
add_executable(DynamicProgramming-ZeroOneBagExtension.exe ZeroOneBagExtensionTest.cpp ${SRC_FILE})
