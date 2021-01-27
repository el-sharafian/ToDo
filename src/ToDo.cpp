#include "todo.hpp"
#include "set.hpp"
#include "functions.hpp"
#include "task.hpp"
#include <iostream>

using namespace std;

ToDo::ToDo() // ToDo constructor
{
    Set set;
    window = new sf::RenderWindow(sf::VideoMode(900, 601), "ToDO", sf::Style::Close); // creating the main window
    window->setPosition(sf::Vector2i(20, 80));
    icon = new Icon("../assets/icons");

    font.loadFromFile("../assets/icons/font.ttf"); // set font
    font2.loadFromFile("../assets/icons/f1.ttf");  // set font for taskNames

    WindowText.setFont(font);
    WindowText2.setFont(font2);
    set.SetText(WindowText, 320, 0, "Make a ToDo list");
    set.SetText(WindowText2, 250, 570, "Reopen the window to apply changes:)");
    WindowText2.setCharacterSize(20);

    BackgroundTexture.loadFromFile("../assets/images/background.jpg"); // set background
    Sprite.setTexture(BackgroundTexture);

    // load icons from assets directory
    BinTexture.loadFromFile("../assets/icons/bin.png");
    FavoriteTexture.loadFromFile("../assets/icons/favorite.png");
    NotFavoriteTexture.loadFromFile("../assets/icons/notFavorite.png");
    IsDoneTexture.loadFromFile("../assets/icons/done.png");
    NotDoneTexture.loadFromFile("../assets/icons/notDone.png");
}
void ToDo::Loop()
{
    // declaring vectors for icons and text of taskNames
    vector<sf::Sprite> BinSprite(11);
    vector<sf::Sprite> FavoriteSprite(11);
    vector<sf::Sprite> IsDoneSprite(11);
    vector<string> IsFavorite(11);
    vector<string> IsDeleted(11);
    vector<string> IsDone(11);
    vector<sf::Text> TaskName;
    sf::Text Task1;
    vector<Task> task;

    ifstream Tasks1("../Tasks.txt", ios::app | ios::in); // declare an ifstream file for read from file
    if (!Tasks1.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Task a;
    while (!Tasks1.fail() && !Tasks1.eof()) // read tasks from file
    {
        Tasks1 >> a;
        task.push_back(a);
    }
    for (size_t i = 0; i < task.size(); i++) // set IsFavorite, IsDone and IsDeleted vectors
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
    for (size_t i = 0; i < task.size(); i++) // set string for texts of task names
    {
        Task1.setFont(font2);
        Task1.setString(task[i].GetName());
        TaskName.push_back(Task1);
    }
    bool taskSize = false;
    int TaskSize = task.size();
    task.pop_back();
    while (window->isOpen())
    {
        sf::Event evnt;
        while (window->pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window->close(); // close the main window
            }
            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                taskSize = icon->IconEvents(evnt, *window, task); // if user press add or edit icon
            }
            if (WindowText.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
            {
                WindowText.setFillColor(sf::Color::White); // change the color of text if mouse is on its position
            }
            else
            {
                WindowText.setFillColor(sf::Color::Black);
            }
            for (size_t i = 0; i < task.size(); i++)
            {
                if (evnt.type == sf::Event::MouseMoved) // rotates the sprites if mouse is on their position
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
            if (evnt.type == sf::Event::MouseButtonPressed) // checks if user pressed Favorite or Bin or iIsDone sprites
            {
                for (size_t i = 0; i < task.size(); i++)
                {
                    // if user wants to change Favorite icons
                    if (FavoriteSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                    {
                        if (IsFavorite[i] == "1")
                        {
                            IsFavorite[i] = "0";
                        }
                        else
                        {
                            IsFavorite[i] = "1";
                        }
                    }
                    // if user wants to delete a task
                    else if (BinSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                    {
                        IsDeleted[i] = DrawWindow();
                    }
                    // if user wants to mark a task as done
                    else if (IsDoneSprite[i].getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
                    {
                        if (IsDone[i] == "1")
                        {
                            IsDone[i] = "0";
                        }
                        else
                        {
                            IsDone[i] = "1";
                        }
                    }
                }
            }
        }
        for (size_t i = 0; i < task.size(); i++) // a loop to set color, position and size of task names and set icons for them
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
        if (taskSize)
        {
            WindowS();
            taskSize = false;
        }
        window->draw(Sprite);
        icon->DrawIcons(*window, icon->Add(), icon->Edit());
        window->draw(WindowText);
        window->draw(WindowText2);

        for (size_t i = 0; i < task.size(); i++) // draw icons for every task
        {
            if ("0" == IsDeleted[i]) // checks if user deleted the task or not
            {
                window->draw(TaskName[i]);
                window->draw(BinSprite[i]);
                if (IsFavorite[i] == "1") // checks if task is favorite or not
                {
                    FavoriteSprite[i].setTexture(FavoriteTexture); // if task is favorite
                }
                else
                {
                    FavoriteSprite[i].setTexture(NotFavoriteTexture); // if task is not favorite
                }
                if (IsDone[i] == "1") // checks if task is done or not
                {
                    IsDoneSprite[i].setTexture(IsDoneTexture); // if task is done
                }
                else
                {
                    IsDoneSprite[i].setTexture(NotDoneTexture); // if task is not done
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
        name = name + IsDeleted[i] + IsDone[i] + IsFavorite[i]; // add 3 strings at the end of taskName
        task[i].SetTask(name);
    }
    const int index = task.size();
    for (size_t i = 0; i < index; i++)
    {
        if (IsDeleted[i] == "1")
        {
            task.erase(task.begin() + i);
        }
    }
    ofstream Tasks("../Tasks.txt", ios::trunc); // declare ofstream file to write in file
    if (!Tasks.is_open())
    {
        exit(EXIT_FAILURE);
    }
    Tasks.seekp(ios::beg);
    Tasks << task; // write an object to file
}
ToDo::~ToDo() // ToDo destructor
{
    delete window;
    delete icon;
}
