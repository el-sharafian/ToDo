#include "deleteButton.hpp"
#include <string>

DeleteButton::DeleteButton()
{
    std::string iconName = "../assets/icons/bin.png";
    set.setTexture(DeletedSprite, iconName, DeletedTexture, 715, 50);
}
sf::Sprite DeleteButton::GetDeletedSprite()
{
    return DeletedSprite;
}
void DeleteButton::SetIsDeleted(int check)
{
    isDeleted = check;
}
int DeleteButton::GetIsDeleted(void)
{
    return isDeleted;
}