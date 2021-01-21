#include "../include/isDoneButton.hpp"
#include <string>

IsDoneButton::IsDoneButton()
{
    std::string iconName = "../assets/icons/tick.png";
    set.setTexture(IsDoneSprite, iconName, IsDoneTexture, 10, 50);
    iconName = "../assets/icons/notDone.png";
    set.setTexture(NotDoneSprite, iconName, NotDoneTexture, 10, 50);
}
sf::Sprite IsDoneButton::GetIsDoneSprite()
{
    return IsDoneSprite;
}
sf::Sprite IsDoneButton::GetNotDoneSprite()
{
    return NotDoneSprite;
}
void IsDoneButton::setIsDone(int check)
{
    isDone = check;
}
int IsDoneButton::getIsDone(void)
{
    return isDone;
}