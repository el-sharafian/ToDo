#include "deleteButton.hpp"

DeleteButton::DeleteButton()
{
    WindowTexture.loadFromFile("../assets/images/ax5.jpg");
    WindowSprite.setTexture(WindowTexture);
    win.create(sf::VideoMode(400, 200), "edit a task", sf::Style::Close);

    font.loadFromFile("../assets/icons/font.ttf");

    TaskText.setFont(font);
    TaskText.setPosition(sf::Vector2f(10, 0));
    TaskText.setString(Task);
    TaskText.setFillColor(sf::Color(20, 100, 100));
    TaskText.setCharacterSize(30);

    TaskNumberText.setFont(font);
    TaskNumberText.setPosition(sf::Vector2f(150, 50));
    TaskNumberText.setString(TaskNumber);
    TaskNumberText.setFillColor(sf::Color::Black);
    TaskNumberText.setCharacterSize(30);
}
