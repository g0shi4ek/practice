#include "SFML/Graphics.hpp"
#include "menu.h"
#include "buttons.h"

using namespace sf;
using namespace std;

int Menu::choice(RenderWindow& window , Vector2i pos_mouse , bool mouse_pr) {
    Font font;
    font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");
    Message t((string)"Menu", false);
    t.setFont(font);
    t.setPos({ 550,100 });
    t.print(window);
    Button but1(font, (string)"Start", {200,60}, {500, 200}, Color(255, 255, 255), pos_mouse); // нужно высчитать правильное расположение кнопки на окне
    Button but2(font, (string)"Finish game", { 200,60 }, { 500, 300 }, Color(255, 255, 255), pos_mouse);
    but1.print(window);
    but2.print(window);


    if (mouse_pr == true && but1.isMouse(pos_mouse) == true) {
        window.close();
        this->state = 1;
        mouse_pr = false;
        return 0;
    }

    if (mouse_pr == true && but2.isMouse(pos_mouse) == true) {
        window.close();
        this->state = 2;
        mouse_pr = false;
        return 0;
    }
}

void Menu::backscreen(RenderWindow& window) {
    Texture herotexture;
    herotexture.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\menu_pic.jpg");

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(0, 0);

    window.clear();
    window.draw(herosprite);
}
