#ifndef ICON_HPP
#define ICON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../include/task.hpp"

class Icon
{
public:
    Icon(std::string);
    // void IconDisplay(sf::RenderWindow &);
    void iconEvents(sf::Event, sf::RenderWindow &);
    void list(sf::RenderWindow &);
    void edit(sf::RenderWindow &);
    void add(sf::RenderWindow &);
    void bin(sf::RenderWindow &);

private:
    sf::Texture addTexture;
    sf::Sprite addSprite;
    sf::Texture binTexture;
    sf::Sprite binSprite;
    sf::Texture editTexture;
    sf::Sprite editSprite;
    sf::Texture listTexture;
    sf::Sprite listSprite;
    sf::Font font;
};

#endif // ICON_HPP
