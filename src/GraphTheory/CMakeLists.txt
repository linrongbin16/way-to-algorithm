cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Traverse/DepthFirstSearch.cpp
    Traverse/BreadthFirstSearch.cpp
    Traverse/TopologicalSort.cpp
    Traverse/EulerCycle.cpp
    MinSpanningTree/Kruskal.cpp
    MinSpanningTree/Prim.cpp
    )

add_executable(GraphTheory-Traverse-DepthFirstSearch.exe Traverse/DepthFirstSearchTest.cpp ${SRC_FILE})
add_executable(GraphTheory-Traverse-BreadthFirstSearch.exe Traverse/BreadthFirstSearchTest.cpp ${SRC_FILE})
add_executable(GraphTheory-Traverse-TopologicalSort.exe Traverse/TopologicalSortTest.cpp ${SRC_FILE})
add_executable(GraphTheory-Traverse-EulerCycle.exe Traverse/EulerCycleTest.cpp ${SRC_FILE})
add_executable(GraphTheory-MinSpanningTree-Kruskal.exe MinSpanningTree/Kruskal.cpp ${SRC_FILE})
add_executable(GraphTheory-MinSpanningTree-Prim.exe MinSpanningTree/Prim.cpp ${SRC_FILE})
