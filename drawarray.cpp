#include "drawarray.hpp"

DrawArray::DrawArray(int height, int width, int num_of_bars)
    : height(height)
    , width(width)
    , num_of_bars(num_of_bars)
{
    bar_width = float(width) / (float) num_of_bars;
}

void DrawArray::drawArray(sf::RenderWindow &window, const std::vector<int> &vec)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (!window.isOpen())
        return;
    window.clear();

    for (int i = 0; i < num_of_bars; i++) {
        sf::RectangleShape bar(sf::Vector2f(bar_width - 2, vec[i]));
        bar.setFillColor(sf::Color::Blue);
        bar.setPosition(i * bar_width, height - vec[i]);
        bar.setOutlineThickness(1);
        window.draw(bar);
    }
    window.display();
}
