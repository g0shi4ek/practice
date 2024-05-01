#include "buttons.h"

Message::Message(string& t, bool f) {
    if (f == false) { //настройки текста если нет курсора (не трогайте все что связано со шрифтом оно оч странно работает)
        Font font;
        font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");
        txt.setString(t);
        txt.setFillColor(Color::Black);
        txt.setCharacterSize(40);
        txt.setStyle(Text::Bold);
        flag = f;
    }

    else { // настройки текста если курсор наведен
        Font font;
        font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");
        txt.setFont(font);
        txt.setString(t);
        txt.setFillColor(Color::White);
        txt.setCharacterSize(40);
        txt.setStyle(Text::Bold | Text::Underlined);
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

    Message elem(t, isMouse(pos_mouse));
    elem.setFont(font);
    setPostext(size_btn, pos_btn, elem);
    text = elem;
}

void Button::setPostext(Vector2f size_btn, Vector2f pos_btn, Message& el) { //для того чтобы текст был посередине мб надо поменять
    float xPos = (pos_btn.x + btn.getGlobalBounds().width / 2) - (el.getTxt().getGlobalBounds().width / 2);
    float yPos = (pos_btn.y + btn.getGlobalBounds().height / 2) - (el.getTxt().getGlobalBounds().height / 2);

    el.setPos({ xPos,yPos });
}

void Button::setBgcolor(Color bgcolor) {
    btn.setFillColor(bgcolor);
}

bool Button::isMouse(Vector2i mouse_pos) {

    float btn_x1 = btn.getPosition().x; //начальные координаты кнопки 500
    float btn_y1 = btn.getPosition().y;

    float btn_x2 = btn.getPosition().x + btn.getGlobalBounds().width; //конечные координаты кнопки 
    float btn_y2 = btn.getPosition().y + btn.getGlobalBounds().height;

    if (mouse_pos.x > btn_x1 && mouse_pos.x < btn_x2 && mouse_pos.y > btn_y1 && mouse_pos.y < btn_y2) {
        setBgcolor(Color::Black);// цвет наведенной кнопки
        return true;
    }
    return false;
}

void Button::print(RenderWindow& window) {
    window.draw(btn);
    window.draw(text.getTxt());
}