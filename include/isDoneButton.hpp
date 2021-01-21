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
    sf::Sprite GetIsDoneSprite();
    sf::Sprite GetNotDoneSprite();

private:
    Set set;
    sf::Sprite IsDoneSprite;
    sf::Sprite NotDoneSprite;
    int isDone = 0;
    sf::Texture IsDoneTexture;
    sf::Texture NotDoneTexture;
};

#endif // ISDONEBUTTON_HPP