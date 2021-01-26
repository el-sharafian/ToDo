#include "addButton.hpp"
#include "set.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <cstdlib>

#define Enter_key 13
#define BACKSPACE_key 8

using namespace std;

AddButton::AddButton()
{
    Win.create(sf::VideoMode(600, 200), "add a task name", sf::Style::Close);
    if (Texture.loadFromFile("../assets/images/background2.png"))
    {
        // error ...
    }
    Sprite.setTexture(Texture);

    Fontt.loadFromFile("../assets/icons/f1.ttf");

    TaskNameText.setFont(Fontt);
    set.SetText(TaskNameText, 10, 50, TaskName);
    AddTaskText.setFont(Fontt);
    set.SetText(AddTaskText, 140, 0, addTask);
    AddTaskText.setFillColor(sf::Color(253, 173, 173));
}
void AddButton::DisplayWindow(AddButton &addButton, vector <Task> & task)
{
    sf::Text txt;
    txt.setFont(Fontt);
    txt.setPosition(sf::Vector2f(400, 300));
    txt.setFillColor(sf::Color::Black);

    Task t(addButton.TaskName);

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
                if (evn.text.unicode == BACKSPACE_key)
                {
                    addButton.TaskName.erase(TaskName.size() - 1);
                }
                else if (evn.text.unicode < 128)
                {
                    if (addButton.TaskName.size() < 35)
                    {
                        addButton.TaskName += static_cast<char>(evn.text.unicode);
                    }
                }
            }
            addButton.TaskNameText.setString(addButton.TaskName);
            addButton.Win.clear();
            addButton.Win.draw(addButton.Sprite);
            addButton.Win.draw(addButton.AddTaskText);
            addButton.Win.draw(addButton.TaskNameText);
            addButton.Win.draw(txt);
            addButton.Win.display();
        }
    }
    addButton.TaskName = addButton.TaskName + "000";
    t.SetTask(addButton.TaskName);
    task.push_back(t);
}