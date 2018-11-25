#include <iostream>

#include "../include/ship_manager.hpp"

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

}
