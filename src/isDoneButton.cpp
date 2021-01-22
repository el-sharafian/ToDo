#include "../include/isDoneButton.hpp"
#include <string>

IsDoneButton::IsDoneButton()
{
    std::string iconName = "../assets/icons/tick.png";
    set.SetTexture(Sprite, iconName, Texture, 10, 50);
    iconName = "../assets/icons/notDone.png";
    set.SetTexture(NotDoneSprite, iconName, NotDoneTexture, 10, 50);
}
sf::Sprite IsDoneButton::GetIsDoneSprite()
{
    return Sprite;
}
sf::Sprite IsDoneButton::GetNotDoneSprite()
{
    return NotDoneSprite;
}
void IsDoneButton::SetIsDone(int check)
{
    IsDone = check;
}
int IsDoneButton::GetIsDone(void)
{
    return IsDone;
}