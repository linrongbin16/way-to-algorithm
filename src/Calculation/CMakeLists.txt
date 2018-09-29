cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    #Exponentiation.cpp
    LargeNumber.cpp
    )

add_executable(Calculation-LargeNumber.exe LargeNumberTest.cpp ${SRC_FILE})
#add_executable(Calculation-Exponentiation.exe ExponentiationTest.cpp ${SRC_FILE})
