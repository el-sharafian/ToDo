#include "deleteButton.hpp"
#include <string>

DeleteButton::DeleteButton()
{
    std::string iconName = "../assets/icons/bin.png";
    set.setTexture(DeletedSprite, iconName, DeletedTexture, 715, 50);
}
void DeleteButton::setIsDeleted(int check)
{
    isDeleted = check;
}
int DeleteButton::getIsDeleted(void)
{
    return isDeleted;
}