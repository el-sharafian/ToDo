#include "ToDo.hpp"
#include "Set.hpp"
#include "Task.hpp"
#include <iostream>

using namespace std;

ToDo::ToDo()
{
    Set set;
    window = new sf::RenderWindow(sf::VideoMode(900, 601), "ToDO", sf::Style::Close);
    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf");
    font2.loadFromFile("../assets/icons/f1.ttf");

    Text.setFont(font);
    set.SetText(Text, 320, 0, "Make a ToDo list");

    if (!BackgroundTexture.loadFromFile("../assets/images/back2.jpg"))
    {
        // error...
    }
    Sprite.setTexture(BackgroundTexture);

    BinTexture.loadFromFile("../assets/icons/bin.png");
    FavoriteTexture.loadFromFile("../assets/icons/favorite.png");
    NotFavoriteTexture.loadFromFile("../assets/icons/notFavorite.png");
    IsDoneTexture.loadFromFile("../assets/icons/done.png");
    NotDoneTexture.loadFromFile("../assets/icons/notDone.png");
}
void ToDo::Loop()
{

    sf::Text txt2;
    string s = "Reopen the window to apply changes:)";
    txt2.setString(s);
    txt2.setFont(font2);
    txt2.setPosition(sf::Vector2f(250, 570));
    txt2.setCharacterSize(20);
    txt2.setFillColor(sf::Color::Black);
    vector<sf::Sprite> BinSprite(9);
    vector<sf::Sprite> FavoriteSprite(9);
    vector<sf::Sprite> NotFavoriteSprite(9);
    vector<string> IsFavorite(9);
    vector<string> IsDeleted(9);
    vector<string> IsDone(9);
    vector<sf::Sprite> IsDoneSprite(9);
    vector<sf::Sprite> NotDoneSprite(9);
    vector<sf::Text> TaskName;
    sf::Text Task1;
    vector<Task> task;

    ifstream Tasks1("../Tasks.txt", ios::app | ios::in);
    if (!Tasks1.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Task a;

    while (!Tasks1.fail() && !Tasks1.eof())
    {
        Tasks1 >> a;
        task.push_back(a);
    }
    for (size_t i = 0; i < task.size(); i++)
    {
        cout << task[i].GetName() << endl;
    }
    bool showTasks = true;
    for (size_t i = 0; i < task.size(); i++)
    {
        string name = task[i].GetName();
        IsFavorite[i] = name[name.size() - 1];
        name = name.substr(0, name.size() - 1);
        IsDone[i] = name[name.size() - 1];
        name = name.substr(0, name.size() - 1);
        IsDeleted[i] = name[name.size() - 1];
        name = name.substr(0, name.size() - 1);
        task[i].SetTask(name);
    }

    for (size_t i = 0; i < task.size(); i++)
    {
        Task1.setFont(font2);
        Task1.setString(task[i].GetName());
        TaskName.push_back(Task1);
    }
    int TaskSize = task.size();
    cout << "++++++++" << task.size() << endl;
    task.pop_back();
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
                icon->IconEvents(evnt, *window, task);
            }
            if (Text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
            {
                Text.setFillColor(sf::Color::White);
            }
            else
            {
                Text.setFillColor(sf::Color::Black);
            }
            for (size_t i = 0; i < task.size(); i++)
            {
                if (NotFavoriteSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                {
                    IsFavorite[i] = "1";
                }
                else if (BinSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                {
                    IsDeleted[i] = DrawWindow();
                }
                else if (NotDoneSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                {
                    IsDone[i] = "1";
                }
            }
        }
        for (size_t i = 0; i < task.size(); i++)
        {
            TaskName[i].setFillColor(sf::Color::Black);
            TaskName[i].setPosition(sf::Vector2f(50, (i * 50) + 50));
            TaskName[i].setCharacterSize(30);
            BinSprite[i].setTexture(BinTexture);
            BinSprite[i].setPosition(sf::Vector2f(840, (i * 50) + 50));
            FavoriteSprite[i].setTexture(FavoriteTexture);
            FavoriteSprite[i].setPosition(sf::Vector2f(800, (i * 50) + 50));
            NotFavoriteSprite[i].setTexture(NotFavoriteTexture);
            NotFavoriteSprite[i].setPosition(sf::Vector2f(800, (i * 50) + 50));
            IsDoneSprite[i].setTexture(IsDoneTexture);
            IsDoneSprite[i].setPosition(sf::Vector2f(10, (i * 50) + 50));
            NotDoneSprite[i].setTexture(NotDoneTexture);
            NotDoneSprite[i].setPosition(sf::Vector2f(10, (i * 50) + 50));
        }
        window->clear();
        window->draw(Sprite);
        icon->DrawIcons(*window, icon->Add(), icon->Edit());
        window->draw(Text);
        window->draw(txt2);
        for (size_t i = 0; i < task.size(); i++)
        {
            if ("0" == IsDeleted[i])
            {
                window->draw(TaskName[i]);
                window->draw(BinSprite[i]);
                if (IsFavorite[i] == "1")
                {
                    window->draw(FavoriteSprite[i]);
                }
                else
                {
                    window->draw(NotFavoriteSprite[i]);
                }
                if (IsDone[i] == "1")
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
    for (size_t i = 0; i < TaskSize - 1; i++)
    {
        string name = task[i].GetName();
        name = name + IsDeleted[i] + IsDone[i] + IsFavorite[i];
        task[i].SetTask(name);
    }
    int Delete[task.size()] = {0};
    for (size_t i = 0; i < task.size(); i++)
    {
        if (IsDeleted[i] == "1")
            Delete[i] = 1;
    }
    const int index = task.size();
    for (size_t i = 0; i < index; i++)
    {
        if (IsDeleted[i] == "1")
        {
            task.erase(task.begin() + i);
        }
    }
    ofstream Tasks("../Tasks.txt", ios::trunc);
    if (!Tasks.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Tasks.seekp(ios::beg);
    Tasks << task;
}
ToDo::~ToDo()
{
    delete window;
    delete icon;
}
string DrawWindow() //draw a window if user press delete icon
{
    string check;
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
            if (YesSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                check = "1";
                window.close();
            }
            if (NoSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                check = "0";
                window.close();
            }
            if (evnt.type == sf::Event::Closed)
            {
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
istream &operator>>(istream &input, Task &p)
{
    getline(input, p.TaskName);
    return input;
}
ostream &operator<<(ostream &output, const vector<Task> &p)
{
    for (size_t i = 0; i < p.size(); i++)
    {
        output << p[i].TaskName << "\n";
    }
    return output;
}