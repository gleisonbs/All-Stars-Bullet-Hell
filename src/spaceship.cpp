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

Spaceship::Spaceship(const string textureKey, const string faction) :
    Drawable(textureKey, 500, 900, 0.3, 0.3),
    Movable(sf::Vector2f({500, 900}), sf::Vector2f({20, 20}), Ships::details[faction]->acceleration, Ships::details[faction]->backingSpeedFactor) {

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
	cout << is_shooting << endl;
	if(is_shooting) {
		projectiles.push_back(Projectile(sprite.getPosition().x,
			top(), damage, Factions::faction2));

		timer.restart();
	}
}

int Spaceship::take_hit(int dmge) {
	hit_points -= dmge;
	if(hit_points <= 0) {
		hit_points = 0;
		exploding = true;
		explosion.set_position(sprite.getPosition());
	}
	return hit_points;
}

Sprite Spaceship::frame() {
	if(exploding)
		return explosion.frame();
	return sprite;
}
