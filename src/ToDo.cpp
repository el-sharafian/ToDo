#include "todo.hpp"
#include "set.hpp"
#include <iostream>
using namespace std;

ToDo::ToDo()
{
    Set set;
    window = new sf::RenderWindow(sf::VideoMode(800, 500), "ToDO");
    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf");

    text.setFont(font);
    set.setText(text, 300, 0, "Make a ToDo list");

    if (!backgrounfTexture.loadFromFile("../assets/images/ax5.jpg"))
    {
        // error...
    }
    sprite.setTexture(backgrounfTexture);
}
void ToDo::Loop()
{
    while (window->isOpen())
    {
        sf::Event evnt;
        while (window->pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window->close();
            }
            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                icon->iconEvents(evnt, *window);
            }
            if (text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
            {
                text.setFillColor(sf::Color(20, 150, 150));
            }
            else
            {
                text.setFillColor(sf::Color::Black);
            }
        }
        window->clear();
        window->draw(sprite);
        icon->DrawIcons(*window, icon->add(), icon->bin(), icon->edit());
        window->draw(text);
        window->display();
    }
}

ToDo::~ToDo()
{
    delete window;
    delete icon;
}