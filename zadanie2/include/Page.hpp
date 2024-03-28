#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <array>

class Page{
public:
    Page();

    void formatText(sf::Text &text, int x, int y, std::string str);

    void formatBox(sf::RectangleShape &box, int x, int y, int sizeX, int sizeY, sf::Color color);

    void updateTotalValueText(std::size_t value);

    sf::Font font;

    sf::Text totalValueText;
};