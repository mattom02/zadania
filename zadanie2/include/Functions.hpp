#pragma once
#include <array>
#include <SFML/Graphics.hpp>

std::array<std::size_t, 3> calculateChange(std::size_t ticket, std::size_t &value);

bool isButtonPressed(const sf::Vector2i &position, int maxX, int minX, int maxY, int minY);