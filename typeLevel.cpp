#include "typeLevel.h"

int TypeLevel::choice(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) {
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");
    Message t((string)"Choose the theme", false, 2);
    t.setFont(font);
    t.setPos({ 576 - t.getTxt().getGlobalBounds().width / 2,100});
    t.print(window);

    Message t1((string)"Russian", false, 2);
    t1.setFont(font);
    t1.setPos({ 110,200 });
    t1.print(window);

    Message t2((string)"English", false, 2);
    t2.setFont(font);
    t2.setPos({ 470,200 });
    t2.print(window);

    Message t3((string)"Math", false, 2);
    t3.setFont(font);
    t3.setPos({830,200 });
    t3.print(window);

    // кнопки с темами
    vector <string> opts = { "Slovarnie slova", "Udareniya", "Chasti rechi", "Pod sushestv", "Animals", "Food", "Actions", "Furniture", "+", "-", "*", "|" };
    vector<ButtonType1> btns;

    float x = -290;
    float y = 300;
    for (int i = 0; i < 12; i++) {
        if (i % 4 == 0) {
            x += 350;
            y = 300;
        }
        ButtonType1 b(font, opts[i], { 325, 60 }, { x, y }, Color(255, 255, 255, 965), pos_mouse, 1);
        b.print(window);
        btns.push_back(b);
        y += 100;
    }

    ButtonType1 rtn_menu(font, (string)"Return to menu", { 400,60 }, { 50, 10 }, Color(255, 255, 255, 965), pos_mouse, 1);
    rtn_menu.print(window);

    for (int i = 0; i < 12; i++) {
        if (mouse_pr == true && btns[i].isMouse(pos_mouse) == true) {
            window.close();
            this->subject_state = i;
            return 0;
        }
    }
    if (mouse_pr == true && rtn_menu.isMouse(pos_mouse) == true) {
        window.close();
        this->subject_state = 12;
        return 0;
    }

    return 0;
}
