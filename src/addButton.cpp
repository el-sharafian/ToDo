#include "addButton.hpp"
// #include "task.hpp"
#include "set.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include "file.hpp"

#define Enter_key 13
#define BACKSPACE_key 8

using namespace std;

AddButton::AddButton()
{
    Win.create(sf::VideoMode(600, 400), "add a task name");
    if (AddWindowTexture.loadFromFile("../assets/images/ax5.jpg"))
    {
        // error ...
    }
    AddWindowSprite.setTexture(AddWindowTexture);

    Fontt.loadFromFile("../assets/icons/f1.ttf");

    TaskNameText.setFont(Fontt);
    set.setText(TaskNameText, 10, 50, TaskName);
    AddTaskText.setFont(Fontt);
    set.setText(AddTaskText, 140, 0, addTask);
}
ostream &operator<<(ostream &output, const Task &p)
{
    output<<p.TaskName;
    return output;
}

void AddButton::DisplayWindow(AddButton &addButton)
{
    sf::Text txt;
    txt.setFont(Fontt);
    txt.setPosition(sf::Vector2f(400, 300));
    txt.setFillColor(sf::Color::Black);

    Task t;

    ofstream Tasks("../Tasks.txt", ios::app);
    if (!Tasks.is_open())
    {
        exit(EXIT_FAILURE);
    }
    while (addButton.Win.isOpen())
    {
        sf::Event evn;
        if (addButton.Win.pollEvent(evn))
        {
            if (evn.type == sf::Event::Closed)
            {
                addButton.Win.close();
            }
            else if (evn.type == sf::Event::TextEntered)
            {
                if (evn.text.unicode == Enter_key)
                {
                    addButton.Win.close();
                }
                if (evn.text.unicode == BACKSPACE_key)
                {
                    addButton.TaskName.erase(TaskName.size() - 1);
                }
                else if (evn.text.unicode < 128)
                {
                    if (addButton.TaskName.size() < 40)
                    {
                        addButton.TaskName += static_cast<char>(evn.text.unicode);
                    }
                }
            }
            addButton.TaskNameText.setString(addButton.TaskName);
            t.SetTask(addButton.TaskName);
            addButton.Win.clear();
            addButton.Win.draw(addButton.AddWindowSprite);
            addButton.Win.draw(addButton.AddTaskText);
            addButton.Win.draw(addButton.TaskNameText);
            addButton.Win.draw(txt);
            addButton.Win.display();
        }
    }
    cout << addButton.TaskName;
    Tasks << t;
}