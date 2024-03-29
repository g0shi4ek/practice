#include <SFML/Graphics.hpp>
#include "menu.h"
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 844), "My window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        
        backscreen(window);
        MenuText(window);
        window.display();

    }

    return 0;
}