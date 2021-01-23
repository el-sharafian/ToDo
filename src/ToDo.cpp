#include "todo.hpp"
#include "set.hpp"
#include "task.hpp"
#include <iostream>
using namespace std;

bool DrawWindow() //draw a window if user press delete icon
{
    bool check;
    sf::RenderWindow window;
    window.create(sf::VideoMode(300, 150), "delete", sf::Style::Close);
    // window.setPosition(sf::Vector2i(500, 500));
    Set set;
    sf::Sprite Sprite;
    sf::Texture Texture;
    sf::Sprite YesSprite;
    sf::Texture YesTexture;
    sf::Sprite NoSprite;
    sf::Texture NoTexture;
    sf::Text text;
    string a = "Do you want to delete this task?";
    set.SetText(text, 10, 10, a);
    std::string iconName = "../assets/icons/cross1.png";
    set.SetTexture(YesSprite, iconName, YesTexture, 40, 50);
    iconName = "../assets/icons/cross.png";
    set.SetTexture(NoSprite, iconName, NoTexture, 130, 50);
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
                check = false;
                window.close();
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
    window = new sf::RenderWindow(sf::VideoMode(1100, 735), "ToDO");
    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf");
    font2.loadFromFile("../assets/icons/f1.ttf");

    text.setFont(font);
    set.SetText(text, 420, 0, "Make a ToDo list");

    if (!backgrounfTexture.loadFromFile("../assets/images/background.jpg"))
    {
        // error...
    }
    sprite.setTexture(backgrounfTexture);
}
istream &operator>>(istream &input, Task &p)
{
    getline(input, p.TaskName);
    // input >> p.TaskName;
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
    sf::Texture BinTexture;
    BinTexture.loadFromFile("../assets/icons/bin.png");
    sf::Texture FavoriteTexture;
    FavoriteTexture.loadFromFile("../assets/icons/favorite.png");
    sf::Texture IsDoneTexture;
    IsDoneTexture.loadFromFile("../assets/icons/done.png");

    fstream Tasks("../Tasks.txt", ios::app | ios::in);
    if (!Tasks.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Task a;
    vector<Task> tasks;
    vector<sf::Sprite> BinSprite(50);
    vector<sf::Sprite> FavoriteSprite(50);
    vector<sf::Sprite> IsDoneSprite(50);
    vector<sf::Text> TaskName;
    sf::Text Task1;
    Task tsk;

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
        Task1.setFont(font2);
        Task1.setString(tasks[i].GetName());
        TaskName.push_back(Task1);
    }
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

            for (size_t i = 0; i < tasks.size(); i++)
            {
                if (BinSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                {
                    CheckDelete = DrawWindow();
                }
            }

            //
            // else if (IsDne.GetNotDoneSprite().getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            // {
            //     CheckIsDne = 1;
            // }
            // if (fav.GetNotFavoriteSprite().getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            // {
            //     CheckFav = true;
            // }
        }
        for (size_t i = 0; i < tasks.size(); i++)
        {
            TaskName[i].setFillColor(sf::Color::Black);
            TaskName[i].setPosition(sf::Vector2f(50, (i * 50) + 50));
            TaskName[i].setCharacterSize(30);
            BinSprite[i].setTexture(BinTexture);
            BinSprite[i].setPosition(sf::Vector2f(1050, (i * 50) + 50));
            FavoriteSprite[i].setTexture(FavoriteTexture);
            FavoriteSprite[i].setPosition(sf::Vector2f(1000, (i * 50) + 50));
            IsDoneSprite[i].setTexture(IsDoneTexture);
            IsDoneSprite[i].setPosition(sf::Vector2f(10, (i * 50) + 50));
        }
        window->clear();
        window->draw(sprite);
        icon->DrawIcons(*window, icon->Add(), icon->Edit());
        window->draw(text);
        for (size_t i = 0; i < tasks.size(); i++)
        {
            window->draw(TaskName[i]);
            window->draw(BinSprite[i]);
            window->draw(FavoriteSprite[i]);
            window->draw(IsDoneSprite[i]);
        }
        // if (!CheckDelete)
        // {
        //     if (!CheckFav)
        //     {
        //         window->draw(tsk.favoriteButton.GetNotFavoriteSprite());
        //     }
        //     else
        //     {
        //         window->draw(tsk.favoriteButton.GetFavoriteSprite());
        //     }
        //     tsk.ShowTask(*window, tsk);
        //     if (CheckIsDne)
        //     {
        //         window->draw(IsDne.GetIsDoneSprite());
        //     }
        // }
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