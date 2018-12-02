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
	explosion.setPosition(sprite.getPosition());

	if(hit_points > 0)
		move();

	if(explosion.played) isDestroyed_ = true;
}

void Enemy::move() {
	sprite.move(0, maxSpeed.y);
}
