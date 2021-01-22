#include "favoriteButton.hpp"
#include <string>

FavoriteButton::FavoriteButton()
{
    std::string iconName = "../assets/icons/favorite.png";
    set.setTexture(FavoriteSprite, iconName, FavoriteTexture, 670, 50);

    iconName = "../assets/icons/notFavorite.png";
    set.setTexture(NotFavoriteSprite, iconName, NotFavoriteTexture, 670, 50);
}
sf::Sprite FavoriteButton::GetFavoriteSprite()
{
    return FavoriteSprite;
}
sf::Sprite FavoriteButton::GetNotFavoriteSprite()
{
    return NotFavoriteSprite;
}
void FavoriteButton::SetIsFavorite(int check)
{
    IsFavorite = check;
}
int FavoriteButton::GetIsFavorite(void)
{
    return IsFavorite;
}