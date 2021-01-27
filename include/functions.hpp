#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "task.hpp"
#include <iostream>
#include <string>
#include <vector>

std::string DrawWindow(); // draw a window if user press delete icon
void WindowS();     // draw a window if tasks are more than 9
std::istream &operator>>(std::istream &input, Task &p);
std::ostream &operator<<(std::ostream &output, const std::vector<Task> &p);

#endif // FUNCTIONS_HPP