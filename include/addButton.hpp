#ifndef ADDBUTTON_HPP
#define ADDBUTTON_HPP

#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "windowDisplay.hpp"
// #include "Button.hpp"
#include "vector.hpp"

class AddButton //: public Button
{

public:
    AddButton();
    void DisplayWindow(AddButton &);

private:
    std::string addTask = "Enter name of your task \n";
    sf::Text AddTaskText;
    std::string TaskName = "";
    sf::Text TaskNameText;
    sf::RenderWindow Win;
    sf::Texture AddWindowTexture;
    sf::Sprite AddWindowSprite;
    Set set;
    sf::Font Fontt;
};

#endif // ADDBUTTON_HPP
