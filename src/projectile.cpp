#include <iostream>

#include <SFML/Graphics.hpp>

#include "../include/projectile.hpp"
#include "../include/constants.hpp"
#include "../include/game_manager.hpp"
#include "../include/resources.hpp"

using namespace std;
using namespace sf;

Projectile::Projectile(int bullet_x, int bullet_y, int dmge) {
 	sprite.setTexture(Resources::Textures[PROJECTILE]);
	sprite.setOrigin(sprite.getLocalBounds().width/2,
									 sprite.getLocalBounds().height/2);
	//sprite.setColor(sf::Color(250, 250, 250, 250));
	sprite.setPosition(bullet_x, bullet_y);
	damage = dmge;
}

void Projectile::update() {
	sprite.move(speed);
	if(bottom() <= 0) out_of_screen = true;
	else out_of_screen = false;
}
