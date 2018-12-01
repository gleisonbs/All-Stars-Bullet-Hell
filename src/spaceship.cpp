#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <map>

#include "../include/constants.hpp"
#include "../include/game_manager.hpp"
#include "../include/spaceship.hpp"
#include "../include/ships.hpp"
#include "../include/resources.hpp"

using namespace std;
using namespace sf;

Spaceship::Spaceship(const string faction, const string shipCode, double scale) :
    Movable(sf::Vector2f({500, 900}),
	Ships::details[faction]->max_speed,
	Ships::details[faction]->acceleration,
	Ships::details[faction]->backingSpeedFactor,
	faction + "_" + shipCode, scale) {

	this->_faction = faction;

	hit_points = Ships::details[faction]->hit_points;
	max_hit_points = hit_points;
	damage = Ships::details[faction]->body_damage;
	shooting_interval = Ships::details[faction]->shooting_interval;

	explosion.set(faction + "_explosions_explosion", 60);
	for(int x = 0; x < 16; ++x)
		explosion.add_frame(x*128, 0, 128, 128);
}

void Spaceship::shoot() {
	if(timer.getElapsedTime().asMilliseconds() <= shooting_interval)
		return;

	bool is_shooting = Keyboard::isKeyPressed(Keyboard::Key::Space);
	if(is_shooting) {
		projectiles.push_back(Projectile(sprite.getPosition().x,
			top(), damage, Factions::faction2));

		timer.restart();
	}
}

int Spaceship::takeHit(int dmge) {
	hit_points -= dmge;
	if(hit_points <= 0) {
		hit_points = 0;
		isExploding_ = true;
		explosion.set_position(sprite.getPosition());
	}
	return hit_points;
}

Sprite Spaceship::frame() {
	if(isExploding_)
		return explosion.frame();
	return sprite;
}

bool Spaceship::isExploding() {
	return isExploding_;
}

bool Spaceship::isDestroyed() {
	return isDestroyed_;
}
