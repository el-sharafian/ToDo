#ifndef ISDONEBUTTON_HPP
#define ISDONEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class IsDoneButton : public Button
{
public:
    IsDoneButton();
    void setIsDone(int);
    int getIsDone(void);

private:
    int isDone = 0;
};

#endif // ISDONEBUTTON_HPP