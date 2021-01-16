#include "editButton.hpp"

EditButton::EditButton()
{
    WindowTexture.loadFromFile("../assets/images/ax5.jpg");
    WindowSprite.setTexture(WindowTexture);
    win.create(sf::VideoMode(400, 200), "edit a task", sf::Style::Close);
    
    font.loadFromFile("../assets/icons/f1.ttf");

    TaskText.setFont(font);
    set.setText(TaskText, 10, 0, Task);

    TaskNumberText.setFont(font);
    set.setText(TaskNumberText, 150, 50, TaskNumber); 
}