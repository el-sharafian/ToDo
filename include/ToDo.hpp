#ifndef TODO_HPP
#define TODO_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "icon.hpp"
#include "AddButton.hpp"

std::string DrawWindow(); //draw a window if user press delete icon

class ToDo
{
public:
    ToDo();
    void Loop();
    ~ToDo();

private:
    sf::RenderWindow *window;
    Icon *icon;
    sf::Font font;
    sf::Font font2;
    sf::Text WindowText;
    sf::Text WindowText2;
    sf::Sprite Sprite;
    sf::Texture BackgroundTexture;
    sf::Texture BinTexture;
    sf::Texture FavoriteTexture;
    sf::Texture NotFavoriteTexture;
    sf::Texture IsDoneTexture;
    sf::Texture NotDoneTexture;
};

#endif // TODO_HPP