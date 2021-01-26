#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Set.hpp"

class Task
{
    friend std::istream &operator>>(std::istream &input, Task &p);
    friend std::ostream &operator<<(std::ostream &output, const std::vector<Task> &p);
    friend class ToDo;

public:
    Task();
    Task(std::string);
    void SetTask(std::string);
    void Event(sf::RenderWindow &, sf::Event);
    std::string GetName();
    void setFa(std::string);

private:
    int IsFavorite;
    int IsDeleted;
    int IsDone;
    sf::Font font;
    std::string TaskName;
    // bool Check = false;
    Set set; // sets Texts and Sprites
};

#endif