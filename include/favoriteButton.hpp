#ifndef FAVORITEBUTTON_HPP
#define FAVORITEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class FavoriteButton : public Button    // set a task as favorite
{
public:
    FavoriteButton();
    void SetIsFavorite(int);    // sets IsFavorite variable
    int GetIsFavorite(void);       // return IsFavorite variable
    sf::Sprite GetNotFavoriteSprite();
    sf::Sprite GetFavoriteSprite();
    
private:
    int IsFavorite = 0;
    sf::Sprite NotFavoriteSprite;
    sf::Texture NotFavoriteTexture;
};

#endif // FAVORITEBUTTON_HPP