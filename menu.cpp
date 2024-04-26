#include "SFML/Graphics.hpp"
#include "menu.h"
#include "buttons.h"


using namespace sf;
using namespace std;

void Menu::MenuText(RenderWindow& window) {

    /*Font font;
    font.loadFromFile("C:\\Users\\dassa\\CLionProjects\\practice\\VividSans-Regular.ttf");
    Text text;
    text.setFont(font);
    text.setString("Hello world! Great to see you!");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(350.f, 300.f);
    window.draw(text);*/
    string a = "hiho";
    Button but(100, 100, 200, 200, a, false);
    but.print(window);
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
