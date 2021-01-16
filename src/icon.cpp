#include "icon.hpp"
#include "table.hpp"
#include "ToDo.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

#define Sp 20
#define BS_key 8
#define Enter_key 13

using namespace std;

Icon::Icon(std::string imgDirectory)    
{
    font.loadFromFile("../assets/icons/f1.ttf"); //**********

    std::string iconName = imgDirectory + "/add.png";
    set.setTexture(addSprite, iconName, addTexture, 10, 0);

    iconName = imgDirectory + "/edit5.png";
    set.setTexture(editSprite, iconName, editTexture, 10, 125);

    iconName = imgDirectory + "/bin.png";
    set.setTexture(binSprite, iconName, binTexture, 10, 400);
}
ostream &operator<<(ostream &out, const Task &p)
{
    out << p.TaskName << "\t" << p.priority << endl;
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
                set.setText(addTaskText, 140, 0, addTask);

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
                            if (evn.text.unicode == BS_key)
                            {
                                taskName.erase(taskName.size() - 1);
                            }
                            else if (evn.text.unicode < 128)
                            {
                                if (taskName.size() < 30)
                                {
                                    taskName += static_cast<char>(evn.text.unicode);
                                }
                            }
                            taskNameText.setString(taskName);

                            addT(tasks, taskName);

                            // for (const auto &e : v)
                            //     output << e;
                            // cin.ignore();
                        }

                        taskNameText.setString(taskName);
                        win.clear();
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
sf::Sprite Icon::edit()
{
    return editSprite;
}
sf::Sprite Icon::add()
{
    return addSprite;
}
sf::Sprite Icon::bin()
{
    return binSprite;
}
void Icon::DrawIcons(sf::RenderWindow &window, sf::Sprite addSprite, sf::Sprite binSprite, sf::Sprite editSprite)
{
    window.draw(addSprite);
    window.draw(binSprite);
    window.draw(editSprite);
}