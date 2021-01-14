#include "addButton.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>

#define Enter_key 13

AddButton::AddButton()
{
    TaskNameText.setFont(font);
    
    addTaskText.setFont(font);
    addTaskText.setPosition(sf::Vector2f(140, 0));
    addTaskText.setString(addTask);
    addTaskText.setFillColor(sf::Color(20, 100, 100));

    limitTaskNameText.setFont(font);
    limitTaskNameText.setPosition(sf::Vector2f(200, 200));
    limitTaskNameText.setString(limitTaskName);
    limitTaskNameText.setFillColor(sf::Color::Red);

    win.create(sf::VideoMode(600, 400), "add a task name");
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
        bool checklimit = false;
        sf::Event evn;
        if (addButton.win.pollEvent(evn))
        {
            if (evn.type == sf::Event::Closed)
            {
                addButton.win.close();
            }
            if (evn.type == sf::Event::TextEntered)
            {
                if (evn.text.unicode == Enter_key)
                {
                    addButton.win.close();
                }
                else if (evn.text.unicode < 128)
                {
                    if (addButton.taskName.size() < 30)
                    {
                        addButton.taskName += static_cast<char>(evn.text.unicode);
                    }
                    else
                    {
                        std::cout << "***************************";
                        checklimit = true;
                    }
                }
                unsigned int m = 5;
                char c = 'y';

                /*t.setTask(b);
                                    t.setPriority(m);
                                    t.setFavorite(c);*/
                // addButton.TaskNameText.setString(taskName);

                // addT(tasks, taskName, m, c);

                // for (const auto &e : v)
                //     output << e;
                // cin.ignore();
            }

            addButton.TaskNameText.setString(addButton.taskName);
            addButton.win.clear();
            if (checklimit)
            {
                addButton.win.draw(addButton.limitTaskNameText);
            }
            addButton.win.draw(addButton.addWindowSprite);
            addButton.win.draw(addButton.addTaskText);
            addButton.win.draw(addButton.TaskNameText);
            addButton.win.display();
        }
    }
    std::ofstream output("../src/output.txt", std::ios::app);
    // testOpen(output);
    output << addButton.taskName << std::endl;
}

