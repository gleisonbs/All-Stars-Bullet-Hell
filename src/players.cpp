#include <iostream>
#include <string>

#include "../include/constants.hpp"
#include "../include/players.hpp"
#include "../include/game_manager.hpp"
#include "../include/resources.hpp"

using namespace std;
using namespace sf;


Player::Player(string faction) : Spaceship(faction + "_2", faction) {
	txt_score.setFont(Resources::getFont(Fonts::Score));
	overlay.init(300);
}
Player::Player() : Spaceship(Factions::faction2 + "_1", Factions::faction2) {
	txt_score.setFont(Resources::getFont(Fonts::Score));
	overlay.init(300);
}

void Player::draw() {
	overlay.draw();
}

void Player::update() {
	explosion.set_position(sprite.getPosition());
	if(invulnerable_timer.getElapsedTime().asMilliseconds() > 1500) {
		invulnerable = false;
		sprite.setColor(Color(255, 255, 255, 255));
	}

	bool goingLeft = Keyboard::isKeyPressed(Keyboard::Key::Left);
	bool goingRight = Keyboard::isKeyPressed(Keyboard::Key::Right);
	if (goingLeft and goingRight) { goingLeft = false; goingRight = false; }

	bool goingUp = Keyboard::isKeyPressed(Keyboard::Key::Up);
	bool goingDown = Keyboard::isKeyPressed(Keyboard::Key::Down);
	if(goingUp and goingDown) { goingUp = false; goingDown = false; }

    move(goingLeft, goingRight, goingUp, goingDown);
    setPosition(this->position);
	shoot();

	for(int i = 0; i < projectiles.size(); ++i) {
		projectiles[i].update();
		if(projectiles[i].isOutOfScreen()) {
			projectiles.erase(projectiles.begin()+i);
		}
	}

	if(explosion.played) isDestroyed_ = true;
}

int Player::take_hit(int dmge) {
	if(invulnerable_timer.getElapsedTime().asSeconds() < 2)
		return 0;
	sprite.setColor(Color(255, 255, 255, 100));
	invulnerable = true;
	invulnerable_timer.restart();
	hit_points -= dmge;
	if(hit_points <= 0) {
		hit_points = 0;
		isExploding_ = true;
		explosion.set_position(sprite.getPosition());
	}
	return hit_points;
}

