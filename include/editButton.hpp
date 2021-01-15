#ifndef EDITBUTTON_HPP
#define EDITBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "task.hpp"
#include "button.hpp"
#include "windowDisplay.hpp"

class EditButton : public Button
{
    friend void WindowDisplay(Button &);

public:
    EditButton();
};

#endif // EDITBUTTON_HPP
