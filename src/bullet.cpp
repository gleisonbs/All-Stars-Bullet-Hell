#include <SFML/Graphics.hpp>
#include <iostream>

#include "bullet.hpp"
#include "constants.hpp"
#include "game_manager.hpp"
#include "resource_manager.hpp"

using namespace std;
using namespace sf;

Bullet::Bullet(int bullet_x, int bullet_y, int dmge) {
 	sprite.setTexture(ResourceManager::Textures[PROJECTILE]);
	sprite.setOrigin(sprite.getLocalBounds().width/2,
									 sprite.getLocalBounds().height/2);
	//sprite.setColor(sf::Color(250, 250, 250, 250));
	sprite.setPosition(bullet_x, bullet_y);
	damage = dmge;
}

void Bullet::update() {
	sprite.move(speed);
	if(bottom() <= 0) out_of_screen = true;
	else out_of_screen = false;
}
