#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP
#include "drawarray.hpp"
class SelectionSort {
public:
    SelectionSort(DrawArray &draw) : draw(draw) {}
    void sort(std::vector<int> &arr, sf::RenderWindow &window);
private:
    DrawArray &draw;
};
#endif // SELECTIONSORT_HPP 