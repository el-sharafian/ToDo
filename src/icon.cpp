#include "icon.hpp"
#include "ToDo.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "task.hpp"

#define Sp 20
#define BACKSPACE_key 8
#define Enter_key 13

using namespace std;

Icon::Icon(std::string imgDirectory)
{
    font.loadFromFile("../assets/icons/f1.ttf");

    std::string iconName = imgDirectory + "/add.png";
    set.SetTexture(AddSprite, iconName, AddTexture, 15, 615);

    iconName = imgDirectory + "/edit.png";
    set.SetTexture(EditSprite, iconName, EditTexture, 985, 615);
}
void Icon::IconEvents(sf::Event evnt, sf::RenderWindow &window, vector <Task> & task)
{    
    Task tsk;
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
            if (AddSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                AddButton addbutton;
                addbutton.DisplayWindow(addbutton, task);
            }
            else if (EditSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                EditButton editButton;
                WindowDisplay(editButton, task);
            }
        }
    }
}
sf::Sprite Icon::Edit()
{
    return EditSprite;
}
sf::Sprite Icon::Add()
{
    return AddSprite;
}
void Icon::DrawIcons(sf::RenderWindow &window, sf::Sprite addSprite, sf::Sprite editSprite)
{
    window.draw(addSprite);
    window.draw(editSprite);
}