#include <iostream>
#include <SFML/Graphics.hpp>
#include "start.hpp"
#include "icon.hpp"

using namespace std;

void start()
{
    sf::RenderWindow window(sf::VideoMode(800, 500), "ToDO");
    string name = "../assets/icons";
    Icon icon(name);

    sf::Font font;
    font.loadFromFile("../assets/icons/font.ttf");
    sf::Text t;
    t.setPosition(100, 100);
    t.setFillColor(sf::Color::Black);
    t.setFont(font);
    std::string s = "This is text that you type: ";
    t.setString(s);

    sf::Text text;
    text.setString("Make a ToDo list");
    text.setPosition(sf::Vector2f(300, 0));
    text.setFillColor(sf::Color::Black);
    text.setFont(font);

    sf::Texture backgrounfTexture;
    if (!backgrounfTexture.loadFromFile("../assets/images/ax5.jpg"))
    {
        // error...
    }
    sf::Sprite sprite;
    sprite.setTexture(backgrounfTexture);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                icon.iconEvents(evnt);
            }
            
            if (text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
            {
                text.setFillColor(sf::Color(20, 150, 150));
            }
            else
            {
                text.setFillColor(sf::Color::Black);
            }
            if (evnt.type == sf::Event::TextEntered)
            {
                if (evnt.text.unicode < 128)
                {
                    s += static_cast<char>(evnt.text.unicode);
                }
            }
        }
        t.setString(s);
        window.clear();
        window.draw(sprite);
        icon.add(window);
        icon.edit(window);
        icon.list(window);
        icon.bin(window);
        window.draw(t);
        window.draw(text);
        window.display();
    }
}