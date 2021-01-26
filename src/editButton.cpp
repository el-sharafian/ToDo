#include "editButton.hpp"

#define Enter_key 13
#define BACKSPACE_key 8
#define ESCAPE_key 27

using namespace std;

EditButton::EditButton()
{
    Texture.loadFromFile("../assets/images/background2.png");
    Sprite.setTexture(Texture);
    win.create(sf::VideoMode(600, 300), "edit a task", sf::Style::Close);

    font.loadFromFile("../assets/icons/f1.ttf");

    TaskText.setFont(font);
    set.SetText(TaskText, 120, 0, Task);
    TaskText.setFillColor(sf::Color(253, 173, 173));

    TaskNameText.setFont(font);
    set.SetText(TaskNameText, 5, 40, TaskName);

    NameText.setFont(font);
    set.SetText(NameText, 135, 95, Name);
    NameText.setFillColor(sf::Color(253, 173, 173));

    NewNameText.setFont(font);
    set.SetText(NewNameText, 5, 135, NewName);

    Text.setFont(font);
    set.SetText(Text, 150, 270, TextString);
    Text.setCharacterSize(20);
}
// unsigned int EditButton::search(fstream &file, string &search)
// {
//     string line;
//     unsigned int curLine;
//     unsigned int cur2;
//     for (curLine = 0; getline(file, line); curLine++)
//     {
//         if (line.find(search) != string::npos)
//         {
//             cout << "found: " << search << "line: " << curLine << endl;
//             cur2 = curLine;
//         }
//     }

//     return cur2;
// }
void WindowDisplay(EditButton &button, vector<Task> &task)
{
    bool IsNameEntered = false;
    while (button.win.isOpen())
    {
        sf::Event evn;
        if (button.win.pollEvent(evn))
        {
            if (evn.type == sf::Event::Closed)
            {
                button.win.close();
            }
            if (evn.type == sf::Event::TextEntered)
            {
                if (evn.text.unicode == Enter_key)
                {
                    IsNameEntered = true;
                }
                if (evn.text.unicode == BACKSPACE_key)
                {
                    if (!IsNameEntered)
                        button.TaskName.erase(button.TaskName.size() - 1);
                    else
                        button.NewName.erase(button.NewName.size() - 1);
                }
                else if (evn.text.unicode < 128)
                {
                    if (!IsNameEntered)
                    {
                        if (button.TaskName.size() < 35)
                        {
                            button.TaskName += static_cast<char>(evn.text.unicode);
                        }
                    }
                    else
                    {
                        if (evn.text.unicode == ESCAPE_key)
                        {
                            button.win.close();
                        }
                        if (button.NewName.size() < 35)
                        {
                            button.NewName += static_cast<char>(evn.text.unicode);
                        }
                    }
                }
                button.TaskNameText.setString(button.TaskName);
                // fstream Tasks("../Tasks.txt", ios::app | ios::in);
                // if (!Tasks.is_open())
                // {
                //     exit(EXIT_FAILURE);
                // }

                // cout << button.search(Tasks, button.TaskName) << endl;
            }
            button.TaskText.setString(button.Task);
            button.NameText.setString(button.Name);
            button.NewNameText.setString(button.NewName);
            button.win.clear();
            button.win.draw(button.Sprite);
            button.win.draw(button.TaskText);
            button.win.draw(button.TaskNameText);
            if (IsNameEntered)
            {
                button.win.draw(button.NameText);
                button.win.draw(button.NewNameText);
                button.win.draw(button.Text);
            }
            button.win.display();
        }
    }
    for (size_t i = 0; i < task.size(); i++)
    {
        if (button.TaskName == task[i].GetName())
        {
            task[i].SetTask(button.NewName);
            cout << task.size() << "****" << endl;
        }
    }
}