cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Euclid.cpp
    Sieve.cpp)

add_executable(NumberTheory-Euclid.exe EuclidTest.cpp ${SRC_FILE})
add_executable(NumberTheory-Sieve.exe SieveTest.cpp ${SRC_FILE})
if ((${CMAKE_CXX_COMPILER_ID} MATCHES "GNU") OR (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang"))
    target_link_libraries(NumberTheory-Sieve.exe pthread)
endif()
