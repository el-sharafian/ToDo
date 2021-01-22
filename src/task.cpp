#include <iostream>
#include "../include/task.hpp"
//#include "../include/table.hpp"
#include <random>
#include <ctime>
#include <sstream>

using namespace std;

Task::Task()
{
}
Task::Task(string imgDirectory)
{
    if (!font.loadFromFile("../assets/icons/f1.ttf"))
    {
        exit(EXIT_FAILURE);
    }
}
void Task::showTask(sf::RenderWindow &window, Task task)
{
    sf::Text TName;
    TName.setFont(font);
    set.setText(TName, 20, 50, task.GetName());
    //TName.setString("aaaaa");
    TName.setCharacterSize(50);
    TName.setFillColor(sf::Color::Red);
    if (!task.deleteButton.GetIsDeleted())
    {
        window.draw(task.deleteButton.GetDeletedSprite());
        if (!task.isDoneButton.getIsDone())
        {
            window.draw(task.isDoneButton.GetIsDoneSprite());
        }
        else
        {
            window.draw(task.isDoneButton.GetNotDoneSprite());
        }
        window.draw(TName);
    }
}
void Task::Event(sf::RenderWindow &window, sf::Event evnt)
{
    if ((favoriteButton.GetNotFavoriteSprite().getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y))))
    {
        window.draw(favoriteButton.GetFavoriteSprite());
    }
}
void Task::SetTask(string t)
{
    TaskName = t;
    int index = TaskName.size();
    string f = TaskName;
    f = f[index - 3]; //the first int for favorite
    stringstream geek(f);

    // it to the integer x
    int x = 0;
    geek >> x;

    // Now the variable x holds the value 12345
    cout << "Value of x : " << x;
    favoriteButton.SetIsFavorite(x);

    string d = TaskName;
    d = d[index - 2]; //the second int for delete
    stringstream geek1(d);

    // it to the integer x
    int y = 0;
    geek1 >> y;

    // Now the variable x holds the value 12345
    cout << "Value of x : " << y;
    deleteButton.SetIsDeleted(y);

    string dn = TaskName;
    dn = dn[index - 1]; //the third int for isDone
    stringstream geek2(dn);

    // it to the integer x
    int z = 0;
    geek2 >> z;

    // Now the variable x holds the value 12345
    cout << "Value of x : " << z;
    isDoneButton.setIsDone(z);

    //favoriteButton.setIsFavorite(fav);
    // deleteButton.setIsDeleted(deleted);
    // isDoneButton.setIsDone(done);
}
string Task::getTask()
{
    return TaskName;
}
std::string Task::GetName()
{
    return TaskName;
}
