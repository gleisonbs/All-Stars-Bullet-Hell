#include "../include/drawable.hpp"
#include "../include/resources.hpp"

Drawable::Drawable(std::string race, int x_pos, int y_pos, double x_scale, double y_scale) {
	//texture.loadFromFile();

    sprite.setTexture(Resources::Textures[race]);
    sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);

    sprite.setColor(sf::Color(255, 255, 255, 255));
    sprite.setPosition(x_pos, y_pos);

    sprite.scale(x_scale, y_scale);
}
