#ifndef TASK_H
#define TASK_H

#include "set.hpp"
#include "../include/deleteButton.hpp"
#include "favoriteButton.hpp"
#include "isDoneButton.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Task
{
    friend std::istream &operator>>(std::istream &input, Task &p);
    friend std::ostream &operator<<(std::ostream &output, const Task &p);
    // friend void add(std::vector<task> &,std::string);
    friend class File;

public:
    Task();
    Task(std::string);
    void showTask(sf::RenderWindow &, Task);
    void SetTask(std::string);
    std::string GetName();
    std::string getTask(void);

private:
    sf::Font font;
    std::string TaskName;
    FavoriteButton favoriteButton;
    DeleteButton deleteButton;
    IsDoneButton isDoneButton;
    bool check = false;
    Set set; // sets Texts and Sprites
};

#endif