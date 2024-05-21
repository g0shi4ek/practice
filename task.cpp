#include "SFML/Graphics.hpp"
#include "task.h"
#include "buttons.h"

using namespace sf;
using namespace std;

void Task::actions(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) {
    choose_backscreen(window, this->getSubjectState());
    variants(window, pos_mouse, mouse_pr, this->answers, this->right);
    question(window, this->answers);
}

//  выбор фона по предмету
void Task::choose_backscreen(RenderWindow& window, int type) {
    if (type == 0 || type == 1 || type == 2 || type == 3) {
        this->backscreen(window, "russian_back.jpg");
    }
    else if (type == 4 || type == 5 || type == 6 || type == 7) {
        this->backscreen(window, "english_back.jpg");
    }
    else {
        this->backscreen(window, "math_back.jpg");
    }
}

int Task::variants(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr, vector<string> ans, int right) {
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");

    ButtonType1 menu(font, (string)"Return to menu", { 350,70 }, { 50, 10 }, Color(255, 255, 255, 965), pos_mouse, 1);
    menu.print(window);

    vector<ButtonType1> var;

    // варианты ответа
    var.push_back({font, ans[1], {250, 70}, {300, 400}, Color(255, 255, 255, 965), pos_mouse, 1 });
    var.push_back({ font, ans[2], {250, 70}, {300, 500}, Color(255, 255, 255, 965), pos_mouse, 1 });
    var.push_back({ font, ans[3], {250, 70}, {600, 400}, Color(255, 255, 255, 965), pos_mouse, 1 });
    var.push_back({ font, ans[4], {250, 70}, {600, 500}, Color(255, 255, 255, 965), pos_mouse, 1 });

    var[0].print(window);
    var[1].print(window);
    var[2].print(window);
    var[3].print(window);

    for (int i = 0; i < var.size(); i++) {
        if (mouse_pr == true && var[i].isMouse(pos_mouse) == true) {
            if (i == right - 1) {
                window.close();
                this->score++;
                this->ans = true;
                this->GetDone()[this->sub_state * 15 + this->lv_num] = true;
                this->GetResults()[this->sub_state * 15 + this->lv_num] = true;
                this->state = 1; // правильный ответ
                mouse_pr = false;
            }
            else {      // неправльный ответ
                this->ans = false;
                this->state = 0;
                this->GetDone()[this->sub_state * 15 + this->lv_num] = true;
                if (this->GetResults()[this->sub_state * 15 + this->lv_num] != true) {
                    this->GetResults()[this->sub_state * 15 + this->lv_num] = false;
                }
                mouse_pr = false;
                window.close();
            }
            this->chosen = i;
        }
    }

    if (mouse_pr == true && menu.isMouse(pos_mouse) == true) {
        window.close();
        this->score = 0;
        this->ans = false;
        this->state = 2; // возвращает в меню
        mouse_pr = false;
    }
    return 0;
}


void Task::question(RenderWindow& window, vector<string> ans) { 
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");

    // прямоугольник для вопроса 
    RectangleShape q({550,150 });
    q.setPosition({ 300, 200 });
    q.setFillColor(Color(255, 255, 255));
    q.setOutlineColor(Color(255, 204, 51));
    q.setOutlineThickness(5);
    window.draw(q);

    Message quest(ans[0], false, 2);
    quest.setFont(font);
    float pos = 576 - quest.getTxt().getLocalBounds().width / 2;
    quest.setPos({ pos,250 });
    quest.print(window);

    /*Message sc((string)"Your score: " + to_string(this->score), false, 1);
    sc.setFont(font);
    sc.setPos({ 700,50 }); 
    sc.print(window);*/

};
