#ifndef DELETEBUTTON_HPP
#define DELETEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class DeleteButton : public Button
{
    // friend void WindowDisplay(Button &);
public:
    DeleteButton();
    void setIsDeleted(int);
    int getIsDeleted(void);

private:
    int isDeleted = 0;
};

#endif // DELETEBUTTON_HPP