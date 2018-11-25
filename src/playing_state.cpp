#include <iostream>

#include "../include/constants.hpp"
#include "../include/playing_state.hpp"
#include "../include/game_manager.hpp"
#include "../include/garbage_remover.hpp"
#include "../include/resources.hpp"
#include "../include/paused_state.hpp"
#include "../include/main_menu.hpp"

using namespace std;
using namespace sf;

PlayingState::PlayingState() {
	ship_manager.ship_factory.make_player1(Factions::faction2);

	level = Level(1);
}

void PlayingState::draw() {
	GameManager::window->clear(Color::Black);

	level.draw();

	draw_players();
	draw_enemies();

	GameManager::window->display();
}
bool PlayingState::handle_input() {
	if (level.isComplete()) level = Level(level.levelNumber+1);

	Event e;
	while(GameManager::window->pollEvent(e)) {
		if(e.key.code == Keyboard::Key::Escape) {
			return true;
		}
		if(e.key.code == Keyboard::Key::R) {
			level.enemies.clear();
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
	CollisionChecker::check(ship_manager.ship_factory.player1.projectiles, level.enemies);
	CollisionChecker::check(ship_manager.ship_factory.player1, level.enemies);
	GarbageRemover::clean(ship_manager.ship_factory.player1.projectiles);
	GarbageRemover::clean(level.enemies);

	ship_manager.update();
	level.update();
}

void PlayingState::draw_players() {
	GameManager::window->draw(ship_manager.ship_factory.player1.frame());

	ship_manager.ship_factory.player1.update();
	ship_manager.ship_factory.player1.draw();

	for(int i = 0; i < ship_manager.ship_factory.player1.projectiles.size(); ++i)
		GameManager::window->draw(
			ship_manager.ship_factory.player1.projectiles[i].sprite);
}

void PlayingState::draw_enemies() {
	for(int i = 0; i < level.enemies.size(); ++i) {
		GameManager::window->draw(level.enemies[i].frame());
	}
}
