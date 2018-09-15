cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    BashGame.cpp
    WythoffGame.cpp
    NimGame.cpp
    )

add_executable(GameTheory-BashGame.exe BashGameTest.cpp ${SRC_FILE})
add_executable(GameTheory-WythoffGame.exe WythoffGameTest.cpp ${SRC_FILE})
add_executable(GameTheory-NimGame.exe NimGameTest.cpp ${SRC_FILE})
