#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "set.hpp"

//abstract class
class Button
{
    friend void WindowDisplay(Button &);

public:
    Button();

protected:
    std::string Task = "Enter the name of task \n";
    sf::Text TaskText;
    std::string TaskName = "";
    sf::Text TaskNameText;
    sf::RenderWindow win;
    sf::Font font;
    sf::Texture Texture;
    sf::Sprite Sprite;
    Set set;    //sets Texts and Sprites
};

#endif // BUTTON_HPP
