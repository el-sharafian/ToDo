#include "../include/icon.hpp"
#include "../include/task.hpp"
#include "../include/table.hpp"
#include "../include/ToDo.hpp"
#include "addButton.hpp"
#include "Button.hpp"
#include "editButton.hpp"
#include "deleteButton.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/System/String.hpp>
#include <locale>
#include <vector>

#define Sp 20
#define Enter_key 13

using namespace std;

Icon::Icon(std::string imgDirectory)
{
    font.loadFromFile("../assets/icons/font.ttf");

    std::string iconName = imgDirectory + "/add.png";
    if (!addTexture.loadFromFile(iconName))
    {
        // error...
    }
    addSprite.setTexture(addTexture);
    editSprite.setPosition(sf::Vector2f(10, 0));

    iconName = imgDirectory + "/edit5.png";
    if (!editTexture.loadFromFile(iconName))
    {
        //error
    }
    editSprite.setTexture(editTexture);
    editSprite.setPosition(sf::Vector2f(10, 125));

    iconName = imgDirectory + "/bin.png";
    if (!binTexture.loadFromFile(iconName))
    {
        // error...
    }
    binSprite.setTexture(binTexture);
    binSprite.setPosition(sf::Vector2f(10, 400));
}
ostream &operator<<(ostream &out, const Task &p)
{
    out << p.TaskName << "\t" << p.priority << "\t" << p.favorite << endl;
    // output << p.age;
    return out;
}
void testOpen(std::ofstream &out)
{
    if (!out)
    {
        cout << "can not open the file !!!" << endl;
        // exit(EXIT_FAILURE);
    }
}
void Icon::iconEvents(sf::Event evnt, sf::RenderWindow &window)
{
    sf::Text taskNameText;
    std::string taskName;
    taskNameText.setFont(font);
    taskNameText.setPosition(sf::Vector2f(5, 25));
    taskNameText.setFillColor(sf::Color(20, 100, 100));

    if (evnt.type == sf::Event::MouseButtonPressed)
    {
        if (evnt.mouseButton.button == sf::Mouse::Left)
        {

            if (addSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                // AddButton addbutton;
                // displayWindow(addbutton);

                std::string addTask = "Enter name of your task \n";
                sf::Text addTaskText;
                addTaskText.setFont(font);
                addTaskText.setPosition(sf::Vector2f(140, 0));
                addTaskText.setString(addTask);
                addTaskText.setFillColor(sf::Color(20, 100, 100));

                std::string limitTaskName = "task name is too long \n";
                sf::Text limitTaskNameText;
                limitTaskNameText.setFont(font);
                limitTaskNameText.setPosition(sf::Vector2f(200, 200));
                limitTaskNameText.setString(limitTaskName);
                limitTaskNameText.setFillColor(sf::Color::Red);

                sf::RenderWindow win(sf::VideoMode(600, 400), "add a task name", sf::Style::Close);
                sf::Texture addWindowTexture;
                if (addWindowTexture.loadFromFile("../assets/images/ax5.jpg"))
                {
                    // error ...
                }
                sf::Sprite addWindowSprite;
                addWindowSprite.setTexture(addWindowTexture);

                std::vector<Task> tasks;

                while (win.isOpen())
                {
                    bool checklimit = false;
                    sf::Event evn;
                    if (win.pollEvent(evn))
                    {

                        if (evn.type == sf::Event::Closed)
                        {
                            win.close();
                        }
                        if (evn.type == sf::Event::TextEntered)
                        {
                            if (evn.text.unicode == Enter_key)
                            {
                                win.close();
                            }
                            else if (evn.text.unicode < 128)
                            {
                                if (taskName.size() < 30)
                                {
                                    taskName += static_cast<char>(evn.text.unicode);
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
                            taskNameText.setString(taskName);

                            addT(tasks, taskName, m, c);

                            // for (const auto &e : v)
                            //     output << e;
                            // cin.ignore();
                        }

                        taskNameText.setString(taskName);
                        win.clear();
                        if (checklimit)
                        {
                            win.draw(limitTaskNameText);
                        }
                        win.draw(addWindowSprite);
                        win.draw(addTaskText);
                        win.draw(taskNameText);
                        win.display();
                    }
                }
                std::ofstream output("../src/output.txt", std::ios::app);
                testOpen(output);
                output << taskName << endl;
            }
            else if (binSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                DeleteButton deleteButton;
                WindowDisplay(deleteButton);
            }
            else if (editSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                EditButton editButton;
                WindowDisplay(editButton);
            }
        }
    }
}
void Icon::edit(sf::RenderWindow &window)
{
    window.draw(editSprite);
}
void Icon::add(sf::RenderWindow &window)
{
    window.draw(addSprite);
}
void Icon::bin(sf::RenderWindow &window)
{
    window.draw(binSprite);
}