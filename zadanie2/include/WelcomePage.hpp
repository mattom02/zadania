#pragma once
#include <SFML/Graphics.hpp>
#include "Page.hpp"

class WelcomePage : public sf::Drawable, public Page{
public:
    WelcomePage();

    void increaseCurrentValue();

    void decreaseCurrentValue();

    void insertCurrentValue(std::size_t &value);

    void setEnLanguage(const std::size_t &totalValue);

    void setPlLanguage(const std::size_t &totalValue);
private:
    sf::Text mainText;
    sf::Text currentValueText;
    sf::Text OK;
    sf::Text plus;
    sf::Text minus;
    sf::Text cancel;
    sf::Text PL;
    sf::Text EN;

    size_t currentValue = 0;

    std::array<sf::RectangleShape, 6> box;

    sf::RectangleShape arrowTail;
    sf::VertexArray arrowHead = sf::VertexArray(sf::Triangles, 3);

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};