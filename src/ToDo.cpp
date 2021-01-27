#include "todo.hpp"
#include "set.hpp"
#include "functions.hpp"
#include "task.hpp"
#include <iostream>

using namespace std;

ToDo::ToDo()
{
    Set set;
    window = new sf::RenderWindow(sf::VideoMode(900, 601), "ToDO", sf::Style::Close);creating the main window
    window->setPosition(sf::Vector2i(20, 80));
    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf");//set font for Text above of window
    font2.loadFromFile("../assets/icons/f1.ttf");//set font for taskNames

    Text.setFont(font);
    set.SetText(Text, 320, 0, "Make a ToDo list");

    BackgroundTexture.loadFromFile("../assets/images/background.jpg");//set background
    Sprite.setTexture(BackgroundTexture);
    //load icons from aasets file
    BinTexture.loadFromFile("../assets/icons/bin.png");
    FavoriteTexture.loadFromFile("../assets/icons/favorite.png");
    NotFavoriteTexture.loadFromFile("../assets/icons/notFavorite.png");
    IsDoneTexture.loadFromFile("../assets/icons/done.png");
    NotDoneTexture.loadFromFile("../assets/icons/notDone.png");
}
void ToDo::Loop()
{  //declaring vectors for icons and text of taskNames
    vector<sf::Sprite> BinSprite(11);
    vector<sf::Sprite> FavoriteSprite(11);
    vector<sf::Sprite> IsDoneSprite(11);
    vector<string> IsFavorite(11);
    vector<string> IsDeleted(11);
    vector<string> IsDone(11);
    vector<sf::Text> TaskName;
    sf::Text Task1;
    vector<Task> task;

    ifstream Tasks1("../Tasks.txt", ios::app | ios::in);//declare an ifstream file for read from file
    if (!Tasks1.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Task a;

    while (!Tasks1.fail() && !Tasks1.eof())//read from file
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

    for (size_t i = 0; i < task.size(); i++)//set string for texts of task names
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
                if (evnt.type == sf::Event::MouseMoved)
                {
                    if (FavoriteSprite[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
                    {
                        FavoriteSprite[i].setRotation(10.f);
                        FavoriteSprite[i].rotate(10.f);
                        float rotation = FavoriteSprite[i].getRotation();
                    }
                    else
                    {
                        FavoriteSprite[i].setRotation(0.f);
                        FavoriteSprite[i].rotate(0.f);
                        float rotation = FavoriteSprite[i].getRotation();
                    }
                    if (IsDoneSprite[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
                    {
                        IsDoneSprite[i].setRotation(10.f);
                        IsDoneSprite[i].rotate(10.f);
                        float rotation = IsDoneSprite[i].getRotation();
                    }
                    else
                    {
                        IsDoneSprite[i].setRotation(0.f);
                        IsDoneSprite[i].rotate(0.f);
                        float rotation = IsDoneSprite[i].getRotation();
                    }
                    if (BinSprite[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
                    {
                        BinSprite[i].setRotation(10.f);
                        BinSprite[i].rotate(10.f);
                        float rotation = BinSprite[i].getRotation();
                    }
                    else
                    {
                        BinSprite[i].setRotation(0.f);
                        BinSprite[i].rotate(0.f);
                        float rotation = BinSprite[i].getRotation();
                    }
                }
            }
            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                for (size_t i = 0; i < task.size(); i++)
                {
                    if (FavoriteSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                    {
                        if (IsFavorite[i] == "1")
                        {
                            IsFavorite[i] = "0";
                        }
                        else
                            IsFavorite[i] = "1";
                    }
                    else if (BinSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                    {
                        IsDeleted[i] = DrawWindow();
                    }
                    else if (IsDoneSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                    {
                        if (IsDone[i] == "1")
                        {
                            IsDone[i] = "0";
                        }
                        else
                            IsDone[i] = "1";
                    }
                }
            }
        }
        for (size_t i = 0; i < task.size(); i++)//a loop for set color,position and size of task names and set icons for them
        {
            TaskName[i].setFillColor(sf::Color::Black);
            TaskName[i].setPosition(sf::Vector2f(50, (i * 50) + 50));
            TaskName[i].setCharacterSize(30);
            BinSprite[i].setTexture(BinTexture);
            BinSprite[i].setPosition(sf::Vector2f(840, (i * 50) + 50));
            FavoriteSprite[i].setPosition(sf::Vector2f(800, (i * 50) + 50));
            IsDoneSprite[i].setPosition(sf::Vector2f(10, (i * 50) + 50));
        }
        window->clear();
        window->draw(Sprite);
        icon->DrawIcons(*window, icon->Add(), icon->Edit());
        window->draw(Text);
        for (size_t i = 0; i < task.size(); i++)
        {
            if ("0" == IsDeleted[i])
            {
                window->draw(TaskName[i]);
                window->draw(BinSprite[i]);
                if (IsFavorite[i] == "1")
                {
                    FavoriteSprite[i].setTexture(FavoriteTexture);
                }
                else
                {
                    FavoriteSprite[i].setTexture(NotFavoriteTexture);
                }
                if (IsDone[i] == "1")
                {
                    IsDoneSprite[i].setTexture(IsDoneTexture);
                }
                else
                {
                    IsDoneSprite[i].setTexture(NotDoneTexture);
                }
            window->draw(IsDoneSprite[i]);
            window->draw(FavoriteSprite[i]);
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
    int TaskS = task.size() - 1;
    for (size_t i = TaskS; 0 < i; i--)//loop for delete task names from vector
    {
        if (Delete[i] == 1)
            task.erase(task.begin() + i);
    }
    ofstream Tasks("../Tasks.txt", ios::trunc);//declare ofstream file to write in file
    if (!Tasks.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Tasks.seekp(ios::beg);
    Tasks << task;//write an object to file
}
ToDo::~ToDo()
{
    delete window;
    delete icon;
}
