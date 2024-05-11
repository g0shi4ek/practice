#include "SFML/Graphics.hpp"
#include "task.h"
#include "buttons.h"

using namespace sf;
using namespace std;

void Task::play(int type) {
    RenderWindow window(VideoMode(1152, 896), "My window");
    Vector2i pos_mouse;

    while (window.isOpen())
    {
        bool mouse_pr = false;
        Event event{};
        while (window.pollEvent(event))
        {

            pos_mouse = Mouse::getPosition(window); //координаты мыши

            if (event.type == Event::MouseButtonPressed) // проверка нажата ли кнопка мыши
            {
                Mouse::Button mouseButton = event.mouseButton.button;
                mouse_pr = true;
            }
            //cout << pos_mouse.x << "-" << pos_mouse.y << endl;
            if (event.type == Event::Closed)
                window.close();

        }

        backscreen(window, type);
        variants(window, pos_mouse, mouse_pr, this->answers, this->right);
        question(window, this->answers);
        window.display();
    }
}

int Task::variants(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr, vector<string> ans, int right) {
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");

    Button menu(font, (string)"Return to menu", { 350,70 }, { 50, 10 }, Color(255, 255, 255, 965), pos_mouse);
    menu.print(window);

    vector<Button> var;

    var.push_back({font, ans[1], {250, 70}, {300, 400}, Color(255, 255, 255, 965), pos_mouse });
    var.push_back({ font, ans[2], {250, 70}, {300, 500}, Color(255, 255, 255, 965), pos_mouse });
    var.push_back({ font, ans[3], {250, 70}, {600, 400}, Color(255, 255, 255, 965), pos_mouse });
    var.push_back({ font, ans[4], {250, 70}, {600, 500}, Color(255, 255, 255, 965), pos_mouse });

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
                                                                             // | вроде нет такой проблемы 
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
    quest.setPos({ pos,250 }); // должен быть по центру (само задание) | ИСПРАВЛЕНО
    quest.print(window);

    Message sc((string)"Your score: " + to_string(this->score), false, 1);
    sc.setFont(font);
    sc.setPos({ 700,50 }); 
    sc.print(window);

};

void Task::backscreen(RenderWindow& window, int type) {
    Texture herotexture;
    if (type == 1) {
        herotexture.loadFromFile("resources\\images\\russian_back.jpg");
    }
    else if (type == 2) {
        herotexture.loadFromFile("resources\\images\\english_back.jpg");
    }
    else {
        herotexture.loadFromFile("resources\\images\\math_back.jpg");
    }

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(0, 0);

    window.clear();
    window.draw(herosprite);
}
