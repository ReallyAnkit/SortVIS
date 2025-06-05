#include "bubblesort.hpp"
#include <algorithm>
void BubbleSort::sort(std::vector<int> &arr, sf::RenderWindow &window)
{
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
            draw.drawArray(window, arr);
        }
    }
}
