#include "SFML/Graphics.hpp"
#include "task.h"
#include "buttons.h"

using namespace sf;
using namespace std;

int Task::variants(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr, vector<string> ans, int right) {
    Font font;
    font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");

    Button menu(font, (string)"Return to menu", { 200,60 }, { 100, 10 }, Color(255, 255, 255), pos_mouse);
    menu.print(window);

    vector<Button> var;

    var.push_back({font, ans[1], {200,60}, {200, 400}, Color(255, 255, 255), pos_mouse });
    var.push_back({ font, ans[2], {200,60}, {200, 500}, Color(255, 255, 255), pos_mouse });
    var.push_back({ font, ans[3], {200,60}, {600, 400}, Color(255, 255, 255), pos_mouse });
    var.push_back({ font, ans[4], {200,60}, {600, 500}, Color(255, 255, 255), pos_mouse });

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
                this->state = 1; // переход на следующий уровень
                mouse_pr = false;
            }
            else {
                window.close();
                this->score = 0;
                this->ans = false;
                this->state = 0; // табличка которая высвечивает результат при нажатии возвращает в меню
                mouse_pr = false;
            }
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


void Task::question(RenderWindow& window, vector<string> ans) {  // когда второй раз запускаешь один и тот же предмет не закрывая программу почему-то score =1
    Font font;
    font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");

    Message quest(ans[0], false);
    quest.setFont(font);
    quest.setPos({ 550,100 }); // должен быть по центру (само задание)
    quest.print(window);

    Message sc((string)"Your score: " + to_string(this->score), false);
    sc.setFont(font);
    sc.setPos({ 700,50 }); 
    sc.print(window);

};