cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    PrimeSieve.cpp
    Euclid.cpp
    ExtendedEuclid.cpp
    ModularLinearEquations.cpp
    ChineseRemainerTheorem.cpp
    )

add_executable(NumberTheory-PrimeSieve.exe PrimeSieveTest.cpp ${SRC_FILE})
add_executable(NumberTheory-Euclid.exe EuclidTest.cpp ${SRC_FILE})
add_executable(NumberTheory-ExtendedEuclid.exe ExtendedEuclidTest.cpp ${SRC_FILE})
add_executable(NumberTheory-ModularLinearEquations.exe ModularLinearEquationsTest.cpp ${SRC_FILE})
add_executable(NumberTheory-ChineseRemainerTheorem.exe ChineseRemainerTheoremTest.cpp ${SRC_FILE})
