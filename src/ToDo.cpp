#include "todo.hpp"
#include "set.hpp"
#include "task.hpp"
#include <iostream>
using namespace std;

ToDo::ToDo()
{
    Set set;
    window = new sf::RenderWindow(sf::VideoMode(800, 500), "ToDO");
    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf");

    text.setFont(font);
    set.setText(text, 300, 0, "Make a ToDo list");

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
    fstream Tasks("../Tasks.txt", ios::app | ios::in);
    if (!Tasks.is_open())
    {
        exit(EXIT_FAILURE);
    }
    //string a;
    Task a;
    Tasks >> a;
    //getline(Tasks, a);
    bool showTasks = true;
    if (Tasks.tellp() == 0)
    {
        showTasks = false;
    }
    else
    {
        Tasks.seekg(ios::beg);
        cout << "++++++++++" << a << endl;
        // getline(Tasks, a);
    }
    /* string c = a.getTask();
    int index = c.size();
    c = c[index - 1];*/

    Task t;
    t.SetTask(a.GetName());

    while (window->isOpen())
    {

        sf::Text TaskText;
        Set set;
        set.setText(TaskText, 100, 200, a.GetName());
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
                icon->iconEvents(evnt, *window);
            }
            if (text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
            {
                text.setFillColor(sf::Color(20, 150, 150));
            }
            else
            {
                text.setFillColor(sf::Color::Black);
            }
        }
        window->clear();
        window->draw(sprite);
        icon->DrawIcons(*window, icon->add(), icon->edit());
        window->draw(text);
        window->draw(TaskText);
        t.showTask(*window, t);
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