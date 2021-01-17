#ifndef FAVORITEBUTTON_HPP
#define FAVORITEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class FavoriteButton : public Button
{
    // friend void WindowDisplay(Button &);
public:
    FavoriteButton();
    void setIsFavorite(int);
    int getIsFavorite(void);

private:
    int isFavorite = 0;
    sf::Texture notFavoriteTexture;
    sf::Sprite notFavoriteSprite;
};

#endif // FAVORITEBUTTON_HPP