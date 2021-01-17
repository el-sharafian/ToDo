#include "deleteButton.hpp"
#include <string>

DeleteButton::DeleteButton()
{
    std::string iconName = "../assets/icons/bin.png";
    set.setTexture(Sprite, iconName, Texture, 10, 400);
}
void DeleteButton::setIsDeleted(int check)
{
    isDeleted = check;
}
int DeleteButton::getIsDeleted(void)
{
    return isDeleted;
}