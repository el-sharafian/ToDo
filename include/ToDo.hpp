#ifndef TODO_HPP
#define TODO_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "icon.hpp"
#include "AddButton.hpp"

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
    sf::Text text;
    sf::Sprite sprite;
    sf::Texture backgroundTexture;
    std::string s;
};

#endif // TODO_HPP