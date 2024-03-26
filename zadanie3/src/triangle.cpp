#include "triangle.hpp"

Triangle::Triangle(triangle Triangle){
    texture = sf::VertexArray(sf::Triangles, 3);
    hitbox = Triangle;
    updateHitbox();
}

void Triangle::updateHitbox(){
    texture[0].position = sf::Vector2f(hitbox.points[0].x, hitbox.points[0].y);
    texture[1].position = sf::Vector2f(hitbox.points[1].x, hitbox.points[1].y);
    texture[2].position = sf::Vector2f(hitbox.points[2].x, hitbox.points[2].y);
}

void Triangle::moveLeft() {
    hitbox.points[0].x -= 1;
    hitbox.points[1].x -= 1;
    hitbox.points[2].x -= 1;
    updateHitbox();
}

void Triangle::moveRight() {
    hitbox.points[0].x += 1;
    hitbox.points[1].x += 1;
    hitbox.points[2].x += 1;
    updateHitbox();
}

void Triangle::moveUp() {
    hitbox.points[0].y -= 1;
    hitbox.points[1].y -= 1;
    hitbox.points[2].y -= 1;
    updateHitbox();
}

void Triangle::moveDown() {
    hitbox.points[0].y += 1;
    hitbox.points[1].y += 1;
    hitbox.points[2].y += 1;
    updateHitbox();
}

void Triangle::changeColorToRed() {
    texture[0].color = sf::Color::Red;
    texture[1].color = sf::Color::Red;
    texture[2].color = sf::Color::Red;
}

void Triangle::changeColorToWhite() {
    texture[0].color = sf::Color::White;
    texture[1].color = sf::Color::White;
    texture[2].color = sf::Color::White;
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(texture, state);
}