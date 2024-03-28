#include "Functions.hpp"

std::array<std::size_t, 3> calculateChange(std::size_t ticket, std::size_t &value){
    std::array<std::size_t, 3> change;
    value -= ticket;
    change[0] = std::size_t(value / 5);
    value -= 5 * change[0];
    change[1] = std::size_t(value / 2);
    value -= 2 * change[1];
    change[2] = std::size_t(value / 1);
    value = 0;
    return change;
}

bool isButtonPressed(const sf::Vector2i &position, int maxX, int minX, int maxY, int minY){
    if(position.x < maxX && position.x > minX && position.y < maxY && position.y > minY){
        return true;
    }
    return false;
}