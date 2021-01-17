#include "../include/isDoneButton.hpp"
#include <string>

IsDoneButton::IsDoneButton()
{
    std::string iconName = "../assets/icons/bin.png";
    set.setTexture(Sprite, iconName, Texture, 10, 400);
}
void IsDoneButton::setIsDone(int check)
{
    isDone = check;
}
int IsDoneButton::getIsDone(void)
{
    return isDone;
}