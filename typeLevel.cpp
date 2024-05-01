#include "SFML/Graphics.hpp"
#include "typeLevel.h"
#include "buttons.h"

using namespace sf;
using namespace std;

int TypeLevel::choice(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) {
    Font font;
    font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");
    Message t((string)"Choose the subject", false);
    t.setFont(font);
    t.setPos({ 550,100 });
    t.print(window);

    Button type1(font, (string)"Russian", { 200,60 }, { 500, 200 }, Color(255, 255, 255), pos_mouse);
    Button type2(font, (string)"English", { 200,60 }, { 500, 300 }, Color(255, 255, 255), pos_mouse);
    Button type3(font, (string)"Math", { 200,60 }, { 500, 400 }, Color(255, 255, 255), pos_mouse);
    Button type4(font, (string)"Return to menu", { 400,60 }, { 500, 500 }, Color(255, 255, 255), pos_mouse);

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
    herotexture.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\menu_pic.jpg");

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(0, 0);

    window.clear();
    window.draw(herosprite);
}
