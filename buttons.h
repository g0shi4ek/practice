#ifndef PRACTICE_BUTTONS_H
#define PRACTICE_BUTTONS_H
#include "SFML/Graphics.hpp"
#include <string>
#include "menu.h"


using namespace std;
using namespace sf;

class Message{
    bool flag;// проверка наведен курсор или нет
    Text txt;
public:

    Message() : flag(false), txt(){};
    Message(string& t, bool f) {
        if (f==true) { //настройки текста если нет курсора
            Font font;
            font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");
            txt.setFont(font);
            txt.setString(t);
            txt.setCharacterSize(40);
            txt.setFillColor(sf::Color::Black);
            txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
            txt.setPosition(350, 300);
            flag = f;

        }
        else { // настройки текста если курсор наведен
            Font font;
            font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");
            txt.setFont(font);
            txt.setString(t);
            txt.setCharacterSize(40);
            txt.setFillColor(sf::Color::Black);
            txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
            txt.setPosition(350.f, 300.f);
            flag = f;
        }
    }
    ~Message() = default;

    void print(RenderWindow& window){
        window.draw(this->txt);
    }


};

class Button{
    Message el; // текст внутри кнопки
    float x,y; // позиция самой кнопки
    RectangleShape rect;
public:
    friend Message;
    Button() : el(),x(0), y(0), rect() {};
    Button(float x_p, float y_p, float x_s, float y_s, string &t, bool f)
            : x(x_p), y(y_p) {
        rect.setSize(Vector2f(x_s,y_s));
        rect.setPosition(x,y);
        rect.setFillColor(Color(0,100,0));
        Message elem(t,f);
        el = elem;
    }

    void print(RenderWindow & window){
        window.draw(rect);
        el.print(window);
    }
};


#endif
