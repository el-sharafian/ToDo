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
    if(!font.loadFromFile("../assets/icons/f1.ttf"))
    {
        exit(EXIT_FAILURE);
    }
}
void Task::showTask(sf::RenderWindow &window, Task task)
{
    sf::Text TName;
    TName.setFont(font);
    set.setText(TName, 20,50, task.GetName());
    TName.setString("aaaaa");
    TName.setCharacterSize(50);
    TName.setFillColor(sf::Color::Red);
    if (!task.deleteButton.getIsDeleted())
    {
        if (!task.favoriteButton.getIsFavorite())
        {
            window.draw(task.favoriteButton.FavoriteSprite);
        }
        else
        {
            window.draw(task.favoriteButton.notFavoriteSprite);
        }
        window.draw(TName);
        window.draw(task.deleteButton.DeletedSprite);
        window.draw(task.isDoneButton.IsDoneSprite);
    }
}

void Task::SetTask(string t, int fav, int deleted, int done)
{
    TaskName = t;
    favoriteButton.setIsFavorite(fav);
    deleteButton.setIsDeleted(deleted);
    isDoneButton.setIsDone(done);
}
string Task::getTask()
{
    return TaskName;
}
std::string Task::GetName()
{
    return TaskName;
}
