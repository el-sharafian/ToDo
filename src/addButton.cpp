#include "addButton.hpp"
#include "set.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>

#define Enter_key 13
#define BS_key 8

AddButton::AddButton()
{
    TaskNameText.setFont(font);
    addTaskText.setFont(font); //**

    // Set set;
    // set.setText(addTaskText, 140, 0, addTask);
    addTaskText.setPosition(sf::Vector2f(140, 0)); //**
    addTaskText.setString(addTask);
    addTaskText.setFillColor(sf::Color(20, 100, 100));


    win.create(sf::VideoMode(500, 300), "add a task name");
    if (addWindowTexture.loadFromFile("../assets/images/ax5.jpg"))
    {
        // error ...
    }
    addWindowSprite.setTexture(addWindowTexture);
}
void displayWindow(AddButton &addButton)
{
    while (addButton.win.isOpen())
    {
        sf::Event evn;
        if (addButton.win.pollEvent(evn))
        {
            if (evn.type == sf::Event::Closed)
            {
                addButton.win.close();
            }
            else if (evn.type == sf::Event::TextEntered)
            {
                if (evn.text.unicode == Enter_key)
                {
                    addButton.win.close();
                }
                if (evn.text.unicode == BS_key)
                {
                    addButton.win.close();
                }
                else if (evn.text.unicode < 128)
                {
                    if (addButton.taskName.size() < 30)
                    {
                        addButton.taskName += static_cast<char>(evn.text.unicode);
                    }
                }
                // for (const auto &e : v)
                //     output << e;
                // cin.ignore();
            }
            addButton.TaskNameText.setString(addButton.taskName);
            addButton.win.clear();
            addButton.win.draw(addButton.addWindowSprite);
            addButton.win.draw(addButton.addTaskText);
            addButton.win.draw(addButton.TaskNameText);
            addButton.win.display();
        }
    }
    std::cout << addButton.taskName;
    std::ofstream output("../src/output.txt", std::ios::app);
    // testOpen(output);
    output << addButton.taskName << std::endl;
}