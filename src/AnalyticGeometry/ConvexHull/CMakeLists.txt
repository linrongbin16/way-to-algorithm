cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    ../Util.cpp
    GrahamScan.cpp
    )

add_executable(AnalyticGeometry-GrahamScan.exe GrahamScanTest.cpp ${SRC_FILE})
