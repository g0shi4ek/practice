#ifndef END_H
#include "SFML/Graphics.hpp"
#include "task.h"
#define END_H
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class End : public Task { 
    int numbers = 0;
    int all = 0;
public:
    End() {};

    End(int sc, int al) {
        this->numbers = sc; // кол-во решенных номеров
        this->all = al; // кол-во номеров всего
    }
    void actions(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) override;

    void final_screen(RenderWindow& window, bool mouse_pr, Vector2i pos_mouse);
};

#endif END_H