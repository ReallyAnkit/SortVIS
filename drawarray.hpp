#ifndef DRAWARRAY_HPP
#define DRAWARRAY_HPP
#include <SFML/Graphics.hpp>
#include <vector>
class DrawArray
{
public:
    DrawArray(int height, int width, int num_of_bars);
    void drawArray(sf::RenderWindow &window, const std::vector<int> &vec);

private:
    int height;
    int width;
    int num_of_bars;
    float bar_width;
};

#endif // DRAWARRAY_HPP
