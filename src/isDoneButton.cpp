#include "../include/isDoneButton.hpp"
#include <string>

IsDoneButton::IsDoneButton()
{
    std::string iconName = "../assets/icons/tick.png";
    set.setTexture(IsDoneSprite, iconName, IsDoneTexture, 10, 50);
    // IsDoneTexture.loadFromFile("../assets/icons/tick.png");
    // IsDoneSprite.setTexture(IsDoneTexture);
}
void IsDoneButton::setIsDone(int check)
{
    isDone = check;
}
int IsDoneButton::getIsDone(void)
{
    return isDone;
}