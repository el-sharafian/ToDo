#include "icon.hpp"
#include <iostream>

#define Enter_key 13

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

    iconName = imgDirectory + "/list.png";
    if (!listTexture.loadFromFile(iconName))
    {
        // error...
    }
    listSprite.setTexture(listTexture);
    listSprite.setPosition(sf::Vector2f(7, 250));

    iconName = imgDirectory + "/bin.png";
    if (!binTexture.loadFromFile(iconName))
    {
        // error...
    }
    binSprite.setTexture(binTexture);
    binSprite.setPosition(sf::Vector2f(10, 400));
}
// void Icon::IconDisplay(sf::RenderWindow &window)
// {
// }
void Icon::iconEvents(sf::Event evnt, sf::RenderWindow &window)
{
    if (evnt.type == sf::Event::MouseButtonPressed)
    {
        if (evnt.mouseButton.button == sf::Mouse::Left)
        {

            if (addSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                std::string taskName = "";
                sf::Text taskNameText;
                taskNameText.setFont(font);
                taskNameText.setPosition(sf::Vector2f(5, 25));
                taskNameText.setFillColor(sf::Color(20, 100, 100));

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

                sf::RenderWindow win(sf::VideoMode(600, 400), "add a task name");
                sf::Texture addWindowTexture;
                if (addWindowTexture.loadFromFile("../assets/images/ax5.jpg"))
                {
                    // error ...
                }
                sf::Sprite addWindowSprite;
                addWindowSprite.setTexture(addWindowTexture);

                while (win.isOpen())
                {
                    bool checklimit = false;
                    sf::Event evn;
                    while (win.pollEvent(evn))
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
                            // t.setString(s);
                            if (evn.text.unicode < 128)
                            {
                                if (taskName.size() < 30)
                                {
                                    taskName += static_cast<char>(evn.text.unicode);
                                }
                                else
                                {
                                    std::cout << "***************************";
                                    std::cout << "***************************";
                                    std::cout << "***************************";
                                    checklimit = true;
                                }
                            }
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
            }
            else if (binSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                std::cout << "bin button" << std::endl;
            }
            else if (listSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                std::cout << "list button" << std::endl;
            }
            else if (editSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                std::cout << "edit button" << std::endl;
            }
        }
    }
}

void Icon::list(sf::RenderWindow &window)
{
    window.draw(listSprite);
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
