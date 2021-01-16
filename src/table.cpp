#include "../include/task.hpp"
#include "../include/table.hpp"
// #include "../include/start.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void addT(vector<Task> &tasks, string taskN)
{
  Task t("../assets/icons");

  // t.setTask(taskN);

  tasks.push_back(t);
}