#ifndef DELETEBUTTON_HPP
#define DELETEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

// icon for deleting a task

class DeleteButton : public Button
{
    friend void WindowDisplay(Button &);
    
public:
    DeleteButton();
    void SetIsDeleted(int);
    int GetIsDeleted(void);
    sf::Sprite GetSprite();

private:
    int isDeleted = 0;
};

#endif // DELETEBUTTON_HPP