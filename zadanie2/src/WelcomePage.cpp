#include "WelcomePage.hpp"

WelcomePage::WelcomePage(){
    formatText(mainText, 150, 200, "Witaj, z tej strony automat biletowy miasta Krakow,\n           oczekuje wrzucenia do mnie pieniedzy.");
    formatText(currentValueText, 457, 500, "Dodaj:\n     0");
    formatText(OK, 479, 590, "OK");
    formatText(plus, 544, 590, "+");
    formatText(minus, 439, 590, "-");

    formatBox(box[0], 479, 590, 40, 40, sf::Color(128, 128, 128));
    formatBox(box[1], 532, 590, 40, 40, sf::Color(128, 128, 128));
    formatBox(box[2], 426, 590, 40, 40, sf::Color(128, 128, 128));
    formatBox(arrowTail, 800, 500, 70, 50, sf::Color::White);

    arrowHead[0].position = sf::Vector2f(870, 475);
    arrowHead[1].position = sf::Vector2f(870, 575);
    arrowHead[2].position = sf::Vector2f(910, 525);

}

void WelcomePage::increaseCurrentValue(){
    currentValue++;
    std::stringstream str;
    if(currentValue < 10){
        str << "Dodaj:\n     " << std::to_string(currentValue);
    }
    else{
        str << "Dodaj:\n    " << std::to_string(currentValue);
    }
    currentValueText.setString(str.str());
}

void WelcomePage::decreaseCurrentValue(){
    if(currentValue > 0){
        currentValue--;
        std::stringstream str;
        if(currentValue < 10){
            str << "Dodaj:\n     " << std::to_string(currentValue);
        }
        else{
            str << "Dodaj:\n    " << std::to_string(currentValue);
        }
        currentValueText.setString(str.str());
    }
}

void WelcomePage::insertCurrentValue(std::size_t &value){
    value += currentValue;
    currentValue = 0;
    currentValueText.setString("Dodaj:\n     0");
    updateTotalValueText(value);
}

void WelcomePage::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    for(const auto &i : box){
        target.draw(i, state);
    }
    target.draw(arrowTail, state);
    target.draw(arrowHead, state);
    target.draw(mainText, state);
    target.draw(currentValueText, state);
    target.draw(totalValueText, state);
    target.draw(OK, state);
    target.draw(plus, state);
    target.draw(minus, state);
}