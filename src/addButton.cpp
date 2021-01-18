#include "addButton.hpp"
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

AddButton::AddButton()
{
    win.create(sf::VideoMode(600, 400), "add a task name");
    if (addWindowTexture.loadFromFile("../assets/images/ax5.jpg"))
    {
        // error ...
    }
    addWindowSprite.setTexture(addWindowTexture);

    fontt.loadFromFile("../assets/icons/f1.ttf");

    TaskNameText.setFont(fontt);
    set.setText(TaskNameText, 10, 50, taskName);
    addTaskText.setFont(fontt);
    set.setText(addTaskText, 140, 0, addTask);
}

void AddButton::displayWindow(AddButton &addButton)
{

    sf::Text txt;
    txt.setFont(fontt);
    txt.setPosition(sf::Vector2f(400, 300));
    txt.setFillColor(sf::Color::Black);

    // std::vector<Task> tasks;
    Vector v;

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
                // if (evn.text.unicode == Enter_key)
                // {
                //     addButton.win.close();
                // }
                if (evn.text.unicode == BACKSPACE_key)
                {
                    addButton.taskName.erase(taskName.size() - 1);
                }
                else if (evn.text.unicode < 128)
                {
                    if (addButton.taskName.size() < 40)
                    {
                        addButton.taskName += static_cast<char>(evn.text.unicode);
                        std::fstream file;
                        std::string s = "both.txt";
                        File fi(file, s);
                        fi.isOpen(file);
                        //Task t;
                        //t.setTask(taskName);
                        //string a = "salam";
                        //v.push(taskName);
                        fi.writeToFile(file, v);
                        std::vector<Task> t;
                        std::vector<Task> *vptr = v.assign();
                        std::vector<Task> *vptr2 = &t;
                        Task tt;
                        tt.setTask(taskName);
                        t.push_back(tt);
                        std::cout << vptr << std::endl;
                        vptr2 = v.assign();
                        std::cout << vptr2 << std::endl;
                        //std::cout<<v.assign()<<std::endl;
                        //t=v.assign();
                        if (evn.text.unicode == Enter_key)
                        {
                            std::string b = fi.readFromFile(file, v);
                            std::cout << b << std::endl;
                            txt.setString(b);
                            //std::cout << v.assign() << std::endl;
                        }
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
            addButton.win.draw(txt);
            addButton.win.display();
        }
    }
    std::cout << addButton.taskName;
    std::ofstream output("../src/output.txt", std::ios::app);
    // testOpen(output);
    output << addButton.taskName << std::endl;
}