#include <iostream>
#include <string>
#include "../include/task.hpp"
//#include "../include/table.hpp"
#include <random>
#include <ctime>

using namespace std;

Task::Task()
{
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
int Task::getPriority()
{
    return priority;
}
void Task::setFavorite(char f)
{
    if (f == 'y' || f == 'n')
        favorite = f;
    else
    {
        throw invalid_argument("The input was not valid!!");
    }
}
char Task::getFavorite()
{
    return favorite;
}

void Task::setCheck(bool c)
{
    check = c;
}
bool Task::getCheck()
{
    return check;
}
