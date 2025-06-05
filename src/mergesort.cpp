#include "mergesort.hpp"

// void MergeSort::merge(std::vector<int> &arr, int left, int mid, int right, sf::RenderWindow &window)
// {
//     int leftSize = mid - left + 1;
//     int rightSize = right - mid;
//     std::vector<int> leftArr(leftSize), rightArr(rightSize);

//     for (int i = 0; i < leftSize; i++) {
//         leftArr[i] = arr[left + i];
//     }
//     for (int i = 0; i < rightSize; i++) {
//         rightArr[i] = arr[mid + 1 + i];
//     }

//     int i = 0, j = 0, k = left;
//     while (i < leftSize && j < rightSize) {
//         if (leftArr[i] <= rightArr[j]) {
//             arr[k] = leftArr[i];
//             i++;
//         } else {
//             arr[k] = rightArr[j];
//             j++;
//         }
//         k++;
//         draw.drawArray(window, arr);
//     }
//     while (i < leftSize) {
//         arr[k] = leftArr[i];
//         i++;
//         k++;
//         draw.drawArray(window, arr);
//     }
//     while (j < rightSize) {
//         arr[k] = rightArr[j];
//         j++;
//         k++;
//         draw.drawArray(window, arr);
//     }
// }
void MergeSort::merge(std::vector<int> &arr, int left, int mid, int right, sf::RenderWindow &window)
{
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            int value = arr[j];
            int index = j;
            while (index > i) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i] = value;
            i++;
            mid++;
            j++;
        }
        draw.drawArray(window, arr);
    }
}

void MergeSort::merge_sort(std::vector<int> &arr, int left, int right, sf::RenderWindow &window)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid, window);
        merge_sort(arr, mid + 1, right, window);
        merge(arr, left, mid, right, window);
    }
}
