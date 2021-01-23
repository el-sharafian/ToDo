#include "todo.hpp"
#include "set.hpp"
#include "task.hpp"
#include <iostream>
using namespace std;

bool DrawWindow()   //draw a window if user press delete icon
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
    std::string iconName = "../assets/icons/cross1.png";

    sf::Font font;
    font.loadFromFile("../assets/icons/f1.ttf");
    sf::Text Text;
    string testig = "Delete this task?";
    Text.setString(testig);
    Text.setFont(font);
    Text.setPosition(sf::Vector2f(25, 0));

    set.SetTexture(YesSprite, iconName, YesTexture, 50, 50);
    iconName = "../assets/icons/cross.png";
    set.SetTexture(NoSprite, iconName, NoTexture, 160, 50);

    iconName = "../assets/images/background3.jpg";
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
            window.draw(Text);
            window.display();
        }
    }
    return check;
}
ToDo::ToDo()
{
    Set set;
    window = new sf::RenderWindow(sf::VideoMode(1100, 735), "ToDO", sf::Style::Close);
    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf");
    font2.loadFromFile("../assets/icons/f1.ttf");

    text.setFont(font);
    set.SetText(text, 420, 0, "Make a ToDo list");

    if (!backgroundTexture.loadFromFile("../assets/images/background.jpg"))
    {
        // error...
    }
    sprite.setTexture(backgroundTexture);
}
istream &operator>>(istream &input, Task &p)
{
    getline(input, p.TaskName);
    // input >> p.TaskName;
    return input;
}
void ToDo::Loop()
{
    sf::Texture BinTexture;
    BinTexture.loadFromFile("../assets/icons/bin.png");
    sf::Texture FavoriteTexture;
    FavoriteTexture.loadFromFile("../assets/icons/favorite.png");
    sf::Texture NotFavoriteTexture;
    NotFavoriteTexture.loadFromFile("../assets/icons/notFavorite.png");
    sf::Texture IsDoneTexture;
    IsDoneTexture.loadFromFile("../assets/icons/done.png");
    sf::Texture NotDoneTexture;
    NotDoneTexture.loadFromFile("../assets/icons/notDone.png");

    vector<Task> tasks;
    vector<sf::Sprite> BinSprite(11);
    vector<sf::Sprite> FavoriteSprite(11);
    vector<sf::Sprite> NotFavoriteSprite(11);
    vector<bool> IsFavorite(11);
    vector<bool> IsDeleted(11);
    vector<bool> IsDone(11);
    vector<sf::Sprite> IsDoneSprite(11);
    vector<sf::Sprite> NotDoneSprite(11);
    vector<sf::Text> TaskName;
    sf::Text Task1;
    Task tsk;

    fstream Tasks("../Tasks.txt", ios::app | ios::in);
    if (!Tasks.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Task a;

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
    for (size_t i = 0; i < IsFavorite.size(); i++)
    {
        IsFavorite[i] = false;
        IsDeleted[i] = false;
        IsDone[i] = false;
    }
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
                text.setFillColor(sf::Color::White);
            }
            else
            {
                text.setFillColor(sf::Color::Black);
            }
            for (size_t i = 0; i < tasks.size(); i++)
            {
                if (NotFavoriteSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                {
                    IsFavorite[i] = true;
                }
                else if (BinSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                {
                    IsDeleted[i] = DrawWindow();
                }
                else if (NotDoneSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                {
                    IsDone[i] = true;
                }
            }
        }
        for (size_t i = 0; i < tasks.size(); i++)
        {
            TaskName[i].setFillColor(sf::Color::Black);
            TaskName[i].setPosition(sf::Vector2f(50, (i * 50) + 50));
            TaskName[i].setCharacterSize(30);
            BinSprite[i].setTexture(BinTexture);
            BinSprite[i].setPosition(sf::Vector2f(1040, (i * 50) + 50));
            FavoriteSprite[i].setTexture(FavoriteTexture);
            FavoriteSprite[i].setPosition(sf::Vector2f(1000, (i * 50) + 50));
            NotFavoriteSprite[i].setTexture(NotFavoriteTexture);
            NotFavoriteSprite[i].setPosition(sf::Vector2f(1000, (i * 50) + 50));
            IsDoneSprite[i].setTexture(IsDoneTexture);
            IsDoneSprite[i].setPosition(sf::Vector2f(10, (i * 50) + 50));
            NotDoneSprite[i].setTexture(NotDoneTexture);
            NotDoneSprite[i].setPosition(sf::Vector2f(10, (i * 50) + 50));
        }
        window->clear();
        window->draw(sprite);
        icon->DrawIcons(*window, icon->Add(), icon->Edit());
        window->draw(text);
        for (size_t i = 0; i < tasks.size(); i++)
        {
            if (!IsDeleted[i])
            {
                window->draw(TaskName[i]);
                window->draw(BinSprite[i]);
                if (IsFavorite[i])
                {
                    window->draw(FavoriteSprite[i]);
                }
                else
                {
                    window->draw(NotFavoriteSprite[i]);
                }
                if (IsDone[i])
                {
                    window->draw(IsDoneSprite[i]);
                }
                else
                {
                    window->draw(NotDoneSprite[i]);
                }
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