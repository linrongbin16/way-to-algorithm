cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Cross.cpp
    SegmentIntersection.cpp
    Sweeping.cpp
    ConvexPolygonArea.cpp
    ConvexPolygonGravityCenter.cpp
    ../Util.cpp
    )

add_executable(AnalyticGeometry-Cross.exe CrossTest.cpp ${SRC_FILE})
add_executable(AnalyticGeometry-SegmentIntersection.exe SegmentIntersectionTest.cpp ${SRC_FILE})
add_executable(AnalyticGeometry-Sweeping.exe SweepingTest.cpp ${SRC_FILE})
add_executable(AnalyticGeometry-ConvexPolygonArea.exe ConvexPolygonAreaTest.cpp ${SRC_FILE})
add_executable(AnalyticGeometry-ConvexPolygonGravityCenter.exe ConvexPolygonGravityCenterTest.cpp ${SRC_FILE})
