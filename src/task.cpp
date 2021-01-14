#include <iostream>
#include <string>
#include "../include/task.hpp"
#include "../include/start.hpp"
//#include "../include/table.hpp"
#include <random>
#include <ctime>

using namespace std;

task::task()
{
    setId();
}

void task::setTask(string t)
{
    TaskN = t;
}
string task::getTask()
{
    return TaskN;
}
void task::setPriority(unsigned int p)
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
int task::getPriority()
{
    return priority;
}
void task::setFavorite(char f)
{
    if (f == 'y' || f == 'n')
        favorite = f;
    else
    {
        throw invalid_argument("The input was not valid!!");
    }
}
char task::getFavorite()
{
    return favorite;
}
void task::setId()
{
    default_random_engine eng(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> myran(1000, 9999);
    id = myran(eng);
}
int task::getId()
{
    return id;
}
void task::setCheck(bool c)
{
    check = c;
}
bool task::getCheck()
{
    return check;
}
