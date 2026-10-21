#include <iostream>

#include "basic_transform.h"
#include "sprite_manager.h"

int main() {
    // Code commented out for CI compiling
    // Uncomment them after implementation

    // SpriteManager spriteManager;
    // auto& texture = spriteManager.registerTexture("assets/sword_diamond.png");
    // auto spriteID = spriteManager.createSprite(texture);
    // auto& sprite = spriteManager.getSprite(spriteID);
    // sprite.origin() = {114, 14};
    // sprite.position() = {128, 128};
    // sprite.scale().x = -1;
    const sf::Vector2f& fScale = {3.f, 3.f};
    const sf::Vector2f& fTranslation = {0.f, 5.f};
    BasicTransform f = BasicTransform(fScale, fTranslation);

    const sf::Vector2f& gScale = {2.f, -1.f};
    const sf::Vector2f& gTranslation = {4.f, 3.f};
    BasicTransform g = BasicTransform(gScale, gTranslation);

    BasicTransform fg = BasicTransform::compose(f, g);

    BasicTransform fgInverse = BasicTransform::inverse(fg);


    sf::RenderWindow window(sf::VideoMode({256, 256}), "Sprites lab", sf::State::Windowed);
    // window.setMouseCursorVisible(false); // you can use this to hide the mouse
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                return 0;
            }
        }
        // sprite.position() = sf::Vector2f(sf::Mouse::getPosition(window));
        sf::RenderStates states{};
        window.clear(sf::Color::White);
        // sprite.draw(window, states);
        window.display();
    }
    return 0;
}
