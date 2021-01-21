#ifndef ISDONEBUTTON_HPP
#define ISDONEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class IsDoneButton //: public Button
{
public:
    IsDoneButton();
    void setIsDone(int);
    int getIsDone(void);
    sf::Sprite IsDoneSprite;

private:
Set set;
    int isDone = 0;
    sf::Texture IsDoneTexture;
};

#endif // ISDONEBUTTON_HPP