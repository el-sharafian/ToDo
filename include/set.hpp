#ifndef SET_HPP
#define SET_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Set   // sets Texts and Sprites
{
public:
    Set();
    ~Set();
    void setText(sf::Text &, int, int, std::string);        // set Text's position and color and string
    void setTexture(sf::Sprite &, std::string, sf::Texture&, int, int);     // set Sprite's position and Texture

private:
    sf::Font font;
};

#endif // SET_HPP