#ifndef FAVORITEBUTTON_HPP
#define FAVORITEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class FavoriteButton //: public Button
{
    // friend void WindowDisplay(Button &);
public:
    FavoriteButton();
    void setIsFavorite(int);
    int getIsFavorite(void);
    sf::Sprite notFavoriteSprite;
    sf::Sprite FavoriteSprite;

private:
    Set set;
    int isFavorite = 0;
    sf::Texture notFavoriteTexture;
    sf::Texture FavoriteTexture;
};

#endif // FAVORITEBUTTON_HPP