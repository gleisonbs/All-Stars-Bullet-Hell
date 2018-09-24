#include <cstdlib>
#include <iostream>
#include <map>

#include "constants.hpp"
#include "enemy.hpp"

using namespace std;
using namespace sf;

Enemy::Enemy(string name, Vector2f position)
						 : Spaceship(name) {
	sprite.setPosition(position);
	sprite.setOrigin(sprite.getGlobalBounds().width/2,
									 sprite.getGlobalBounds().height/2);
	sprite.rotate(180);
}

bool Enemy::out_of_screen() {
	return bottom() <= 0;
}

void Enemy::update() {
	if(hit_points > 0)
		sprite.move(sf::Vector2f{0, 1});

	explosion.set_position(sprite.getPosition());
}
