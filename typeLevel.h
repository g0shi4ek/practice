#ifndef TYPELEVEL_H // include guard
#include "SFML/Graphics.hpp"
#define TYPELEVEL_H
#include <iostream>
#include "menu.h"
#include "buttons.h"

using namespace std;
using namespace sf;

class Menu;
class TypeLevel: public Menu { // какая-то проблема с наследованием почему-то если конструктор чисто от меню брать то не работает переключение на новое окно
    int state = 0;
public:
    TypeLevel() {
        RenderWindow window(VideoMode(1500, 844), "My window");
        Vector2i pos_mouse;
        state = 0;

        while (window.isOpen())
        {
            Event event{};
            bool mouse_pr = false;
            while (window.pollEvent(event))
            {

                pos_mouse = Mouse::getPosition(window); //координаты мышки
                if (event.type == Event::MouseButtonPressed) // проверка нажата ли кнопка мыши
                {
                    Mouse::Button mouseButton = event.mouseButton.button;
                    mouse_pr = true;
                }
                if (event.type == Event::Closed)
                    window.close();

            }
            window.clear(Color::Black);
            backscreen(window);
            choice(window, pos_mouse, mouse_pr);
            window.display();
        }
    };


    int choice(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) override;
    void backscreen(RenderWindow& window) override;

    int getState() {
        return this->state;
    }
};

#endif TYPELEVEL_H
