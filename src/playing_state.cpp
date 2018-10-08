#include <iostream>

#include "../include/constants.hpp"
#include "../include/playing_state.hpp"
#include "../include/game_manager.hpp"
#include "../include/resources.hpp"
#include "../include/paused_state.hpp"
#include "../include/main_menu.hpp"

using namespace std;
using namespace sf;

PlayingState::PlayingState() {
	level_cleared = false;
	for(int i = 0; i < STAR_COUNT; ++i) stars.push_back(Star());
	//ship_manager = unique_ptr<ShipManager>(new ShipManager);
	ship_manager.ship_factory.make_player1(Races::race2);
	//background = std::unique_ptr<sf::Sprite>(new sf::Sprite);

	background.setTexture(Resources::getTexture("sprites_backgrounds_lvl_1"));
	background.setColor(Color(255, 255, 255, 255));
	background.setPosition(0, -6940);
}

void PlayingState::draw() {
	GameManager::window->clear(Color::Black);

	if (background.getPosition().y < 0) {
		if (scroll_timer.getElapsedTime().asMilliseconds() > 5) {
			background.move(0, 5);
			scroll_timer.restart();
		}
	}
	else level_cleared = true;

	GameManager::window->draw(background);
	draw_players();
	draw_enemies();

	GameManager::window->display();
}
bool PlayingState::handle_input() {

	if (level_cleared) return true;

	Event e;
	while(GameManager::window->pollEvent(e)) {
		if(e.key.code == Keyboard::Key::Escape) {
			return true;
		}
		if(e.key.code == Keyboard::Key::R) {
			ship_manager.ship_factory.enemies.clear();
		}
		if(e.key.code == Keyboard::Key::P) {
			if(GameManager::pause_timer.getElapsedTime().asMilliseconds() >= 250) {
				GameManager::pause_timer.restart();
				GameManager::push_state(new PausedState());
			}
		}
	}

	return false;
}

void PlayingState::update() {
	ship_manager.update();
	int seconds = dt.getElapsedTime().asSeconds();
	if((seconds % 5 == 0) and seconds > 3) {
		ship_manager.make_wave(1);
		++ship_manager.ship_factory.waves_made;
		dt.restart();
	}
}

void PlayingState::draw_players() {
	GameManager::window->draw(ship_manager.ship_factory.player1.frame());
	ship_manager.ship_factory.player1.draw_lifebar();
	ship_manager.ship_factory.player1.draw_score();

	for(int i = 0; i < ship_manager.ship_factory.player1.projectiles.size(); ++i)
		GameManager::window->draw(
			ship_manager.ship_factory.player1.projectiles[i].sprite);
}

void PlayingState::draw_enemies() {
	for(int i = 0; i < ship_manager.ship_factory.enemies.size(); ++i) {
		GameManager::window->draw(ship_manager.ship_factory.enemies[i].frame());
	}
}
