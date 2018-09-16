#include "ship_manager.hpp"
#include <iostream>
using namespace std;

void ShipManager::update() {
	ship_factory.update();
	check_collisions();
}

vector<Enemy> ShipManager::enemies() {
	return ship_factory.enemies;
}

void ShipManager::make_wave(int wave_number) {
	switch(wave_number) {
		case 1: ship_factory.make_wave1(); break;
		case 2: ship_factory.make_wave2(); break;
	}
}

void ShipManager::check_collisions() {
	if(not ship_factory.player1.invulnerable) {
		for(int i = 0; i < ship_factory.enemies.size(); ++i) {
			if(ship_factory.enemies[i].exploding) continue;
			if(ship_factory.player1.rect().intersects(ship_factory.enemies[i].rect())) {
				ship_factory.player1.take_hit(90);
			}
		}
	}

	for(int i = 0; i < ship_factory.enemies.size(); ++i) {
		for(int j = 0; j < ship_factory.player1.bullets.size(); ++j) {
			if(ship_factory.enemies[i].out_of_screen() or 
				 ship_factory.enemies[i].destroyed or 
				 ship_factory.enemies[i].exploding)
				continue;

			if(ship_factory.player1.bullets[j].rect().intersects(ship_factory.enemies[i].rect())) {
				ship_factory.enemies[i].take_hit(ship_factory.player1.bullets[j].damage);
				ship_factory.player1.bullets.erase(ship_factory.player1.bullets.begin()+j);
			}
		}
	}
}
