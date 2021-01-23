#ifndef EDITBUTTON_HPP
#define EDITBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "button.hpp"

// icon for editing task's name

class EditButton : public Button
{
    friend void WindowDisplay(EditButton &);

public:
    std::string Task = "Enter the name of task \n";
    sf::Text TaskText;
    std::string TaskName = "";
    sf::Text TaskNameText;
    std::string Name = "Enter the new name";
    sf::Text NameText;
    std::string NewName = "";
    sf::Text NewNameText;
    EditButton();
    sf::RenderWindow win;
};

#endif // EDITBUTTON_HPP