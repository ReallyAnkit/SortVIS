#include "bubblesort.hpp"
#include "drawarray.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

int HEIGHT = 800;
int WIDTH = 1000;
int BARS = 1000;
using namespace std;

enum class Algo { BubbleSort, MergeSort, QuickSort, SelectionSort, InsertionSort };
enum class AppState { Menu, Visualizing };

void randomizeArray(vector<int> &arr)
{
    for (auto &i : arr) {
        i = rand() % HEIGHT;
    }
}

int main()
{
    srand(time(0));
    int selectedBars = 100;
    int minBars = 10, maxBars = 1000;
    Algo algo = Algo::BubbleSort;
    vector<string> algoNames = {"Bubble Sort", "Merge Sort", "Quick Sort", "Selection Sort", "Insertion Sort"};
    int algoIndex = 0;
    AppState state = AppState::Menu;

    sf::Font font;
    font.loadFromFile("/home/reallyankit/Documents/Snake-sf/Snake/font1.ttf");

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT + 50), "SORT");
    window.setFramerateLimit(240);

    DrawArray draw(HEIGHT, WIDTH, BARS);
    BubbleSort* bs = new BubbleSort(draw);
    MergeSort* merger = new MergeSort(draw);
    QuickSort* qSort = new QuickSort(draw);
    SelectionSort* selSort = new SelectionSort(draw);
    InsertionSort* insSort = new InsertionSort(draw);

    vector<int> arr;
    bool selected = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (state == AppState::Menu) {
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Up) {
                        selectedBars = min(selectedBars + 10, maxBars);
                    }
                    if (event.key.code == sf::Keyboard::Down) {
                        selectedBars = max(selectedBars - 10, minBars);
                    }
                    if (event.key.code == sf::Keyboard::Right) {
                        algoIndex = (algoIndex + 1) % 5;
                    }
                    if (event.key.code == sf::Keyboard::Left) {
                        algoIndex = (algoIndex + 4) % 5;
                    }
                    if (event.key.code == sf::Keyboard::Enter) {
                        BARS = selectedBars;
                        arr = vector<int>(BARS);
                        randomizeArray(arr);
                        algo = static_cast<Algo>(algoIndex);
                        draw = DrawArray(HEIGHT, WIDTH, BARS);
                        delete bs;
                        delete merger;
                        delete qSort;
                        delete selSort;
                        delete insSort;
                        bs = new BubbleSort(draw);
                        merger = new MergeSort(draw);
                        qSort = new QuickSort(draw);
                        selSort = new SelectionSort(draw);
                        insSort = new InsertionSort(draw);
                        state = AppState::Visualizing;
                        selected = true;
                    }
                }
            }
        }

        window.clear();
        if (state == AppState::Menu) {
            sf::Text title("Sorting Visualizer", font, 60);
            title.setFillColor(sf::Color::White);
            title.setPosition(WIDTH / 2 - title.getLocalBounds().width / 2, 100);
            window.draw(title);

            sf::Text arrText("Array Size: " + std::to_string(selectedBars), font, 40);
            arrText.setFillColor(sf::Color::Yellow);
            arrText.setPosition(WIDTH / 2 - arrText.getLocalBounds().width / 2, 250);
            window.draw(arrText);

            sf::Text algoText("Algorithm: " + algoNames[algoIndex], font, 40);
            algoText.setFillColor(sf::Color::Cyan);
            algoText.setPosition(WIDTH / 2 - algoText.getLocalBounds().width / 2, 320);
            window.draw(algoText);

            sf::Text instr("Up/Down: Change Size\nLeft/Right: Change Algo\nEnter: Start", font, 30);
            instr.setFillColor(sf::Color(200,200,200));
            instr.setPosition(WIDTH / 2 - instr.getLocalBounds().width / 2, 400);
            window.draw(instr);

            window.display();
            continue;
        }
        if (selected) {
            switch (algo) {
            case Algo::BubbleSort:
                bs->sort(arr, window);
                selected = false;
                break;
            case Algo::MergeSort:
                merger->merge_sort(arr, 0, arr.size() - 1, window);
                selected = false;
                break;
            case Algo::QuickSort:
                qSort->sort(window, arr);
                selected = false;
                break;
            case Algo::SelectionSort:
                selSort->sort(arr, window);
                selected = false;
                break;
            case Algo::InsertionSort:
                insSort->sort(arr, window);
                selected = false;
                break;
            default:
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
            state = AppState::Menu;
        }
        draw.drawArray(window, arr);
    }
    delete bs;
    delete merger;
    delete qSort;
    delete selSort;
    delete insSort;
    return 0;
}
