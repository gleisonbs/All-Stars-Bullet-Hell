#include "constants.hpp"
#include "players.hpp"
#include "game_manager.hpp"
#include "resource_manager.hpp"

#include <iostream>
#include <string>

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

	sprite.move(current_speed);
	bool going_left = Keyboard::isKeyPressed(Keyboard::Key::Left);
	bool going_right = Keyboard::isKeyPressed(Keyboard::Key::Right);
	if(going_left and left() >= 0)
		current_speed.x = -max_speed.x;
	else if(going_right and right() <= WINDOW_WIDTH)
		current_speed.x = max_speed.x;
	else
		current_speed.x = 0;

	bool going_top = Keyboard::isKeyPressed(Keyboard::Key::Up);
	bool going_bottom = Keyboard::isKeyPressed(Keyboard::Key::Down);
	if(going_top and top() >= 0)
		current_speed.y = -max_speed.y;
	else if(going_bottom and bottom() <= WINDOW_HEIGHT)
		current_speed.y = max_speed.y;
	else
		current_speed.y = 0;

	shoot();

	for(int i = 0; i < bullets.size(); ++i) {
		bullets[i].update();
		if(bullets[i].out_of_screen) {
            cout << "ofs" << endl;
			bullets.erase(bullets.begin()+i);
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
	txt_score.setFont(ResourceManager::Fonts["SpaceAge"]);

	string score_str = to_string(0);
	while(score_str.size() < 6) score_str = "0" + score_str;
	txt_score.setString(score_str);

	txt_score.setCharacterSize(48);
	txt_score.setPosition(350, 50);

	GameManager::window->draw(txt_score);
}
