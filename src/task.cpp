#include <iostream>
#include "../include/task.hpp"
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
    // favoriteButton.SetIsFavorite(x);
    IsFavorite = x;

    string d = TaskName;
    d = d[index - 2]; //the second int for delete
    stringstream geek1(d);

    // it to the integer x
    int y = 0;
    geek1 >> y;

    // Now the variable x holds the value 12345
    cout << "Value of x : " << y;
    // deleteButton.SetIsDeleted(y);
    IsDeleted = x;

    string dn = TaskName;
    dn = dn[index - 1]; //the third int for isDone
    stringstream geek2(dn);

    // it to the integer x
    int z = 0;
    geek2 >> z;

    // Now the variable x holds the value 12345
    cout << "Value of x : " << z;
    // isDoneButton.SetIsDone(z);
    IsDone = x;
}
string Task::GetTask()
{
    return TaskName;
}
std::string Task::GetName()
{
    return TaskName;
}
