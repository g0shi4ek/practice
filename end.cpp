#include "SFML/Graphics.hpp"
#include "end.h"
#include "buttons.h"

using namespace sf;
using namespace std;

void End::screen(RenderWindow&window, bool mouse_pr) {
    Font font;
    font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");


    Message sc((string)"Your score: " + to_string(this->numbers) + "/" +  to_string(this->all), false);
    sc.setFont(font);
    sc.setPos({ 500,200 });
    sc.print(window);

    if (this->numbers == this->all) {
        Message mes((string)"ladno, sharish", false);
        mes.setFont(font);
        mes.setPos({ 500,400 });
        mes.print(window);
    }
    else {
        Message mes((string)" NATASHA LOH ", false);
        mes.setFont(font);
        mes.setPos({ 500,400 });
        mes.print(window);
    }
    if (mouse_pr == true) {
        window.close(); // возвращает в меню
        mouse_pr = false;
    }
}