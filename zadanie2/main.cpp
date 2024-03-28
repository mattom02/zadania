#include "WelcomePage.hpp"
#include "TicketsPage.hpp"
#include "TextPage.hpp"
#include "Change.hpp"
#include <thread>
#include <chrono>

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Ticket machine");
    sf::RectangleShape background(sf::Vector2f(950, 950));
    background.setPosition(sf::Vector2f(25, 25));
    background.setFillColor(sf::Color::Black);
    background.setOutlineThickness(100);
    background.setOutlineColor(sf::Color(0, 0, 128));

    WelcomePage welcomePage;
    TicketsPage ticketsPage;
    TextPage printPage("Trwa proces drukowania biletu.", 280, 200);
    TextPage backPage("Oddaje monety.", 392, 200);
    TextPage errorPage("Twoje saldo jest niewystarczajace.", 260, 200);
    TextPage changePage("",200, 200);
    TextPage endPage("", 150, 200);
    sf::Event event;

    size_t currentPage = 0;
    size_t totalValue = 0;
    size_t selectedTicket = 0;

    std::stringstream str;
    std::array<size_t, 3> change;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased){
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                switch (currentPage){
                    case 0:
                        if(mousePosition.x < 466 && mousePosition.x > 426 && mousePosition.y < 630 && mousePosition.y > 590){
                            welcomePage.decreaseCurrentValue();
                        }
                        else if(mousePosition.x < 519 && mousePosition.x > 479 && mousePosition.y < 630 && mousePosition.y > 590){
                            welcomePage.insertCurrentValue(totalValue);
                            ticketsPage.updateTotalValueText(totalValue);
                        }
                        else if(mousePosition.x < 572 && mousePosition.x > 532 && mousePosition.y < 630 && mousePosition.y > 590){
                            welcomePage.increaseCurrentValue();
                        }
                        else if(mousePosition.x < 910 && mousePosition.x > 800 && mousePosition.y < 575 && mousePosition.y > 475){
                            currentPage = 1;
                        }
                        break;
                    case 1:
                        if(mousePosition.x < 200 && mousePosition.x > 90 && mousePosition.y < 575 && mousePosition.y > 475){
                            if(totalValue != 0) {
                                currentPage = 2;
                                totalValue = 0;
                                ticketsPage.updateTotalValueText(totalValue);
                                welcomePage.updateTotalValueText(totalValue);
                            }
                            else{
                                currentPage = 0;
                            }
                        }
                        else {
                            if (mousePosition.x < 485 && mousePosition.x > 415 && mousePosition.y < 460 && mousePosition.y > 390) {
                                selectedTicket = 3;
                                currentPage = 3;
                            } else if (mousePosition.x < 485 && mousePosition.x > 415 && mousePosition.y < 560 && mousePosition.y > 490) {
                                selectedTicket = 4;
                                currentPage = 3;
                            } else if (mousePosition.x < 585 && mousePosition.x > 515 && mousePosition.y < 460 && mousePosition.y > 390) {
                                selectedTicket = 8;
                                currentPage = 3;
                            } else if (mousePosition.x < 585 && mousePosition.x > 515 && mousePosition.y < 560 && mousePosition.y > 490) {
                                selectedTicket = 10;
                                currentPage = 3;
                            } else if (mousePosition.x < 535 && mousePosition.x > 465 && mousePosition.y < 660 && mousePosition.y > 590) {
                                selectedTicket = 15;
                                currentPage = 3;
                            }
                            if (selectedTicket > totalValue) {
                                selectedTicket = 0;
                                currentPage = 4;
                            }
                        }
                        break;
                }
            }
        }
        window.draw(background);
        switch (currentPage){
            case 0:
                window.draw(welcomePage);
                window.display();
                break;
            case 1:
                window.draw(ticketsPage);
                window.display();
                break;
            case 2:
                window.draw(backPage);
                window.display();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                currentPage = 0;
                break;
            case 3:
                window.draw(printPage);
                window.display();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                currentPage = 5;
                break;
            case 4:
                window.draw(errorPage);
                window.display();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                currentPage = 0;
                break;
            case 5:
                str.str("");
                str << "Bilet zostal wydrukowany, oto Twoja reszta:\n                     ";
                change = calculateChange(selectedTicket, totalValue);
                str << change[0] << "*5 zl, " << change[1] << "*2 zl, " << change[2] << "*1 zl";
                changePage.setString(str.str());
                window.draw(changePage);
                window.display();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                currentPage = 6;
                totalValue = 0;
                welcomePage.updateTotalValueText(totalValue);
                ticketsPage.updateTotalValueText(totalValue);
                break;
            case 6:
                str.str("");
                str << "Zycze milego dnia Twoj bilet ";
                str << selectedTicket << " oczekuje na odbior.";
                endPage.setString(str.str());
                window.draw(endPage);
                window.display();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                selectedTicket = 0;
                currentPage = 0;
                break;
        }
    }
}
