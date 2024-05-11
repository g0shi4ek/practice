#ifndef TYPELEVEL_H // include guard
#include "SFML/Graphics.hpp"
#define TYPELEVEL_H
#include <iostream>
#include "menu.h"
#include "buttons.h"

using namespace std;
using namespace sf;

class Menu;
class TypeLevel { // �����-�� �������� � ������������� ������-�� ���� ����������� ����� �� ���� ����� �� �� �������� ������������ �� ����� ����
    // � ������ ������������, ��� ��� ��� ����� �� �����, �� ��-�� ���� ���� ���� ������ ������ �� �����
    int state = 0;
public:
    TypeLevel();

    int choice(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr);
    void backscreen(RenderWindow& window);

    int getState() {
        return this->state;
    }
};

#endif TYPELEVEL_H
