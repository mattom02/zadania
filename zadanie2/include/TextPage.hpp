#pragma once
#include <SFML/Graphics.hpp>
#include "Page.hpp"

class TextPage : public sf::Drawable, protected Page{
public:
    TextPage(std::string str, int x ,int y);

    void setString(std::string str);
private:
    sf::Text mainText;

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};