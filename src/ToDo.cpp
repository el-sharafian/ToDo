#include "todo.hpp"
#include <iostream>
using namespace std;

ToDo::ToDo()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 500), "ToDO");

    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf");
    t.setPosition(100, 100);
    t.setFillColor(sf::Color::Black);
    t.setFont(font);
    s = "This is text that you type: ";
    //  t.setString(s);
    t.setString(s);

    text.setString("Make a ToDo list");
    text.setPosition(sf::Vector2f(300, 0));
    text.setFillColor(sf::Color::Black);
    text.setFont(font);

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

            // if (text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
            // {
            //     text.setFillColor(sf::Color(20, 150, 150));
            // }
            /*else
            {
                text.setFillColor(sf::Color::Black);
            }*/

            if (evnt.type == sf::Event::TextEntered)
            {

                if (evnt.text.unicode < 128)
                {
                    s += static_cast<char>(evnt.text.unicode);
                }
                t.setString(s);
                cout << s << endl;
            }
        }

        window->clear();
        window->draw(sprite);
        icon->add(*window);
        icon->edit(*window);
        icon->list(*window);
        icon->bin(*window);
        window->draw(t);
        window->draw(text);
        window->display();
    }
}

ToDo::~ToDo()
{
    delete window;
    delete icon;
}