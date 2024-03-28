#include "triangle.hpp"

Triangle::Triangle(triangle Triangle, float Velocity){
    texture = sf::VertexArray(sf::Triangles, 3);
    hitbox = Triangle;
    velocity = Velocity;
    updateHitbox();
}

void Triangle::updateHitbox(){
    texture[0].position = sf::Vector2f(hitbox.points[0].x, hitbox.points[0].y);
    texture[1].position = sf::Vector2f(hitbox.points[1].x, hitbox.points[1].y);
    texture[2].position = sf::Vector2f(hitbox.points[2].x, hitbox.points[2].y);
}

void Triangle::moveLeft() {
    if(hitbox.points[0].x > 0) {
        hitbox.points[0].x -= velocity;
        hitbox.points[1].x -= velocity;
        hitbox.points[2].x -= velocity;
        updateHitbox();
    }
}

void Triangle::moveRight() {
    if(hitbox.points[2].x < 1000) {
        hitbox.points[0].x += velocity;
        hitbox.points[1].x += velocity;
        hitbox.points[2].x += velocity;
        updateHitbox();
    }
}

void Triangle::moveUp() {
    if(hitbox.points[0].y > 0) {
        hitbox.points[0].y -= velocity;
        hitbox.points[1].y -= velocity;
        hitbox.points[2].y -= velocity;
        updateHitbox();
    }
}

void Triangle::moveDown() {
    if(hitbox.points[1].y < 1000) {
        hitbox.points[0].y += velocity;
        hitbox.points[1].y += velocity;
        hitbox.points[2].y += velocity;
        updateHitbox();
    }
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