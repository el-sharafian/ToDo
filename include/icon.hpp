#ifndef ICON_HPP
#define ICON_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "task.hpp"
#include "set.hpp"
#include "editButton.hpp"
#include "addButton.hpp"

class Icon // drawing icons
{
public:
    Icon(std::string);
    sf::Sprite Edit();
    sf::Sprite Add();
    bool IconEvents(sf::Event, sf::RenderWindow &, std::vector<Task> &);
    void DrawIcons(sf::RenderWindow &window, sf::Sprite, sf::Sprite);

private:
    sf::Texture AddTexture;
    sf::Sprite AddSprite;
    sf::Texture EditTexture;
    sf::Sprite EditSprite;
    sf::Font font;
    Set set; //sets Texts and Sprites
};

#endif // ICON_HPP