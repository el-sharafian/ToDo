#ifndef DELETEBUTTON_HPP
#define DELETEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class DeleteButton //: public Button
{
    friend void WindowDisplay(Button &);
public:
    DeleteButton();
    void setIsDeleted(int);
    int getIsDeleted(void);
    sf::Sprite DeletedSprite;

private:
    Set set;
    int isDeleted = 0;
    sf::Texture DeletedTexture;
};

#endif // DELETEBUTTON_HPP