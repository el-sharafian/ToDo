#ifndef ADDBUTTON_HPP
#define ADDBUTTON_HPP

#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "button.hpp"

class AddButton : public Button    // adds a task
{
public:
    AddButton();
    void DisplayWindow(AddButton &,  std::vector<Task> &);  //displays AddButton Window

private:
    std::string addTask = "Enter name of your task \n";
    sf::Text AddTaskText;
    std::string TaskName = "";
    sf::Text TaskNameText;
    std::string WindowString = "Please close the window to add the task";
    sf::Text WindowText;
    sf::RenderWindow Win;
};

#endif // ADDBUTTON_HPP
