#include "functions.hpp"

using namespace std;

string DrawWindow() //draw a window if user press delete icon
{
    string check;
    sf::RenderWindow window;
    window.create(sf::VideoMode(300, 150), "delete", sf::Style::Close);
    window.setPosition(sf::Vector2i(350, 500));    //set position of window
    //declare Sprites and Textures for icons
    Set set;
    sf::Sprite Sprite;
    sf::Texture Texture;
    sf::Sprite YesSprite;
    sf::Texture YesTexture;
    sf::Sprite NoSprite;
    sf::Texture NoTexture;
    std::string iconName = "../assets/icons/cross1.png";

    sf::Font font;
    font.loadFromFile("../assets/icons/f1.ttf");
    sf::Text Text;
    string testig = "Delete this task?";
    Text.setString(testig);
    Text.setFont(font);
    Text.setPosition(sf::Vector2f(25, 0));

    set.SetTexture(YesSprite, iconName, YesTexture, 50, 50);//set Texture for YES icon
    iconName = "../assets/icons/cross.png";
    set.SetTexture(NoSprite, iconName, NoTexture, 160, 50);//set Texture for No icon

    iconName = "../assets/images/background3.jpg";
    Texture.loadFromFile(iconName);
    Sprite.setTexture(Texture);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
            if (YesSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                check = "1";//if user presses YES change check to 1 to delete task
                window.close();
            }
            if (NoSprite.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)))
            {
                check = "0";//if presses NO declare check 0 and the task wont delete
                window.close();
            }
            window.clear();
            window.draw(Sprite);
            window.draw(YesSprite);//draw YES icon
            window.draw(NoSprite);//draw NO icon
            window.draw(Text);
            window.display();
        }
    }
    return check;
}
istream &operator>>(istream &input, Task &p)//overload >> for reading object from file
{
    getline(input, p.TaskName);
    return input;
}
ostream &operator<<(ostream &output, const vector<Task> &p)//overload << for writing vector in file
{
    for (size_t i = 0; i < p.size(); i++)
    {
        output << p[i].TaskName << "\n";
    }
    return output;
}