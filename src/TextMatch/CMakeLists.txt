cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    SimpleMatch.cpp
    KnuthMorrisPratt.cpp
    AhoCorasickAutomata.cpp
    RabinKarp.cpp
    Util.cpp
    )

add_executable(TextMatch-SimpleMatch.exe SimpleMatchTest.cpp ${SRC_FILE})
add_executable(TextMatch-AhoCorasickAutomata.exe AhoCorasickAutomataTest.cpp ${SRC_FILE})
add_executable(TextMatch-KnuthMorrisPratt.exe KnuthMorrisPrattTest.cpp ${SRC_FILE})
add_executable(TextMatch-RabinKarp.exe RabinKarpTest.cpp ${SRC_FILE})
