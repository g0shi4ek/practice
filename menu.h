#ifndef MENU_H // include guard
#include "SFML/Graphics.hpp"
#define MENU_H
#include <iostream>

using namespace std;
using namespace sf;


class Menu{
    int state = 0;
public:
    Menu(){
        RenderWindow window(VideoMode(1500, 844), "My window");
        Vector2i pos_mouse;

        while (window.isOpen())
        {
            bool mouse_pr = false;
            Event event{};
            while (window.pollEvent(event))
            {

                pos_mouse = Mouse::getPosition(window); //���������� ����

                if (event.type == Event::MouseButtonPressed) // �������� ������ �� ������ ����
                {
                    Mouse::Button mouseButton = event.mouseButton.button;
                    mouse_pr = true;
                }
                //cout << pos_mouse.x << "-" << pos_mouse.y << endl;
                if (event.type == Event::Closed)
                    window.close();

            }
 
            window.clear(Color::Black);
            backscreen(window);
            choice(window, pos_mouse, mouse_pr);
            window.display();
            
        }
    }
    virtual void backscreen(RenderWindow& window);
    virtual int choice(RenderWindow& window , Vector2i pos_mouse, bool mouse_pr);

    int getState() {
        return this->state;
    }

    void setState(int s) {
        this->state = s;
    }

};

#endif MENU_H
