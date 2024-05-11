#include "buttons.h"

Message::Message(string& t, bool f, int ms_type) {
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");
    txt.setString(t);
    if (ms_type == 1) {
        txt.setFillColor(Color(5, 8, 94));
        txt.setCharacterSize(40);
        txt.setStyle(Text::Bold);
        flag = f;
    }
    else {
        txt.setFillColor(Color(5, 8, 94));
        txt.setCharacterSize(60);
        txt.setStyle(Text::Bold);
        txt.setOutlineColor(Color(216, 237, 255));
        txt.setOutlineThickness(1);
        flag = f;
    }
}

void Message::print(RenderWindow& window) {
    window.draw(this->txt);
}

void Message::setFont(Font& font) {
    txt.setFont(font);
}

void Message::setPos(Vector2f pos) {
    txt.setPosition(pos);
}

Text Message::getTxt() {
    return this->txt;
}

Button::Button(Font& font, string& t, Vector2f size_btn, Vector2f pos_btn, Color bgcolor, Vector2i pos_mouse) {
    btn.setSize(size_btn);
    btn.setPosition(pos_btn);
    btn.setFillColor(bgcolor);

    Message elem(t, isMouse(pos_mouse), 1);
    elem.setFont(font);
    setPostext(size_btn, pos_btn, elem);
    text = elem;
}

void Button::setPostext(Vector2f size_btn, Vector2f pos_btn, Message& el) { //для того чтобы текст был посередине мб надо поменять
    float xPos = (pos_btn.x + btn.getLocalBounds().width / 2) - (el.getTxt().getLocalBounds().width / 2);
    float yPos = (pos_btn.y + btn.getLocalBounds().height / 2) - (el.getTxt().getLocalBounds().height / 1.5);

    el.setPos({ xPos,yPos });
}

void Button::setBgcolor(Color bgcolor) {
    btn.setFillColor(bgcolor);
}

bool Button::isMouse(Vector2i mouse_pos) {

    float btn_x1 = btn.getPosition().x; //начальные координаты кнопки 
    float btn_y1 = btn.getPosition().y;

    float btn_x2 = btn.getPosition().x + btn.getGlobalBounds().width; //конечные координаты кнопки 
    float btn_y2 = btn.getPosition().y + btn.getGlobalBounds().height;

    if (mouse_pos.x > btn_x1 && mouse_pos.x < btn_x2 && mouse_pos.y > btn_y1 && mouse_pos.y < btn_y2) {
        setBgcolor(Color(255, 255, 255));// цвет наведенной кнопки
        return true;
    }
    return false;
}

void Button::print(RenderWindow& window) {
    window.draw(btn);
    window.draw(text.getTxt());
}