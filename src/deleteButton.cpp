#include "deleteButton.hpp"
#include <string>

DeleteButton::DeleteButton()
{
    std::string iconName = "../assets/icons/bin.png";
    set.SetTexture(Sprite, iconName, Texture, 715, 50);
    iconName = "../assets/icons/t1.png";
}
sf::Sprite DeleteButton::GetSprite()
{
    return Sprite;
}
void DeleteButton::SetIsDeleted(int check)
{
    isDeleted = check;
}
int DeleteButton::GetIsDeleted(void)
{
    return isDeleted;
}