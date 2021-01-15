#include "../include/windowDisplay.hpp"

#define Enter_key 13

void WindowDisplay(Button & button)
{
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
                    button.win.close();
                }
                else if (46 < evn.text.unicode && evn.text.unicode < 58)
                {
                    if (button.TaskNumber.size() < 5)
                    {
                        button.TaskNumber += static_cast<char>(evn.text.unicode);
                    }
                }
                button.TaskNumberText.setString(button.TaskNumber);
            }

            button.TaskText.setString(button.Task);
            button.win.clear();
            button.win.draw(button.WindowSprite);
            button.win.draw(button.TaskText);
            button.win.draw(button.TaskNumberText);
            button.win.display();
        }
    }
}
