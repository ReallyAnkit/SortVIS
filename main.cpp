#include "bubblesort.hpp"
#include "drawarray.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

int HEIGHT = 800;
int WIDTH = 1000;
int BARS = 1000;
using namespace std;

enum class Algo { BubbleSort, MergeSort, QuickSort };

void randomizeArray(vector<int> &arr)
{
    for (auto &i : arr) {
        i = rand() % HEIGHT;
    }
}

int main()

{
    srand(time(0));
    vector<int> arr(BARS);
    randomizeArray(arr);

    sf::Font font;
    font.loadFromFile("/home/reallyankit/Documents/Snake-sf/Snake/font1.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Quick");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(96);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);

    text.setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2));

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT + 50), "SORT");
    window.setFramerateLimit(1000000);
    DrawArray draw(HEIGHT, WIDTH, BARS);

    BubbleSort bs(draw);
    MergeSort merger(draw);
    QuickSort qSort(draw);

    Algo algo = Algo::BubbleSort;
    bool selected = true;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::A) {
                    algo = Algo::QuickSort;
                    selected = true;
                }
                if (event.key.code == sf::Keyboard::S) {
                    algo = Algo::MergeSort;
                    selected = true;
                }
            }
        }

        if (selected) {
            switch (algo) {
            case Algo::BubbleSort:
                bs.sort(arr, window);
                selected = false;
                break;
            case Algo::MergeSort:
                merger.merge_sort(arr, 0, arr.size() - 1, window);
                selected = false;
                break;
            case Algo::QuickSort:
                qSort.sort(window, arr);
                selected = false;
                break;
            default:
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // randomizeArray(arr);
        }
        draw.drawArray(window, arr);

        // window.draw(text);
        // window.display();
    }
    return 0;
}
