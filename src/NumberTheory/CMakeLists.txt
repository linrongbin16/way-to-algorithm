cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Euclid.cpp
    Sieve.cpp)

add_executable(NumberTheory-Euclid.exe EuclidTest.cpp ${SRC_FILE})
add_executable(NumberTheory-Sieve.exe SieveTest.cpp ${SRC_FILE})
