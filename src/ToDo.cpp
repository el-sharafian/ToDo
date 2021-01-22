#include "todo.hpp"
#include "set.hpp"
#include "task.hpp"
#include <iostream>
using namespace std;

bool DrawWindow()       //draw a window if user press delete icon
{
    bool check;
    sf::RenderWindow window;
    window.create(sf::VideoMode(300, 150), "delete", sf::Style::None);
    window.setPosition(sf::Vector2i(500, 500));
    Set set;
    sf::Sprite Sprite;
    sf::Texture Texture;
    sf::Sprite YesSprite;
    sf::Texture YesTexture;
    sf::Sprite NoSprite;
    sf::Texture NoTexture;
    sf::Text text;

    set.SetText(text, 0,0,"Do you want to delete this task?");
    std::string iconName = "../assets/icons/t1.png";
    set.SetTexture(YesSprite, iconName, YesTexture, 80, 50);
    iconName = "../assets/icons/cross.png";
    set.SetTexture(NoSprite, iconName, NoTexture, 150, 50);
    iconName = "../assets/images/back.png";
    Texture.loadFromFile(iconName);
    Sprite.setTexture(Texture);
    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
            if (YesSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                check = true;
                window.close();
            }
            if (NoSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                window.close();
                check = false;
            }
            window.clear();
            window.draw(Sprite);
            window.draw(YesSprite);
            window.draw(NoSprite);
            window.draw(text);
            window.display();
        }
    }
    return check;
}

ToDo::ToDo()
{
    Set set;
    window = new sf::RenderWindow(sf::VideoMode(800, 500), "ToDO");
    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf");

    text.setFont(font);
    set.SetText(text, 300, 0, "Make a ToDo list");

    if (!backgrounfTexture.loadFromFile("../assets/images/ax5.jpg"))
    {
        // error...
    }
    sprite.setTexture(backgrounfTexture);
}
istream &operator>>(istream &input, Task &p)
{
    input >> p.TaskName;
    return input;
}
void ToDo::Loop()
{
    int CheckIsDne = 0;
    bool CheckFav = false;
    bool CheckDelete = false;
    FavoriteButton fav;
    IsDoneButton IsDne;
    DeleteButton dlt;
    fstream Tasks("../Tasks.txt", ios::app | ios::in);
    if (!Tasks.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Task a;
    vector<Task> tasks;
    vector<sf::Text> TaskName;
    sf::Text Task1;

    while (!Tasks.fail() && !Tasks.eof())
    {
        Tasks >> a;
        tasks.push_back(a);
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
        cout << tasks[i].GetName() << endl;
    }

    bool showTasks = true;
    if (Tasks.tellp() == 0)
    {
        showTasks = false;
    }
    else
    {
        Tasks.seekg(ios::beg);
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
        Task1.setFont(font);
        Task1.setString(tasks[i].GetName());
        TaskName.push_back(Task1);
    }
    Task tsk;
    tsk.SetTask(a.GetName());

    while (window->isOpen())
    {
        sf::Text TaskText;
        Set set;
        set.SetText(TaskText, 100, 200, a.GetName());
        TaskText.setFont(font);
        sf::Event evnt;
        while (window->pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window->close();
            }
            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                icon->IconEvents(evnt, *window);
            }
            if (text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
            {
                text.setFillColor(sf::Color(20, 150, 150));
            }
            else
            {
                text.setFillColor(sf::Color::Black);
            }
            if (dlt.GetSprite().getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                CheckDelete = DrawWindow();
            }
            else if (IsDne.GetNotDoneSprite().getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                CheckIsDne = 1;
            }
            if (fav.GetNotFavoriteSprite().getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                CheckFav = true;
            }
        }
        for (size_t i = 0; i < tasks.size(); i++)
        {
            TaskName[i].setFillColor(sf::Color::Red);
            TaskName[i].setPosition(sf::Vector2f(50, (i * 50)));
        }
        window->clear();
        window->draw(sprite);
        icon->DrawIcons(*window, icon->Add(), icon->Edit());
        window->draw(text);
        for (size_t i = 0; i < tasks.size(); i++)
        {
            window->draw(TaskName[i]);
        }
        if (!CheckDelete)
        {
            if (!CheckFav)
            {
                window->draw(tsk.favoriteButton.GetNotFavoriteSprite());
            }
            else
            {
                window->draw(tsk.favoriteButton.GetFavoriteSprite());
            }
            tsk.ShowTask(*window, tsk);
            if (CheckIsDne)
            {
                window->draw(IsDne.GetIsDoneSprite());
            }
        }
        window->display();
    }
}
ToDo::~ToDo()
{
    delete window;
    delete icon;
}
Task ToDo::SetTask(string taskN)
{
    int index = taskN.size();
    Task taskV;
    char settask = taskN[index - 1];

    settask = taskN[index - 2];

    settask = taskN[index - 3];

    taskN = taskN.erase(index - 3);

    taskN.erase(taskN.size() - 3);

    return taskV;
}