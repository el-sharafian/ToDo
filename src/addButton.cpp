#include "addButton.hpp"
#include "set.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

#define Enter_key 13
#define BACKSPACE_key 8

using namespace std;

AddButton::AddButton() //  AddButton constructor
{
    Win.create(sf::VideoMode(600, 200), "add a task name", sf::Style::Close); // creating second window to add tasks
    Win.setPosition(sf::Vector2i(350, 500));                                  // set position of window

    font.loadFromFile("../assets/icons/f1.ttf"); // loading font

    Texture.loadFromFile("../assets/images/background2.png"); // set the background for second window
    Sprite.setTexture(Texture);
    // set 2 texts for window
    TaskNameText.setFont(font);
    set.SetText(TaskNameText, 10, 50, TaskName);
    AddTaskText.setFont(font);
    set.SetText(AddTaskText, 140, 0, addTask);
    AddTaskText.setFillColor(sf::Color(253, 173, 173));

    WindowText.setFont(font);
    set.SetText(WindowText, 100, 170, WindowString);
    WindowText.setCharacterSize(20);
}
bool AddButton::DisplayWindow(AddButton &addButton, vector<Task> &task)
{
    Task temp(addButton.TaskName); // declare an object of class Task to set taskName

    while (addButton.Win.isOpen())
    {
        sf::Event evn;
        if (addButton.Win.pollEvent(evn))
        {
            if (evn.type == sf::Event::Closed) //  close the window
            {
                addButton.Win.close();
            }
            else if (evn.type == sf::Event::TextEntered)
            {
                if (evn.text.unicode == BACKSPACE_key) //  delete the last character from string if BACKSPACE is pressed
                {
                    addButton.TaskName.erase(TaskName.size() - 1);
                }
                else if (evn.text.unicode < 128)
                {
                    if (addButton.TaskName.size() < 35)
                    {
                        addButton.TaskName += static_cast<char>(evn.text.unicode); // adding the entered text to string
                    }
                }
            }
            addButton.TaskNameText.setString(addButton.TaskName); // set the string that user entered
            addButton.Win.clear();
            addButton.Win.draw(addButton.Sprite);       // draw background
            addButton.Win.draw(addButton.AddTaskText);  // draw the first text that sets before
            addButton.Win.draw(addButton.TaskNameText); // draw the text that user entered
            addButton.Win.draw(addButton.WindowText);   // draw the second text that sets befor
            addButton.Win.display();
        }
    }
    addButton.TaskName = addButton.TaskName + "000";
    temp.SetTask(addButton.TaskName); // set the taskName for object
    if (task.size() < 9)
    {
        if (4 < addButton.TaskName.size()) //  checks if addButton.TaskName is empty
        {
            task.push_back(temp); // add object to the vector
            return false;
        }
        return false;
    }
    return true;
}