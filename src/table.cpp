#include "../include/task.hpp"
#include "../include/table.hpp"
// #include "../include/start.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void addT(vector<Task> &tasks, string taskN, unsigned int Pi, char fav)
{
  Task t;

  // t.setTask(taskN);
  try
  {
    t.setPriority(Pi);
  }
  catch (invalid_argument &e)
  {
    std::cerr << e.what() << '\n';
  }

  try
  {
    t.setFavorite(fav);
  }
  catch (invalid_argument &e)
  {
    std::cerr << e.what() << '\n';
  }

  tasks.push_back(t);
}