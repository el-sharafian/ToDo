#include <iostream>
#include "../include/task.hpp"
#include <random>
#include <ctime>

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
void Task::SetTask(string t) // set the task name
{
    TaskName = t;
}
std::string Task::GetName() // function for get task name
{
    return TaskName;
}