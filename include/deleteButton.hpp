#ifndef DELETEBUTTON_HPP
#define DELETEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class DeleteButton //: public Button
{
    friend void WindowDisplay(Button &);
public:
    DeleteButton();
    void SetIsDeleted(int);
    int GetIsDeleted(void);
    sf::Sprite GetDeletedSprite();

private:
    Set set;
    int isDeleted = 0;
    sf::Sprite DeletedSprite;
    sf::Texture DeletedTexture;
};

#endif // DELETEBUTTON_HPP