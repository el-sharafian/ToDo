#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "set.hpp"

//abstract class
class Button
{
    friend void WindowDisplay(Button &);

public:
    Button();

protected:
    std::string Task = "Enter the number of task \n";
    sf::Text TaskText;
    std::string TaskNumber = "";
    sf::Text TaskNumberText;
    sf::RenderWindow win;
    sf::Font font;
    sf::Texture WindowTexture;
    sf::Sprite WindowSprite;
    Set set;    //sets Texts and Sprites
};

#endif // BUTTON_HPP
