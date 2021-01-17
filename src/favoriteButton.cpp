#include "favoriteButton.hpp"
#include <string>

FavoriteButton::FavoriteButton()
{
    std::string iconName = "../assets/icons/favorite.png";
    set.setTexture(Sprite, iconName, Texture, 0, 200);

    iconName = "../assets/icons/notFavorite.png";
    set.setTexture(notFavoriteSprite, iconName, notFavoriteTexture, 0, 200);
}
void FavoriteButton::setIsFavorite(int check)
{
    isFavorite = check;
}
int FavoriteButton::getIsFavorite(void)
{
    return isFavorite;
}