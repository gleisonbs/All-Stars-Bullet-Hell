#include <iostream>
#include <string>

#include "../include/constants.hpp"
#include "../include/players.hpp"
#include "../include/game_manager.hpp"
#include "../include/resources.hpp"

using namespace std;
using namespace sf;


Player::Player(string race) : Spaceship(race) {}
Player::Player() : Spaceship("faction2") {}

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
		if(projectiles[i].out_of_screen) {
            cout << "ofs" << endl;
			projectiles.erase(projectiles.begin()+i);
		}
	}

	if(explosion.played) destroyed = true;
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
		exploding = true;
		explosion.set_position(sprite.getPosition());
	}
	return hit_points;
}

void Player::draw_lifebar() {

	RectangleShape in_rec;
	in_rec.setSize(Vector2f(hit_points, 50));
	in_rec.setOutlineThickness(0);
	in_rec.setFillColor(Color::Green);
	in_rec.setPosition(50, 50);
	GameManager::window->draw(in_rec);

	RectangleShape out_rec;
	out_rec.setSize(Vector2f(max_hit_points, 50));
	out_rec.setOutlineColor(Color::White);
	out_rec.setOutlineThickness(5);
	out_rec.setFillColor(Color(255, 255, 255, 0));
	out_rec.setPosition(50, 50);
	GameManager::window->draw(out_rec);

}

void Player::draw_score() {
	sf::Text txt_score;
	txt_score.setFont(Resources::Fonts["SpaceAge"]);

	string score_str = to_string(0);
	while(score_str.size() < 6) score_str = "0" + score_str;
	txt_score.setString(score_str);

	txt_score.setCharacterSize(48);
	txt_score.setPosition(350, 50);

	GameManager::window->draw(txt_score);
}
