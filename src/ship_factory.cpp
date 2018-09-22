#include "ship_factory.hpp"
#include "constants.hpp"

#include <iostream>

using namespace std;
using namespace sf;

ShipFactory::ShipFactory() {}

void ShipFactory::make_player1(string race) {
	player1 = Player(race);
}

void ShipFactory::update() {
	player1.update();
	for(int i = 0; i < enemies.size(); ++i) {
		enemies[i].update();
		if(enemies[i].top() > WINDOW_WIDTH) {
			enemies.erase(enemies.begin() + i);
		}
	}
}

void ShipFactory::make_wave1() {
	enemies.push_back(Enemy(Races::race5, Vector2f(WINDOW_WIDTH/2, 0)));
	enemies.push_back(Enemy(Races::race5, Vector2f(WINDOW_WIDTH/3, -300)));
	enemies.push_back(Enemy(Races::race5, Vector2f(2*(WINDOW_WIDTH/3), -300)));
	enemies.push_back(Enemy(Races::race5, Vector2f(WINDOW_WIDTH/6, -600)));
	enemies.push_back(Enemy(Races::race5, Vector2f(5*WINDOW_WIDTH/6, -600)));
}

void ShipFactory::make_wave2() {
	// enemies.push_back(Enemy("Alien", Vector2f(3*(WINDOW_WIDTH/4), -100)));
	// enemies.push_back(Enemy("Alien", Vector2f(3*(WINDOW_WIDTH/4), -500)));
	// enemies.push_back(Enemy("Alien", Vector2f(3*(WINDOW_WIDTH/4), -1100)));
}
