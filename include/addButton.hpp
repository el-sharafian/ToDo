#ifndef ADDBUTTON_HPP
#define ADDBUTTON_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "windowDisplay.hpp"
#include "Button.hpp"

class AddButton //: public Button
{

public:
    AddButton();
    void displayWindow(AddButton &addButton);

private:
    sf::Font font;
    std::string addTask = "Enter name of your task \n";
    sf::Text addTaskText;
    std::string taskName = "";
    std::string limitTaskName = "task name is too long \n";
    sf::Text limitTaskNameText;
    sf::Text TaskNameText;
    sf::RenderWindow win;
    sf::Texture addWindowTexture;
    sf::Sprite addWindowSprite;
    std::vector<Task> tasks;
};

#endif // ADDBUTTON_HPP
