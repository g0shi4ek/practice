#include "check.h"

void Check::actions(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) {
    this->choose_backscreen(window, this->sub_state);
    this->question(window, this->answ);
    this->check_answer(window, pos_mouse, mouse_pr);
}

void Check::check_answer(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) {
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");

    // вывод вариантов ответов
    float x = 300;
    float y = 400;
    for (int i = 1; i < 5; i++) {
        RectangleShape b({ 250, 70 });
        if (i % 3 == 0) {
            x += 300;
            y = 400;
        }
        b.setPosition({ x, y });
        Message t(this->answ[i], false, 1);
        t.setFont(font);
        float xPos = (x + b.getLocalBounds().width / 2) - (t.getTxt().getLocalBounds().width / 2);
        float yPos = (y + b.getLocalBounds().height / 2) - (t.getTxt().getLocalBounds().height / 1.5);

        t.setPos({ xPos, yPos });

        if (this->right_ans == i) { // правильный ответ - зелёный
            b.setFillColor(Color(186, 255, 151, 990));
        }
        else if (this->chosen_ans == i - 1) { // неправильный - красный (если на него нажали)
            b.setFillColor(Color(255, 149, 145, 990));
        }
        else { // другие варинаты, на которые не нажали и которые не правильные
            b.setFillColor(Color(255, 255, 255, 990));
        }
        window.draw(b);
        window.draw(t.getTxt());
        y += 100;
    }
    ButtonType1 next(font, (string)"Next", { 250, 70 }, { 700, 700 }, Color(255, 255, 255, 965), pos_mouse, 1);
    next.GetBotton()->setOutlineColor(Color(255, 204, 51));
    next.GetBotton()->setOutlineThickness(3);
    next.print(window);

    ButtonType1 menu(font, (string)"Return to menu", { 350,70 }, { 50, 10 }, Color(255, 255, 255, 965), pos_mouse, 1);
    menu.print(window);

    if (mouse_pr == true && next.isMouse(pos_mouse) == true) {
        window.close();
        this->check_state = 1;
    }
    else if (mouse_pr == true && menu.isMouse(pos_mouse) == true) {
        window.close();
        this->check_state = 0;
    }
}
