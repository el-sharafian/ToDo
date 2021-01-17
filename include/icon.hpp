#ifndef ICON_HPP
#define ICON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "set.hpp"
#include "editButton.hpp"
#include "deleteButton.hpp"
#include "addButton.hpp"
#include "Button.hpp"

class Icon
{
public:
    Icon(std::string);
    void iconEvents(sf::Event, sf::RenderWindow &);
    sf::Sprite edit();
    sf::Sprite add();
    void DrawIcons(sf::RenderWindow &window, sf::Sprite, sf::Sprite);

private:
    sf::Texture addTexture;
    sf::Sprite addSprite;
    sf::Texture editTexture;
    sf::Sprite editSprite;
    sf::Font font;
    Set set;    //sets Texts and Sprites
};

#endif // ICON_HPP
