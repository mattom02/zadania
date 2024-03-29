#include "WelcomePage.hpp"
#include "TicketsPage.hpp"
#include "TextPage.hpp"
#include "Functions.hpp"
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

    bool isLanguagePL = true;

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
                        if(isButtonPressed(mousePosition, 466, 426, 630, 590)){
                            welcomePage.decreaseCurrentValue();
                        }
                        else if(isButtonPressed(mousePosition, 519, 479, 630, 590)){
                            welcomePage.insertCurrentValue(totalValue);
                            ticketsPage.updateTotalValueText(totalValue);
                        }
                        else if(isButtonPressed(mousePosition, 572, 532, 630, 590)){
                            welcomePage.increaseCurrentValue();
                        }
                        else if(isButtonPressed(mousePosition, 910, 800, 575, 475)){
                            currentPage = 1;
                        }
                        else if(isButtonPressed(mousePosition, 195, 95, 846, 796)){
                            if(totalValue != 0) {
                                currentPage = 2;
                                totalValue = 0;
                                ticketsPage.updateTotalValueText(totalValue);
                                welcomePage.updateTotalValueText(totalValue);
                            }
                        }
                        else if(isButtonPressed(mousePosition, 842, 792, 846, 796)){
                            isLanguagePL = false;
                            welcomePage.setEnLanguage(totalValue);
                            ticketsPage.setEnLanguage(totalValue);
                            printPage.formatText(330, 200, "The ticket is being printed.");
                            backPage.formatText(392, 200, "Returning money.");
                            errorPage.formatText(290, 200,"You don't have enough balance.");
                        }
                        else if(isButtonPressed(mousePosition, 905, 855, 846, 796)){
                            isLanguagePL = true;
                            welcomePage.setPlLanguage(totalValue);
                            ticketsPage.setPlLanguage(totalValue);
                            printPage.formatText(280, 200, "Trwa proces drukowania biletu.");
                            backPage.formatText(392, 200, "Oddaje monety.");
                            errorPage.formatText(260, 200, "Twoje saldo jest niewystarczajace.");
                        }
                        break;
                    case 1:
                        if(isButtonPressed(mousePosition, 200, 90, 575, 475)){
                            currentPage = 0;
                        }
                        else {
                            if (isButtonPressed(mousePosition, 485, 415, 460, 390)) {
                                selectedTicket = 3;
                                currentPage = 3;
                            } else if (isButtonPressed(mousePosition, 485, 415, 560, 490)) {
                                selectedTicket = 4;
                                currentPage = 3;
                            } else if (isButtonPressed(mousePosition, 585, 515, 460, 390)) {
                                selectedTicket = 8;
                                currentPage = 3;
                            } else if (isButtonPressed(mousePosition, 585, 515, 560, 490)) {
                                selectedTicket = 10;
                                currentPage = 3;
                            } else if (isButtonPressed(mousePosition, 535, 465, 660, 590)) {
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
                currentPage = 1;
                break;
            case 5:
                str.str("");
                if(isLanguagePL){
                    str << "Bilet zostal wydrukowany, oto Twoja reszta:\n                     ";
                }
                else{
                    str << "The ticket has been printed, take the change:\n                      ";
                }
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
                if(isLanguagePL) {
                    str << "Zycze milego dnia, Twoj bilet ";
                    str << selectedTicket << " oczekuje na odbior.";
                }
                else{
                    str << "Have a nice day, your ticket ";
                    str << selectedTicket << " is ready to be taken.";
                }
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
