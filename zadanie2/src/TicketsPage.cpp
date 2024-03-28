#include "TicketsPage.hpp"

TicketsPage::TicketsPage(){
    formatText(mainText, 270, 200, "Wybierz bilet ktory chcesz kupic.");

    formatBox(box[0], 415, 390, 70, 70, sf::Color(128, 128, 128));
    formatBox(box[1], 415, 490, 70, 70, sf::Color(128, 128, 128));
    formatBox(box[2], 515, 390, 70, 70, sf::Color(128, 128, 128));
    formatBox(box[3], 515, 490, 70, 70, sf::Color(128, 128, 128));
    formatBox(box[4], 465, 590, 70, 70, sf::Color(128, 128, 128));

    formatText(textTicketPrices[0], 441, 405, std::to_string(ticketPrices[0]));
    formatText(textTicketPrices[1], 441, 505, std::to_string(ticketPrices[1]));
    formatText(textTicketPrices[2], 541, 405, std::to_string(ticketPrices[2]));
    formatText(textTicketPrices[3], 532, 505, std::to_string(ticketPrices[3]));
    formatText(textTicketPrices[4], 482, 605, std::to_string(ticketPrices[4]));

    formatBox(arrowTail, 130, 500, 70, 50, sf::Color::White);

    arrowHead[0].position = sf::Vector2f(130, 475);
    arrowHead[1].position = sf::Vector2f(130, 575);
    arrowHead[2].position = sf::Vector2f(90, 525);
}

void TicketsPage::draw(sf::RenderTarget& target, sf::RenderStates state) const{
    for(const auto &i : box){
        target.draw(i, state);
    }
    for(const auto &i : textTicketPrices){
        target.draw(i, state);
    }
    target.draw(arrowHead, state);
    target.draw(arrowTail, state);
    target.draw(mainText, state);
    target.draw(totalValueText, state);
}