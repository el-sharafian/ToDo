#include "icon.hpp"
#include <iostream>

Icon::Icon(std::string imgDirectory)
{
    std::string iconName = imgDirectory + "/add.png";
    if (!addTexture.loadFromFile(iconName))
    {
        // error...
    }
    addSprite.setTexture(addTexture);
    editSprite.setPosition(sf::Vector2f(10, 0));

    iconName = imgDirectory + "/edit5.png";
    if (!editTexture.loadFromFile(iconName))
    {
        //error
    }
    editSprite.setTexture(editTexture);
    editSprite.setPosition(sf::Vector2f(10, 125));

    iconName = imgDirectory + "/list.png";
    if (!listTexture.loadFromFile(iconName))
    {
        // error...
    }
    listSprite.setTexture(listTexture);
    listSprite.setPosition(sf::Vector2f(7, 250));

    iconName = imgDirectory + "/bin.png";
    if (!binTexture.loadFromFile(iconName))
    {
        // error...
    }
    binSprite.setTexture(binTexture);
    binSprite.setPosition(sf::Vector2f(10, 400));
}
// void Icon::IconDisplay(sf::RenderWindow &window)
// {
// }
void Icon::iconEvents(sf::Event evnt, sf::RenderWindow & window)
{
    if (evnt.type == sf::Event::MouseButtonPressed)
    {
        if (evnt.mouseButton.button == sf::Mouse::Left)
        {
            if (addSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                std::cout << "add button" << std::endl;
            }
            else if (binSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                std::cout << "bin button" << std::endl;
            }
            else if (listSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                std::cout << "list button" << std::endl;
            }
            else if (editSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                std::cout << "edit button" << std::endl;
            }
        }
    }
}

void Icon::list(sf::RenderWindow &window)
{
    window.draw(listSprite);
}
void Icon::edit(sf::RenderWindow &window)
{
    window.draw(editSprite);
}
void Icon::add(sf::RenderWindow &window)
{
    window.draw(addSprite);
}
void Icon::bin(sf::RenderWindow &window)
{
    window.draw(binSprite);
}
