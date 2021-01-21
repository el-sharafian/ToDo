#include <iostream>
#include "vector.hpp"

using namespace std;

Vector::Vector()
{
    vector<Task> tasks;
}
Task t;
//tasks.push_back(t);
void Vector::push(string taskN)
{

    t.SetTask(taskN);

    tasks.push_back(t);
}
string Vector::get()
{
    // Task t;
    std::string b = t.getTask();
    tasks.push_back(t);
    std::cout << b << std::endl;

    return b;
}
vector<Task> *Vector::assign()
{
    // vector<Task>& tasks;
    //cout << &tasks << endl;
    vector<Task> *temp = &tasks;
    // cout << temp << endl;
    return temp;
}