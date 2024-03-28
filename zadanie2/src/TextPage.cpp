#include "TextPage.hpp"

TextPage::TextPage(std::string str, int x, int y){
    formatText(mainText, x, y, str);
}

void TextPage::setString(std::string str){
    mainText.setString(str);
}

void TextPage::draw(sf::RenderTarget& target, sf::RenderStates state) const{
    target.draw(mainText, state);
}