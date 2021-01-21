#ifndef FAVORITEBUTTON_HPP
#define FAVORITEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class FavoriteButton //: public Button
{
    // friend void WindowDisplay(Button &);
public:
    FavoriteButton();
    void SetIsFavorite(int);
    int GetIsFavorite(void);
    sf::Sprite GetNotFavoriteSprite();
    sf::Sprite GetFavoriteSprite();
private:
    Set set;
    int IsFavorite = 0;
    sf::Sprite NotFavoriteSprite;
    sf::Sprite FavoriteSprite;
    sf::Texture NotFavoriteTexture;
    sf::Texture FavoriteTexture;
};

#endif // FAVORITEBUTTON_HPP