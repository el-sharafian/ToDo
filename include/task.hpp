#ifndef TASK_H
#define TASK_H

#include "set.hpp"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Task
{
    friend std::istream &operator>>(std::istream &input, Task &p);
    friend std::ostream &operator<<(std::ostream &output, const Task &p);
    // friend void add(std::vector<task> &,std::string);

public:
    Task(std::string);
    void setPriority(unsigned int);
    void setFavorite(char);
    void setCheck(bool);
    int getPriority(void);
    char getFavorite(void);
    bool getCheck(void);
    std::string TaskName;
    void favorite(sf::RenderWindow &);
    void notFavorite(sf::RenderWindow &);

private:
    // std::string TaskName;
    unsigned int priority;
    bool check = false;
    sf::Texture favoriteTexture;
    sf::Sprite favoriteSprite;
    sf::Texture notFavoriteTexture;
    sf::Sprite notFavoriteSprite;
    Set set;    // sets Texts and Sprites
};

#endif