cmake_minimum_required(VERSION 3.16)
project(SortingVisualis3r LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(SortingVisualis3r main.cpp
    mergesort.hpp mergesort.cpp
    drawarray.hpp drawarray.cpp
    bubblesort.hpp bubblesort.cpp
    quicksort.hpp quicksort.cpp
    selectionsort.hpp selectionsort.cpp
    insertionsort.hpp insertionsort.cpp)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
