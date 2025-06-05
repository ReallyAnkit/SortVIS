cmake_minimum_required(VERSION 3.16)

project(SortingVisualis3r LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(includes)

add_executable(SortingVisualis3r 
    src/main.cpp
    src/mergesort.cpp
    src/drawarray.cpp
    src/bubblesort.cpp
    src/quicksort.cpp
    src/selectionsort.cpp
    src/insertionsort.cpp
)

target_link_libraries(SortingVisualis3r sfml-graphics sfml-window sfml-system)

