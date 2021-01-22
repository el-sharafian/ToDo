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
    Task SetTask(std::string);

private:
    sf::RenderWindow *window;
    Icon *icon;
    sf::Font font;
    sf::Text text;
    sf::Sprite sprite;
    sf::Texture backgrounfTexture;
    std::string s;
};

#endif // TODO_HPP