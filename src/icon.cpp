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

Icon::Icon(std::string imgDirectory) //  set textures and sprites
{
    font.loadFromFile("../assets/icons/f1.ttf");

    std::string iconName = imgDirectory + "/add.png";
    set.SetTexture(AddSprite, iconName, AddTexture, 15, 485); // set the add icon and its position

    iconName = imgDirectory + "/edit.png";
    set.SetTexture(EditSprite, iconName, EditTexture, 785, 485); // set the edit icon and its position
}
bool Icon::IconEvents(sf::Event evnt, sf::RenderWindow &window, vector<Task> &task)
{
    Task tsk;
    sf::Text taskNameText;
    sf::Text txt;
    std::string taskName;
    bool taskSize = false;
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
               taskSize = addbutton.DisplayWindow(addbutton, task); // call DisplayWindow function when user press add icon
            }
            else if (EditSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                EditButton editButton;
                WindowDisplay(editButton, task); // call WindowDisplay function when user press Edit icon
            }
        }
    }
    return taskSize;
}
sf::Sprite Icon::Edit() // return EditSprite
{
    return EditSprite;
}
sf::Sprite Icon::Add() // return AddSprite
{
    return AddSprite;
}
void Icon::DrawIcons(sf::RenderWindow &window, sf::Sprite addSprite, sf::Sprite editSprite)
{
    window.draw(addSprite);  // draw add Icon
    window.draw(editSprite); // draw edit Icon
}