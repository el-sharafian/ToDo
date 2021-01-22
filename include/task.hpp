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
    friend std::ostream &operator<<(std::ostream &output, const std::vector<Task> &p);
    friend class File;

public:
    Task();
    Task(std::string);
    void ShowTask(sf::RenderWindow &, Task);
    void SetTask(std::string);
    void Event(sf::RenderWindow &, sf::Event);
    std::string GetName();
    std::string GetTask(void);
    FavoriteButton favoriteButton;
    DeleteButton deleteButton;
    IsDoneButton isDoneButton;

private:
    sf::Font font;
    std::string TaskName;
    bool Check = false;
    Set set; // sets Texts and Sprites
};

#endif