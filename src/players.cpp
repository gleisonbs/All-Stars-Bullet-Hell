#include <iostream>
#include <string>

#include "../include/constants.hpp"
#include "../include/players.hpp"
#include "../include/game_manager.hpp"
#include "../include/resources.hpp"

using namespace std;
using namespace sf;


Player::Player(string faction) : Spaceship(faction, ShipCodes::ship1) {
	txt_score.setFont(Resources::getFont(Fonts::Score));
	overlay.init(300);
}
Player::Player() : Spaceship(Factions::faction3, ShipCodes::ship1) {
	txt_score.setFont(Resources::getFont(Fonts::Score));
	overlay.init(300);
}

void Player::draw() {
	overlay.draw();
}

void Player::update() {
	for(auto &projectile : projectiles)
		projectile.update();

	explosion.setPosition(sprite.getPosition());

	if (isDestroyed()) return;


	if(invulnerable_timer.getElapsedTime().asMilliseconds() > 1500) {
		invulnerable = false;
		sprite.setColor(Color(255, 255, 255, 255));
	}

	goingLeft = Keyboard::isKeyPressed(Keyboard::Key::Left);
	goingRight = Keyboard::isKeyPressed(Keyboard::Key::Right);
	if (goingLeft and goingRight) { goingLeft = false; goingRight = false; }

	goingUp = Keyboard::isKeyPressed(Keyboard::Key::Up);
	goingDown = Keyboard::isKeyPressed(Keyboard::Key::Down);
	if(goingUp and goingDown) { goingUp = false; goingDown = false; }

	if (not isExploding()) {
	    move(goingLeft, goingRight, goingUp, goingDown);
		shoot();
	}

    setPosition(this->position);

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
	}
	return hit_points;
}

