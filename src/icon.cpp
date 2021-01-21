#include "icon.hpp"
#include "table.hpp"
#include "ToDo.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "file.hpp"

#define Sp 20
#define BACKSPACE_key 8
#define Enter_key 13

using namespace std;

Icon::Icon(std::string imgDirectory)
{
    font.loadFromFile("../assets/icons/f1.ttf");

    std::string iconName = imgDirectory + "/add.png";
    set.setTexture(addSprite, iconName, addTexture, 10, 410);

    iconName = imgDirectory + "/edit5.png";
    set.setTexture(editSprite, iconName, editTexture, 685, 390);
}
void Icon::iconEvents(sf::Event evnt, sf::RenderWindow &window)
{
    sf::Text taskNameText;
    sf::Text txt;
    std::string taskName;
    taskNameText.setFont(font);
    taskNameText.setPosition(sf::Vector2f(5, 25));
    taskNameText.setFillColor(sf::Color(20, 100, 100));
    txt.setFont(font);
    txt.setPosition(sf::Vector2f(400, 300));
    txt.setFillColor(sf::Color::Black);

    if (evnt.type == sf::Event::MouseButtonPressed)
    {
        if (evnt.mouseButton.button == sf::Mouse::Left)
        {
            if (addSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                AddButton addbutton;
                addbutton.DisplayWindow(addbutton);
            }
            else if (editSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                EditButton editButton;
                WindowDisplay(editButton);
            }
           /* else if (FavoriteSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                FavoriteButton favoriteButton;
                WindowDisplay(favoriteButton);
            }*/
        }
    }
}
sf::Sprite Icon::edit()
{
    return editSprite;
}
sf::Sprite Icon::add()
{
    return addSprite;
}
void Icon::DrawIcons(sf::RenderWindow &window, sf::Sprite addSprite, sf::Sprite editSprite)
{
    window.draw(addSprite);
    window.draw(editSprite);
}