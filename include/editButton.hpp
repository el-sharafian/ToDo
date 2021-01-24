#ifndef EDITBUTTON_HPP
#define EDITBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "button.hpp"
#include <fstream>
#include <string>

class EditButton : public Button    // icon for editing task's name
{
    friend void WindowDisplay(EditButton &);

public:
    EditButton();
    sf::RenderWindow win;
    unsigned int search(std::fstream &, std::string &);

private:
    std::string Task = "Enter the name of task \n";
    sf::Text TaskText;
    std::string TaskName = "";
    sf::Text TaskNameText;
    std::string Name = "Enter the new name";
    sf::Text NameText;
    std::string NewName = "";
    sf::Text NewNameText;
    sf::Text Text;
    std::string TextString = "Press Escape to change the name";
};

#endif // EDITBUTTON_HPP