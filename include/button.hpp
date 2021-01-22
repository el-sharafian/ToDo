#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "set.hpp"

// abstract class

class Button
{
public:
    Button();

protected:
    sf::Font font;
    sf::Texture Texture;
    sf::Sprite Sprite;
    Set set;    //sets Texts and Sprites
};

#endif // BUTTON_HPP
