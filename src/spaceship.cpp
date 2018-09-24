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

Spaceship::Spaceship(string race) :
    Drawable(race, 500, 900, 0.6, 0.6),
    Movable(sf::Vector2f({500, 900}), sf::Vector2f({20, 20}), sf::Vector2f({20, 20}) ) {

	hit_points = Ships::details[race]->hit_points;
	max_hit_points = hit_points;
	damage = Ships::details[race]->damage;
	shooting_interval = Ships::details[race]->shooting_interval;

	explosion.set("Explosion", 60);
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
									top(), damage));

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
