#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP
#include "drawarray.hpp"
class InsertionSort {
public:
    InsertionSort(DrawArray &draw) : draw(draw) {}
    void sort(std::vector<int> &arr, sf::RenderWindow &window);
private:
    DrawArray &draw;
};
#endif // INSERTIONSORT_HPP 