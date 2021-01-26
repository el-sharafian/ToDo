#ifndef ADDBUTTON_HPP
#define ADDBUTTON_HPP

#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "task.hpp"

class AddButton     // adds a task
{
public:
    AddButton();
    void DisplayWindow(AddButton &,  std::vector<Task> &);

private:
    Set set;
    sf::Texture Texture;
    sf::Sprite Sprite;
    std::string addTask = "Enter name of your task \n";
    sf::Text AddTaskText;
    std::string TaskName = "";
    sf::Text TaskNameText;
    sf::RenderWindow Win;
    sf::Font Fontt;
};

#endif // ADDBUTTON_HPP
