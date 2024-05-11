#ifndef MENU_H 
#include "SFML/Graphics.hpp"
#define MENU_H
#include <iostream>

using namespace std;
using namespace sf;


class Menu{
    int state = 0;
public:
    Menu();
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
