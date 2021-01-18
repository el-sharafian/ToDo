#ifndef ADDBUTTON_HPP
#define ADDBUTTON_HPP

#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "windowDisplay.hpp"
#include "Button.hpp"
#include "vector.hpp"

class AddButton //: public Button
{

public:
    AddButton();
    void displayWindow(AddButton &addButton);

private:
    std::string addTask = "Enter name of your task \n";
    sf::Text addTaskText;
    std::string taskName = "";
    sf::Text TaskNameText;
    sf::RenderWindow win;
    sf::Texture addWindowTexture;
    sf::Sprite addWindowSprite;
    Set set;
    sf::Font fontt;
};

#endif // ADDBUTTON_HPP
