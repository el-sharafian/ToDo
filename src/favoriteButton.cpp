#include "favoriteButton.hpp"
#include <string>

FavoriteButton::FavoriteButton()
{
    std::string iconName = "../assets/icons/favorite.png";
    set.setTexture(FavoriteSprite, iconName, FavoriteTexture, 680, 50);

    iconName = "../assets/icons/notFavorite.png";
    set.setTexture(notFavoriteSprite, iconName, notFavoriteTexture, 680, 50);
}
void FavoriteButton::setIsFavorite(int check)
{
    isFavorite = check;
}
int FavoriteButton::getIsFavorite(void)
{
    return isFavorite;
}