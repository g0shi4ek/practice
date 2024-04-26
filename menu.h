#ifndef MENU_H // include guard
#include "SFML/Graphics.hpp"
#define MENU_H
using namespace sf;

class Menu{
public:
    Menu(){
        RenderWindow window(sf::VideoMode(1500, 844), "My window");
        while (window.isOpen())
        {
            Event event{};
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(Color::Red);
            this->backscreen(window);
            this->MenuText(window);
            window.display();
        }
    }
    void backscreen(sf::RenderWindow& window);
    void MenuText(sf::RenderWindow& window);
};

#endif MENU_H
