#pragma once
#include <SFML/Graphics.hpp>
#include "Page.hpp"

class TicketsPage : public sf::Drawable, public Page{
public:
    TicketsPage();

    void setEnLanguage(const std::size_t &totalValue);

    void setPlLanguage(const std::size_t &totalValue);
private:
    sf::Text mainText;

    std::array<sf::RectangleShape, 5> box;

    std::array<int, 5> ticketPrices = {3, 4, 8, 10, 15};

    std::array<sf::Text, 5> textTicketPrices;

    sf::RectangleShape arrowTail;
    sf::VertexArray arrowHead = sf::VertexArray(sf::Triangles, 3);

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};