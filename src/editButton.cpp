#include "editButton.hpp"

#define Enter_key 13
#define BACKSPACE_key 8

EditButton::EditButton()
{
    Texture.loadFromFile("../assets/images/background2.jpg");
    Sprite.setTexture(Texture);
    win.create(sf::VideoMode(600, 200), "edit a task", sf::Style::Close);

    font.loadFromFile("../assets/icons/f1.ttf");

    TaskText.setFont(font);
    set.SetText(TaskText, 110, 0, Task);
    TaskText.setFillColor(sf::Color(253, 173, 173));

    TaskNameText.setFont(font);
    set.SetText(TaskNameText, 5, 50, TaskName);

    NameText.setFont(font);
    set.SetText(NameText, 120, 95, Name);
    NameText.setFillColor(sf::Color(253, 173, 173));

    NewNameText.setFont(font);
    set.SetText(NewNameText, 5, 145, NewName);
}
void WindowDisplay(EditButton &button)
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
                    button.TaskName.erase(button.TaskName.size() - 1);
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
                        if (button.NewName.size() < 35)
                        {
                            button.NewName += static_cast<char>(evn.text.unicode);
                        }
                    }
                }
                button.TaskNameText.setString(button.TaskName);
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
            }
            button.win.display();
        }
    }
}
