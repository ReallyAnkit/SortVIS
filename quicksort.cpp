#include "quicksort.hpp"

void QuickSort::sort(sf::RenderWindow &window, std::vector<int> &vec)
{
    quicksort(vec, 0, vec.size() - 1, window);
}

void QuickSort::quicksort(std::vector<int> &vec, int low, int high, sf::RenderWindow &window)
{
    if (low < high) {
        int pivot = partition(vec, low, high, window);
        draw.drawArray(window, vec);
        quicksort(vec, low, pivot - 1, window);
        quicksort(vec, pivot + 1, high, window);
    }
}

int QuickSort::partition(std::vector<int> &vec, int low, int high, sf::RenderWindow &window)
{
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) {
            i++;
            std::swap(vec[i], vec[j]);
            draw.drawArray(window, vec);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    draw.drawArray(window, vec);
    return i + 1;
}
