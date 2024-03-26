#include "collision.hpp"
#include "triangle.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Triangles collision");

    vec2 p11(100, 300);
    vec2 p12(100, 500);
    vec2 p13(300, 400);

    vec2 p21(600, 300);
    vec2 p22(600, 500);
    vec2 p23(800, 400);

    triangle triangle1;
    triangle1.points = {p11, p12, p13};

    triangle triangle2;
    triangle2.points = {p21, p22, p23};

    Triangle Triangle1 = Triangle(triangle1);
    Triangle Triangle2 = Triangle(triangle2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Triangle1.moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            Triangle1.moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Triangle1.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Triangle1.moveDown();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Triangle2.moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Triangle2.moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Triangle2.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Triangle2.moveDown();
        }
        if(isColliding(Triangle1.getHitbox(), Triangle2.getHitbox())){
            Triangle1.changeColorToRed();
            Triangle2.changeColorToRed();
        }
        else{
            Triangle1.changeColorToWhite();
            Triangle2.changeColorToWhite();
        }
        window.clear();
        window.draw(Triangle1);
        window.draw(Triangle2);
        window.display();
    }
}