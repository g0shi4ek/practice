#include "SFML/Graphics.hpp"
#include "menu.h"
#include "buttons.h"

using namespace sf;
using namespace std;

Menu::Menu() {
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

        window.clear(Color::Black);
        backscreen(window);
        choice(window, pos_mouse, mouse_pr);
        window.display();
    }
}

int Menu::choice(RenderWindow& window , Vector2i pos_mouse , bool mouse_pr) {
    
    Font font;
    font.loadFromFile("resources\\Lineyka.ttf");
    Message t((string)"Menu", false, 2);
    t.setFont(font);
    t.setPos({ 576 - t.getTxt().getLocalBounds().width / 2,100});
    t.print(window);
    Button but1(font, (string)"Start", {250,70}, {450, 200}, Color(255, 255, 255, 965), pos_mouse); // нужно высчитать правильное расположение кнопки на окне | ИСПРАВЛЕНО
    Button but2(font, (string)"Finish game", { 250, 70 }, { 450, 300 }, Color(255, 255, 255, 965), pos_mouse);
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
    herotexture.loadFromFile("resources\\images\\menu_back.jpg");

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(0, 0);

    window.clear();
    window.draw(herosprite);
}
