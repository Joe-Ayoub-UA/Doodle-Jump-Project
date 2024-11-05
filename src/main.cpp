//
// Created by s0230501 on 5/11/24.
//
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFMLApplication");
    sf::RectangleShape shape1;
    shape1.setSize({400,200});
    shape1.setFillColor(sf::Color::Blue);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape1);
        window.display();
    }
    return 0;
}