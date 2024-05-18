#ifndef TYPELEVEL_H // include guard
#include "SFML/Graphics.hpp"
#define TYPELEVEL_H
#include <iostream>
#include "menu.h"
#include "buttons.h"

using namespace std;
using namespace sf;

class Menu;

class TypeLevel : public Menu { 
    int subject_state = 0;
public:
    int choice(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) override;
 
    int getSubjectState() {
        return this->subject_state;
    }
};

#endif TYPELEVEL_H
