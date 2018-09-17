#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <map>

#include "constants.hpp"
#include "game_manager.hpp"
#include "spaceship.hpp"
#include "ships.hpp"
#include "resource_manager.hpp"

using namespace std;
using namespace sf;

Spaceship::Spaceship() {}

Spaceship::Spaceship(string race) {
	//texture.loadFromFile(IMAGES_SHIPS + race + "/ship.png");
	sprite.setTexture(ResourceManager::Textures[race]);
	sprite.setOrigin(sprite.getLocalBounds().width/2,
									 sprite.getLocalBounds().height/2);
	sprite.setColor(Color(255, 255, 255, 255));
	sprite.setPosition(WINDOW_WIDTH/2,
		WINDOW_HEIGHT-(sprite.getLocalBounds().height/2)-30);

	sprite.scale(0.6, 0.6);

	max_speed = Ships::details[race]->speed;
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
	if(is_shooting) {
		bullets.push_back(Bullet(sprite.getPosition().x,
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
