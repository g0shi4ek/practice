#ifndef END_H // include guard
#include "SFML/Graphics.hpp"
#include "task.h"
#define END_H
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Task;

class End : public Task { // добавила наследование, чтобы функцию фона не копировать
    int numbers = 0;
    int all = 0;

public:
    End() {};

    End(int sc, int al) {
        this->numbers = sc; // кол-во решенных номеров
        this->all = al; // кол-во номеров всего
    }

    void play(int type);
   // void backscreen(RenderWindow& window, int type);
    void screen(RenderWindow& window, bool mouse_pr);



};

#endif MATHTASK_H