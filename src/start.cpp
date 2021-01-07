#include <iostream>
#include <SFML/Graphics.hpp>
#include "start.hpp"

using namespace std;

void start()
{
    sf::RenderWindow window(sf::VideoMode(900, 480), "ToDO");
    sf::Texture backgrounfTexture;
    if (!backgrounfTexture.loadFromFile("../assets/images/back.png"))
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
    todoSprite.setPosition(sf::Vector2f(400, 1));

    sf::Texture add;
    if (!add.loadFromFile("../assets/icons/add.png"))
    {
        // error...
    }
    sf::Sprite addSprite;
    addSprite.setTexture(add);
    addSprite.setPosition(sf::Vector2f(13, 390));

    sf::Texture trashBin;
    if (!trashBin.loadFromFile("../assets/icons/bin.png"))
    {
        // error...
    }
    sf::Sprite trashBinSprite;
    trashBinSprite.setTexture(trashBin);
    trashBinSprite.setPosition(sf::Vector2f(800, 390));

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
            window.draw(trashBinSprite);
            window.display();
        }
    }
}