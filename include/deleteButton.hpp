#ifndef DELETEBUTTON_HPP
#define DELETEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "button.hpp"
#include "windowDisplay.hpp"

class DeleteButton : public Button
{
    friend void WindowDisplay(Button &);

public:
    DeleteButton();
};

#endif // DELETEBUTTON_HPP