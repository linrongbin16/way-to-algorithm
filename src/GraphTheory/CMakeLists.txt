cmake_minimum_required(VERSION 3.4)

set(SRC_FILE
    Util.cpp
    Traverse/DepthFirstSearch.cpp
    Traverse/BreadthFirstSearch.cpp
    Traverse/TopologicalSort.cpp
    Traverse/EulerCycle.cpp
    MinSpanningTree/Kruskal.cpp
    MinSpanningTree/Prim.cpp
    StronglyConnectedComponents/Kosaraju.cpp
    StronglyConnectedComponents/Tarjan.cpp
    StronglyConnectedComponents/TwoSatisfiability.cpp
    ShortestPath/BellmanFord.cpp
    ShortestPath/Dijkstra.cpp
    ShortestPath/FloydWarshall.cpp
    ShortestPath/DifferenceConstraints.cpp
    )

add_executable(GraphTheory-Traverse-DepthFirstSearch.exe Traverse/DepthFirstSearchTest.cpp ${SRC_FILE})
add_executable(GraphTheory-Traverse-BreadthFirstSearch.exe Traverse/BreadthFirstSearchTest.cpp ${SRC_FILE})
add_executable(GraphTheory-Traverse-TopologicalSort.exe Traverse/TopologicalSortTest.cpp ${SRC_FILE})
add_executable(GraphTheory-Traverse-EulerCycle.exe Traverse/EulerCycleTest.cpp ${SRC_FILE})
add_executable(GraphTheory-MinSpanningTree-Kruskal.exe MinSpanningTree/KruskalTest.cpp ${SRC_FILE})
add_executable(GraphTheory-MinSpanningTree-Prim.exe MinSpanningTree/PrimTest.cpp ${SRC_FILE})
add_executable(GraphTheory-StronglyConnectedComponents-Kosaraju.exe StronglyConnectedComponents/KosarajuTest.cpp ${SRC_FILE})
add_executable(GraphTheory-StronglyConnectedComponents-Tarjan.exe StronglyConnectedComponents/TarjanTest.cpp ${SRC_FILE})
add_executable(GraphTheory-StronglyConnectedComponents-TwoSatisfiability.exe StronglyConnectedComponents/TwoSatisfiabilityTest.cpp ${SRC_FILE})
add_executable(GraphTheory-ShortestPath-BellmanFord.exe ShortestPath/BellmanFordTest.cpp ${SRC_FILE})
add_executable(GraphTheory-ShortestPath-Dijkstra.exe ShortestPath/DijkstraTest.cpp ${SRC_FILE})
add_executable(GraphTheory-ShortestPath-FloydWarshall.exe ShortestPath/FloydWarshallTest.cpp ${SRC_FILE})
add_executable(GraphTheory-ShortestPath-DifferenceConstraints.exe ShortestPath/DifferenceConstraintsTest.cpp ${SRC_FILE})
