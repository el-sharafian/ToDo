#include <iostream>
#include <SFML/Graphics.hpp>
#include "start.hpp"

using namespace std;

void start()
{
    sf::RenderWindow window(sf::VideoMode(800, 500), "ToDO");
    sf::Texture backgrounfTexture;
    if (!backgrounfTexture.loadFromFile("../assets/images/bb.jpeg"))
    {
        // error...
    }
    sf::Sprite sprite;
    sprite.setTexture(backgrounfTexture);

    sf::Texture todo;
    if (!todo.loadFromFile("../assets/icons/todo4.png"))
    {
        // error...
    }
    sf::Sprite todoSprite;
    todoSprite.setTexture(todo);
    todoSprite.setPosition(sf::Vector2f(400, 400));

    sf::Texture add;
    if (!add.loadFromFile("../assets/icons/add.png"))
    {
        // error...
    }
    sf::Sprite addSprite;
    addSprite.setTexture(add);
    addSprite.setPosition(sf::Vector2f(13, 400));

    sf::Texture trashBin;
    if (!trashBin.loadFromFile("../assets/icons/bin.png"))
    {
        // error...
    }
    sf::Sprite trashBinSprite;
    trashBinSprite.setTexture(trashBin);
    trashBinSprite.setPosition(sf::Vector2f(280, 400));

    sf::Texture edit;
    if (!edit.loadFromFile("../assets/icons/edit5.png"))
    {
        // error...
    }
    sf::Sprite editSprite;
    editSprite.setTexture(edit);
    editSprite.setPosition(sf::Vector2f(150, 410));

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
            
            window.clear();
            window.draw(sprite);
            window.draw(todoSprite);
            window.draw(addSprite);
            window.draw(editSprite);
            window.draw(trashBinSprite);
            window.display();
        }
    }
}