#ifndef ISDONEBUTTON_HPP
#define ISDONEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class IsDoneButton : public Button      // show if a task is complete
{
public:
    IsDoneButton();
    void SetIsDone(int);
    int GetIsDone(void);
    sf::Sprite GetIsDoneSprite();
    sf::Sprite GetNotDoneSprite();

private:
    int IsDone = 0;
    sf::Sprite NotDoneSprite;
    sf::Texture NotDoneTexture;
};

#endif // ISDONEBUTTON_HPP