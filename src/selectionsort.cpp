#include "selectionsort.hpp"
#include <algorithm>
void SelectionSort::sort(std::vector<int> &arr, sf::RenderWindow &window) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
            draw.drawArray(window, arr);
        }
        if (min_idx != i)
            std::swap(arr[i], arr[min_idx]);
        draw.drawArray(window, arr);
    }
} 