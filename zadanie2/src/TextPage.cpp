#include "TextPage.hpp"

TextPage::TextPage(std::string str, int x, int y){
    Page::formatText(mainText, x, y, str);
}

void TextPage::formatText(int x, int y, std::string str){
    mainText.setPosition(x, y);
    mainText.setString(str);
}

void TextPage::setString(std::string str){
    mainText.setString(str);
}

void TextPage::draw(sf::RenderTarget& target, sf::RenderStates state) const{
    target.draw(mainText, state);
}