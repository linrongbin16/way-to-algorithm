cmake_minimum_required(VERSION 3.4)

cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    SimpleMatch.cpp
    )

add_executable(GameTheory-BashGame.exe BashGameTest.cpp ${SRC_FILE})
add_executable(GameTheory-WythoffGame.exe WythoffGameTest.cpp ${SRC_FILE})
add_executable(GameTheory-NimGame.exe NimGameTest.cpp ${SRC_FILE})

add_executable(TextMatch-ACAutomation.exe ACAutomation.hpp ACAutomation.cpp)
add_executable(TextMatch-KMPMatch.exe KMPMatch.hpp KMPMatch.cpp)
add_executable(TextMatch-SimpleMatch.exe SimpleMatch.hpp SimpleMatch.cpp)
