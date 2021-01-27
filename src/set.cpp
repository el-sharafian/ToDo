#include "set.hpp"
#include <iostream>

Set::Set()
{
}
void Set::SetText(sf::Text &text, int x, int y, std::string textString)//function for set string,position,size and color of Text
{
    text.setPosition(sf::Vector2f(x, y));
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setString(textString);
}
void Set::SetTexture(sf::Sprite &sprite, std::string name, sf::Texture &texture, int x, int y)//function for set icons and their position
{
    if (!texture.loadFromFile(name))
    {
        // error ...
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(x, y));
}
Set::~Set()
{
}