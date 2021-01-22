#include "deleteButton.hpp"
#include <string>

DeleteButton::DeleteButton()
{
    std::string iconName = "../assets/icons/bin.png";
    set.setTexture(DeletedSprite, iconName, DeletedTexture, 715, 50);
    iconName = "../assets/icons/t1.png";
    

    // window.create(sf::VideoMode(300, 150), "delete", sf::Style::Close);
}
sf::Sprite DeleteButton::GetDeletedSprite()
{
    return DeletedSprite;
}
void DeleteButton::SetIsDeleted(int check)
{
    isDeleted = check;
}
int DeleteButton::GetIsDeleted(void)
{
    return isDeleted;
}
// bool DeleteButton::DrawWindow()
// {
//     while (window.isOpen())
//     {
//         sf::Event evnt;
//         while (window.pollEvent(evnt))
//         {
//             if (evnt.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//         }
//         window.clear();
//         window.draw(YesSprite);
//         window.draw(NoSprite);
//         window.display();
//     }
// }
