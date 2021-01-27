#include "editButton.hpp"

#define ENTER_KEY 13
#define BACKSPACE_KEY 8

using namespace std;

EditButton::EditButton() // load Textures and set Texts and Sprites
{
    Texture.loadFromFile("../assets/images/background2.png"); // set background for window
    Sprite.setTexture(Texture);
    Win.create(sf::VideoMode(600, 300), "edit a task", sf::Style::Close); // creating the window for edit tasks
    Win.setPosition(sf::Vector2i(350, 500));                              // set position of window

    font.loadFromFile("../assets/icons/f1.ttf"); // loading font

    TaskText.setFont(font);
    set.SetText(TaskText, 130, 0, Task);
    TaskText.setFillColor(sf::Color(253, 173, 173));

    TaskNameText.setFont(font);
    set.SetText(TaskNameText, 5, 40, TaskName);

    NameText.setFont(font);
    set.SetText(NameText, 150, 95, Name);
    NameText.setFillColor(sf::Color(253, 173, 173));

    NewNameText.setFont(font);
    set.SetText(NewNameText, 5, 135, NewName);

    WindowText.setFont(font);
    set.SetText(WindowText, 120, 270, WindowString);
    WindowText.setCharacterSize(20);
}
void WindowDisplay(EditButton &button, vector<Task> &task) // display EditButton window
{
    bool IsNameEntered = false;
    while (button.Win.isOpen())
    {
        sf::Event evn;
        if (button.Win.pollEvent(evn))
        {
            if (evn.type == sf::Event::Closed)
            {
                button.Win.close(); // close the EditButton window
            }
            if (evn.type == sf::Event::TextEntered)
            {
                if (evn.text.unicode == ENTER_KEY)
                {
                    IsNameEntered = true;
                }
                if (evn.text.unicode == BACKSPACE_KEY) // delete the last character from string if BACKSPACE is pressed
                {
                    if (!IsNameEntered)
                    {
                        button.TaskName.erase(button.TaskName.size() - 1);
                    }
                    else
                    {
                        button.NewName.erase(button.NewName.size() - 1);
                    }
                }
                else if (evn.text.unicode < 128)
                {
                    if (!IsNameEntered)
                    {
                        if (button.TaskName.size() < 35)
                        {
                            button.TaskName += static_cast<char>(evn.text.unicode); // getting the name of task that user wants to change
                        }
                    }
                    else
                    {
                        if (button.NewName.size() < 35)
                        {
                            button.NewName += static_cast<char>(evn.text.unicode); // getting the new name
                        }
                    }
                }
                button.TaskNameText.setString(button.TaskName); // set the string for name
            }
            button.TaskText.setString(button.Task);
            button.NameText.setString(button.Name);
            button.NewNameText.setString(button.NewName); // set the string for new name
            button.Win.clear();
            button.Win.draw(button.Sprite);
            button.Win.draw(button.TaskText);
            button.Win.draw(button.TaskNameText); // draw the name
            if (IsNameEntered)
            {
                button.Win.draw(button.NameText);
                button.Win.draw(button.NewNameText); // draw new name
                button.Win.draw(button.WindowText);
            }
            button.Win.display();
        }
    }
    for (size_t i = 0; i < task.size(); i++)
    {
        if (button.TaskName == task[i].GetName())   // checks if the input is a task name
        {
            task[i].SetTask(button.NewName); // set the new name for the object
        }
    }
}