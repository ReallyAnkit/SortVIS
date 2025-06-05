#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP
#include "drawarray.hpp"
class BubbleSort
{
public:
    BubbleSort(DrawArray &draw)
        : draw(draw) {};
    void sort(std::vector<int> &arr, sf::RenderWindow &window);

private:
    DrawArray &draw;
};

#endif // BUBBLESORT_HPP
