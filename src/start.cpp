#include <iostream>
#include <SFML/Graphics.hpp>
#include "start.hpp"

using namespace std;

void changecolor(sf::RenderWindow &window, sf::Text text)
{
    window.draw(text);

    // if (text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
    // {
    //     text.setFillColor(sf::Color::Blue);
    // }
    // else
    // {
    //     text.setFillColor(sf::Color(20, 150, 150));
    // }
}

void start()
{
    sf::RenderWindow window(sf::VideoMode(800, 500), "ToDO");

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

    sf::Texture add;
    if (!add.loadFromFile("../assets/icons/add.png"))
    {
        // error...
    }
    sf::Sprite addSprite;
    addSprite.setTexture(add);
    addSprite.setPosition(sf::Vector2f(10, 0));

    sf::Texture edit;
    if (!edit.loadFromFile("../assets/icons/edit5.png"))
    {
        // error...
    }
    sf::Sprite editSprite;
    editSprite.setTexture(edit);
    editSprite.setPosition(sf::Vector2f(10, 100));

    sf::Texture todo;
    if (!todo.loadFromFile("../assets/icons/todo4.png"))
    {
        // error...
    }
    sf::Sprite todoSprite;
    todoSprite.setTexture(todo);
    todoSprite.setPosition(sf::Vector2f(7, 200));

    sf::Texture trashBin;
    if (!trashBin.loadFromFile("../assets/icons/bin.png"))
    {
        // error...
    }
    sf::Sprite trashBinSprite;
    trashBinSprite.setTexture(trashBin);
    trashBinSprite.setPosition(sf::Vector2f(10, 400));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (addSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        cout << "add" << endl;
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (trashBinSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        cout << "delete" << endl;
                    }
                }
            }
            if (text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
            {
                text.setFillColor(sf::Color(20, 150, 150));
            }
            else
            {
                text.setFillColor(sf::Color::Black);
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    s += static_cast<char>(event.text.unicode);
                }
            }
        }
        t.setString(s);
        window.clear();
        window.draw(sprite);
        window.draw(todoSprite);
        window.draw(addSprite);
        window.draw(editSprite);
        window.draw(trashBinSprite);
        // changecolor(window, t);
        window.draw(t);
        window.draw(text);
        window.display();
    }
}