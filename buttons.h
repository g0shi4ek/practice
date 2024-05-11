#ifndef PRACTICE_BUTTONS_H
#define PRACTICE_BUTTONS_H
#include "SFML/Graphics.hpp"
#include <string>
#include "menu.h"


using namespace std;
using namespace sf;

class Message{
    bool flag = false;// проверка наведен курсор или нет
    Text txt;
public:
    Message() {};
    Message(string& t, bool f, int ms_type);
    ~Message() {};

    void print(RenderWindow& window);
    void setFont(Font& font);
    void setPos(Vector2f pos);
    Text getTxt();
};

class Button{
    Message text; // текст внутри кнопки
    RectangleShape btn;
public:
    friend Message;
    Button() {};
    Button(Font& font, string& t, Vector2f size_btn, Vector2f pos_btn, Color bgcolor, Vector2i pos_mouse);
    ~Button() {};

    void setPostext(Vector2f size_btn, Vector2f pos_btn, Message& el);
    void setBgcolor(Color bgcolor);
    bool isMouse(Vector2i mouse_pos);
    void print(RenderWindow& window);
};


#endif
