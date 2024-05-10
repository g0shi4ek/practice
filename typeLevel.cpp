#include "SFML/Graphics.hpp"
#include "typeLevel.h"
#include "buttons.h"

using namespace sf;
using namespace std;

TypeLevel::TypeLevel() {
    RenderWindow window(VideoMode(1152, 896), "My window");
    Vector2i pos_mouse;
    state = 0;
    while (window.isOpen())
    {
        Event event{};
        bool mouse_pr = false;
        while (window.pollEvent(event))
        {

            pos_mouse = Mouse::getPosition(window); //координаты мышки
            if (event.type == Event::MouseButtonPressed) // проверка нажата ли кнопка мыши
            {
                Mouse::Button mouseButton = event.mouseButton.button;
                mouse_pr = true;
            }
            if (event.type == Event::Closed)
                window.close();

        }
        window.clear(Color::Black);
        backscreen(window);
        choice(window, pos_mouse, mouse_pr);
        window.display();
    }
}

int TypeLevel::choice(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) {
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");
    Message t((string)"Choose the subject", false, 2);
    t.setFont(font);
    t.setPos({ 576 - t.getTxt().getGlobalBounds().width / 2,100});
    t.print(window);

    Button type1(font, (string)"Russian", { 200,60 }, { 475, 200 }, Color(255, 255, 255, 965), pos_mouse);
    Button type2(font, (string)"English", { 200,60 }, { 475, 300 }, Color(255, 255, 255, 965), pos_mouse);
    Button type3(font, (string)"Math", { 200,60 }, { 475, 400 }, Color(255, 255, 255, 965), pos_mouse);
    Button type4(font, (string)"Return to menu", { 400,60 }, { 380, 500 }, Color(255, 255, 255, 965), pos_mouse);

    type1.print(window);
    type2.print(window);
    type3.print(window);
    type4.print(window);

    if (mouse_pr == true && type1.isMouse(pos_mouse) == true) {
        window.close();
        this->state = 1;
        return 0;
    }

    if (mouse_pr == true && type2.isMouse(pos_mouse) == true) {
        window.close();
        this->state = 2;
        return 0;
    }
    if (mouse_pr == true && type3.isMouse(pos_mouse) == true) {
        window.close();
        this->state = 3;
        return 0;
    }

    if (mouse_pr == true && type4.isMouse(pos_mouse) == true) {
        window.close();
        this->state = 4;
        return 0;
    }
}


void TypeLevel::backscreen(RenderWindow& window) { // тут если менять картинку начальную
    Texture herotexture;
    herotexture.loadFromFile("resources\\images\\menu_back.jpg");

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(0, 0);

    window.clear();
    window.draw(herosprite);
}
