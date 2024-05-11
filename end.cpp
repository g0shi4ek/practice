#include "SFML/Graphics.hpp"
#include <ctime>
#include <cstdlib>
#include "end.h"
#include "buttons.h"

using namespace sf;
using namespace std;

void End::play(int type) {
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
            if (event.type == Event::Closed)
                window.close();

        }

        //window.clear(Color::Red);
        backscreen(window, type);
        screen(window, mouse_pr);
        window.display();
    }
}

void End::screen(RenderWindow&window, bool mouse_pr) {
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");

    RectangleShape q({ 650,250 });
    q.setPosition({ 250, 200 });
    q.setFillColor(Color(255, 255, 255));
    window.draw(q);


    Message sc((string)"Your score: " + to_string(this->numbers) + "/" +  to_string(this->all), false, 1);
    sc.setFont(font);
    sc.setPos({ 576 - sc.getTxt().getGlobalBounds().width / 2,350});
    sc.print(window);

    vector<Color> colors = { Color(196, 255, 0), Color(149, 255, 41), Color(49, 255, 96), Color(48, 255, 166), Color(48, 255, 221), Color(48, 255, 242), Color(48, 221, 255), Color(48, 180, 255), Color(48, 104, 255), Color(97, 48, 255), Color(135, 74, 255), Color(177, 74, 255), Color(245, 92, 255), Color(255, 78, 209), Color(255, 60, 151), Color(255, 60, 99)};

    srand(time(0));
    int n_color = (rand() % 16);

    if (this->numbers == this->all) {
        Text good;
        good.setString("ladno, sharish");
        good.setCharacterSize(75);
        good.setFont(font);
        good.setStyle(Text::Bold);
        good.setColor(colors[n_color]);
        good.setPosition({ 576 - good.getLocalBounds().width / 2, 225});
        window.draw(good);
    }
    else {
        Text bad;
        bad.setString("NATASHA LOH");
        bad.setCharacterSize(75);
        bad.setFont(font);
        bad.setStyle(Text::Bold);
        bad.setColor(colors[n_color]);
        bad.setPosition({ 576 - bad.getLocalBounds().width / 2, 225 });
        window.draw(bad);
    }
    if (mouse_pr == true) {
        window.close(); // возвращает в меню
        mouse_pr = false;
    }
}