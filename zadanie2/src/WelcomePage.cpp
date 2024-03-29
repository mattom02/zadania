#include "WelcomePage.hpp"

WelcomePage::WelcomePage(){
    formatText(mainText, 150, 200, "Witaj, z tej strony automat biletowy miasta Krakow,\n           oczekuje wrzucenia do mnie pieniedzy.");
    formatText(currentValueText, 457, 500, "Dodaj:\n     0");
    formatText(OK, 479, 590, "OK");
    formatText(plus, 544, 590, "+");
    formatText(minus, 439, 590, "-");
    formatText(cancel, 100, 800, "Anuluj");
    formatText(PL, 860, 800, "PL");
    formatText(EN, 797, 800, "EN");

    formatBox(box[0], 479, 590, 40, 40, sf::Color(128, 128, 128));
    formatBox(box[1], 532, 590, 40, 40, sf::Color(128, 128, 128));
    formatBox(box[2], 426, 590, 40, 40, sf::Color(128, 128, 128));
    formatBox(box[3], 95, 796, 100, 50, sf::Color(128, 128, 128));
    formatBox(box[4], 855, 796, 50, 50, sf::Color(128, 128, 128));
    formatBox(box[5], 792, 796, 50, 50, sf::Color(128, 128, 128));
    formatBox(arrowTail, 800, 500, 70, 50, sf::Color::White);

    arrowHead[0].position = sf::Vector2f(870, 475);
    arrowHead[1].position = sf::Vector2f(870, 575);
    arrowHead[2].position = sf::Vector2f(910, 525);

}

void WelcomePage::increaseCurrentValue(){
    currentValue++;
    std::stringstream str;
    if(isLanguagePl) {
        if (currentValue < 10) {
            str << "Dodaj:\n     " << std::to_string(currentValue);
        } else {
            str << "Dodaj:\n    " << std::to_string(currentValue);
        }
    }
    else{
        if(currentValue < 10){
            str << "Add:\n   " << std::to_string(currentValue);
        }
        else{
            str << "Add:\n  " << std::to_string(currentValue);
        }
    }
    currentValueText.setString(str.str());
}

void WelcomePage::decreaseCurrentValue(){
    if(currentValue > 0){
        currentValue--;
        std::stringstream str;
        if(isLanguagePl) {
            if (currentValue < 10) {
                str << "Dodaj:\n     " << std::to_string(currentValue);
            } else {
                str << "Dodaj:\n    " << std::to_string(currentValue);
            }
        }
        else{
            if(currentValue < 10){
                str << "Add:\n   " << std::to_string(currentValue);
            }
            else{
                str << "Add:\n  " << std::to_string(currentValue);
            }
        }
        currentValueText.setString(str.str());
    }
}

void WelcomePage::insertCurrentValue(std::size_t &value){
    value += currentValue;
    currentValue = 0;
    if(isLanguagePl) {
        currentValueText.setString("Dodaj:\n     0");
    }
    else{
        currentValueText.setString("Add:\n   0");
    }
    updateTotalValueText(value);
}

void WelcomePage::setEnLanguage(const std::size_t &totalValue){
    isLanguagePl = false;
    formatText(mainText, 250, 200, "Hello, it's Krakow ticket machine here,\n             I await inserting money.");
    std::stringstream str;
    if(currentValue < 10){
        str << "Add:\n   " << std::to_string(currentValue);
    }
    else{
        str << "Add:\n  " << std::to_string(currentValue);
    }
    formatText(currentValueText, 469, 500, str.str());
    formatText(cancel, 98, 800, "Cancel");
    str.str("");
    str << "Balance: " << std::to_string(totalValue);
    formatText(totalValueText, 423, 300, str.str());
}

void WelcomePage::setPlLanguage(const std::size_t &totalValue){
    isLanguagePl = true;
    formatText(mainText, 150, 200, "Witaj, z tej strony automat biletowy miasta Krakow,\n           oczekuje wrzucenia do mnie pieniedzy.");
    formatText(cancel, 100, 800, "Anuluj");
    std::stringstream str;
    if (currentValue < 10) {
        str << "Dodaj:\n     " << std::to_string(currentValue);
    } else {
        str << "Dodaj:\n    " << std::to_string(currentValue);
    }
    formatText(currentValueText, 457, 500, str.str());
    str.str("");
    str << "Saldo: " << std::to_string(totalValue);
    formatText(totalValueText, 448, 300, str.str());
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
    target.draw(cancel, state);
    target.draw(PL, state);
    target.draw(EN, state);
}