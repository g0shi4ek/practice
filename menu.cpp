#include "SFML/Graphics.hpp"

using namespace sf;

void MenuText(RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("fonts\\Lineyka.ttf");
    
    sf::Text text;

    text.setFont(font);

    text.setString("Hello world! Great to see you!");

    text.setCharacterSize(40);

    text.setFillColor(sf::Color::White);

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(350.f, 300.f);
    window.draw(text);
}

void backscreen(RenderWindow& window) {
    Texture herotexture;
    herotexture.loadFromFile("images\\menu.jpg");

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(0, 0);

    window.clear();
    window.draw(herosprite);

}
