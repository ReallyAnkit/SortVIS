#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include "drawarray.hpp"
#include <SFML/Graphics.hpp>

class MergeSort
{
public:
    MergeSort(DrawArray &draw)
        : draw(draw)
    {}
    void merge_sort(std::vector<int> &arr, int left, int right, sf::RenderWindow &window);
    void merge(std::vector<int> &arr, int left, int mid, int right, sf::RenderWindow &window);

private:
    DrawArray &draw;
};

#endif // MERGESORT_HPP
