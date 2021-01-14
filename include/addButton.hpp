#ifndef ADDBUTTON_HPP
#define ADDBUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../include/task.hpp"

class AddButton
{
 friend void displayWindow(AddButton &);
public:
    AddButton();

private:
    sf::Font font;
    std::string addTask = "Enter name of your task \n";
    std::string taskName = "";
    sf::Text addTaskText;
    std::string limitTaskName = "task name is too long \n";
    sf::Text limitTaskNameText;
    sf::Text TaskNameText;
    sf::RenderWindow win;
    sf::Texture addWindowTexture;
    sf::Sprite addWindowSprite;
    std::vector<Task> tasks;
};

#endif // ADDBUTTON_HPP
