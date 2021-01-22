#include "editButton.hpp"

EditButton::EditButton()
{
    Texture.loadFromFile("../assets/images/ax5.jpg");
    Sprite.setTexture(Texture);
    win.create(sf::VideoMode(600, 200), "edit a task", sf::Style::Close);
    
    font.loadFromFile("../assets/icons/f1.ttf");

    TaskText.setFont(font);
    set.setText(TaskText, 100, 0, Task);

    TaskNameText.setFont(font);
    set.setText(TaskNameText, 0, 50, TaskName); 
}