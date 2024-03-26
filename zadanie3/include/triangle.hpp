#pragma once
#include "collision.hpp"
#include "SFML/Graphics.hpp"

class Triangle : public sf::Drawable{
public:
    explicit Triangle(triangle Triangle);

    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void updateHitbox();

    void changeColorToRed();

    void changeColorToWhite();

    triangle getHitbox() const { return hitbox; }
private:
    sf::VertexArray texture;
    triangle hitbox;

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};