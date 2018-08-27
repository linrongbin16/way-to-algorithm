cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    ../Util.cpp
    Cross.cpp
    SegmentIntersection.cpp
    )

add_executable(AnalyticGeometry-Cross.exe CrossTest.cpp ${SRC_FILE})
add_executable(AnalyticGeometry-SegmentIntersection.exe SegmentIntersectionTest.cpp ${SRC_FILE})

