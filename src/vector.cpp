#include <iostream>
#include "vector.hpp"

using namespace std;

Vector::Vector()
{
    vector<Task> tasks;
}
Task t;
//tasks.push_back(t);
void Vector::Push(string taskN)
{

    t.SetTask(taskN);

    tasks.push_back(t);
}
string Vector::Get()
{
    // Task t;
    std::string b = t.GetTask();
    tasks.push_back(t);
    std::cout << b << std::endl;

    return b;
}
vector<Task> *Vector::Assign()
{
    // vector<Task>& tasks;
    //cout << &tasks << endl;
    vector<Task> *temp = &tasks;
    // cout << temp << endl;
    return temp;
}