#include <iostream>

#include <SFML/Graphics.hpp>

#include "../include/projectile.hpp"
#include "../include/constants.hpp"
#include "../include/game_manager.hpp"
#include "../include/resources.hpp"

using namespace std;
using namespace sf;

Projectile::Projectile(int bullet_x, int bullet_y, int dmge, const std::string &faction) {
 	sprite.setTexture(Resources::getTexture(Factions::faction1 + "_projectiles_1"));
	sprite.setOrigin(sprite.getLocalBounds().width/2,
	sprite.getLocalBounds().height/2);
	sprite.setPosition(bullet_x, bullet_y);
	damage_ = dmge;
}

void Projectile::update() {
	sprite.move(speed);
}

bool Projectile::isOutOfScreen() {
	return bottom() < 0;
}

void Projectile::takeHit(int damage) {
	health_ -= damage;
}

bool Projectile::isDestroyed() {
	return health_ <= 0;
}
