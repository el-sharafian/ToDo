#include "deleteButton.hpp"

DeleteButton::DeleteButton()
{
    WindowTexture.loadFromFile("../assets/images/ax5.jpg");
    WindowSprite.setTexture(WindowTexture);
    win.create(sf::VideoMode(400, 200), "delete a task", sf::Style::Close);

    font.loadFromFile("../assets/icons/f1.ttf");

    set.setText(TaskText, 35, 0, Task);
    TaskText.setFont(font);

    set.setText(TaskNumberText, 150, 50, TaskNumber);
    TaskNumberText.setFont(font);
}