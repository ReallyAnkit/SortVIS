#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "drawarray.hpp"
#include <vector>
class QuickSort
{
public:
    QuickSort();

public:
    QuickSort(DrawArray &draw)
        : draw(draw)
    {}
    void sort(sf::RenderWindow &window, std::vector<int> &vec);
    void quicksort(std::vector<int> &vec, int low, int high, sf::RenderWindow &window);

private:
    int partition(std::vector<int> &vec, int low, int high, sf::RenderWindow &window);
    DrawArray &draw;
};

#endif // QUICKSORT_HPP
