#include <drawable.hpp>

Drawable::Drawable(sf::Texture texture, int x_pos, int y_pos, double x_scale, double y_scale) {
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);

    sprite.setColor(Color(255, 255, 255, 255));
    sprite.setPosition(x_pos, y_pos);

    sprite.scale(x_scale, y_scale)
}
