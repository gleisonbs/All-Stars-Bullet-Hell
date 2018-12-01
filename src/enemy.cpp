#include <cstdlib>
#include <iostream>
#include <map>

#include "../include/constants.hpp"
#include "../include/enemy.hpp"

using namespace std;
using namespace sf;

Enemy::Enemy(const string faction, const string shipCode, Vector2f position, double scale) : Spaceship(faction, shipCode, scale) {
	sprite.setPosition(position);
	sprite.setOrigin(sprite.getGlobalBounds().width/2,
	sprite.getGlobalBounds().height/2);
	sprite.rotate(180);
}

bool Enemy::isOutOfScreen() {
	return bottom() <= 0;
}

void Enemy::update() {
	explosion.set_position(sprite.getPosition());

	if(hit_points > 0)
		sprite.move(0, maxSpeed.y);
		//sprite.move(sf::Vector2f{0, 1});

	if(explosion.played) isDestroyed_ = true;
}
