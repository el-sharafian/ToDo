#ifndef TODO_HPP
#define TODO_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "icon.hpp"

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
    sf::Text text;
    sf::Sprite sprite;
    sf::Texture backgrounfTexture;
    std::string s = "This is text that you type: ";
    sf::Text t;
};

#endif // TODO_HPP
