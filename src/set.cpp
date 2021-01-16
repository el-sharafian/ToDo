#include "set.hpp"
#include <iostream>

Set::Set()
{
    // font.SetFromFile("../assets/icons/t1.ttf");
}
void Set::setText(sf::Text &text, int x, int y, std::string textString)
{
    text.setPosition(sf::Vector2f(x, y));
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setString(textString);
    // text.setFont(font);
}
void Set::setTexture(sf::Sprite &sprite, std::string name, sf::Texture &texture, int x, int y)
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