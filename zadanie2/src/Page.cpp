#include "Page.hpp"

Page::Page(){
    font.loadFromFile("font.ttf");
    formatText(totalValueText, 448, 300, "Saldo: 0");
}

void Page::formatText(sf::Text &text, int x, int y, std::string str){
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
    text.setString(str);
}

void Page::formatBox(sf::RectangleShape &box, int x, int y, int sizeX, int sizeY, sf::Color color){
    box.setSize(sf::Vector2f(sizeX, sizeY));
    box.setFillColor(color);
    box.setPosition(x, y);
}

void Page::updateTotalValueText(std::size_t value){
    std::stringstream str;
    str << "Saldo: " << std::to_string(value);
    totalValueText.setString(str.str());
}

