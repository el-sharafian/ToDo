#include <iostream>
#include "../include/task.hpp"
//#include "../include/table.hpp"
#include <random>
#include <ctime>

using namespace std;

Task::Task()
{
}
Task::Task(string imgDirectory)
{
    string iconName = imgDirectory + "/favorite.png";
    // if (!favoriteTexture.loadFromFile(iconName))
    // {
    //     // error...
    // }
    // favoriteSprite.setTexture(favoriteTexture);
    // favoriteSprite.setPosition(sf::Vector2f(0, 200));
    set.setTexture(favoriteSprite, iconName, favoriteTexture, 0, 200);

    iconName = imgDirectory + "/notFavorite.png";
    // if (!notFavoriteTexture.loadFromFile(iconName))
    // {
    //     // error...
    // }
    // notFavoriteSprite.setTexture(notFavoriteTexture);
    // notFavoriteSprite.setPosition(sf::Vector2f(0, 200));
    set.setTexture(notFavoriteSprite, iconName, notFavoriteTexture, 0, 200);
}
void Task::setPriority(unsigned int p)
{
    if (p > 0 && p < 6)
    {
        priority = p;
    }
    else
    {
        throw invalid_argument("The input was not valid!!");
    }
}
void Task::setTask(string t)
{
    TaskName = t;
    // return TaskName;
}
string Task::getTask()
{
    return TaskName;
}
int Task::getPriority()
{
    return priority;
}
void Task::setCheck(bool c)
{
    check = c;
}
bool Task::getCheck()
{
    return check;
}
void Task::favorite(sf::RenderWindow &window)
{
    window.draw(favoriteSprite);
}
void Task::notFavorite(sf::RenderWindow &window)
{
    window.draw(notFavoriteSprite);
}