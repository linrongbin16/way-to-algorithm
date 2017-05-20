cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++11)


add_subdirectory(Sort)
add_subdirectory(Search)
add_subdirectory(DataStructure)
add_subdirectory(DynamicProgramming)
add_subdirectory(GraphTheory)