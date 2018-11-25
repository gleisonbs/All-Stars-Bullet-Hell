#include <cstdlib>
#include <iostream>
#include <map>

#include "../include/constants.hpp"
#include "../include/enemy.hpp"

using namespace std;
using namespace sf;

Enemy::Enemy(const string textureKey, const string faction, Vector2f position) : Spaceship(textureKey, faction) {
	sprite.setPosition(position);
	sprite.setOrigin(sprite.getGlobalBounds().width/2,
	sprite.getGlobalBounds().height/2);
	sprite.rotate(180);
}

bool Enemy::isOutOfScreen() {
	return bottom() <= 0;
}

void Enemy::update() {
	if(hit_points > 0)
		sprite.move(sf::Vector2f{0, 1});

	explosion.set_position(sprite.getPosition());
}
