#ifndef END_H // include guard
#include "SFML/Graphics.hpp"
#define END_H
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class End {
    int numbers = 0;
    int all = 0;

public:
    End() {};

    End(int sc, int al) {
        this->numbers = sc; // кол-во решенных номеров
        this->all = al; // кол-во номеров всего
    }

    void play() {
        RenderWindow window(VideoMode(1500, 844), "My window");
        Vector2i pos_mouse;

        while (window.isOpen())
        {
            bool mouse_pr = false;
            Event event{};
            while (window.pollEvent(event))
            {
                pos_mouse = Mouse::getPosition(window); //координаты мыши

                if (event.type == Event::MouseButtonPressed) // проверка нажата ли кнопка мыши
                {
                    Mouse::Button mouseButton = event.mouseButton.button;
                    mouse_pr = true;
                }
                //cout << pos_mouse.x << "-" << pos_mouse.y << endl;
                if (event.type == Event::Closed)
                    window.close();

            }

            window.clear(Color::Red);
            //backscreen(window);
            screen(window, mouse_pr);
            window.display();
        }
    }
    //void backscreen(RenderWindow& window);
    void screen(RenderWindow& window, bool mouse_pr);



};

#endif MATHTASK_H