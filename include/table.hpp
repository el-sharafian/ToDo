#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include <string>
#include "../include/task.hpp"

void addT(std::vector<task> &, std::string, unsigned int, char);
void delet(std::vector<task> &);
void complete(std::vector<task> &);
void edit(std::vector<task> &, unsigned int);
void listTodo(std::vector<task> &);
void listComplete(std::vector<task> &);
int findId(std::vector<task> &, unsigned int);
int findLongest(std::vector<task> &);
void menu(std::vector<task>);
int convert(std::string);

#endif