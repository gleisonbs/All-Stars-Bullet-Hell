#ifndef SHIP_MANAGER_HPP
#define SHIP_MANAGER_HPP

#include <vector>

#include "../include/enemy.hpp"
#include "../include/ship_factory.hpp"
#include "../include/players.hpp"

class ShipManager
{
public:
	void update();
	void make_wave(int);
	std::vector<Enemy> enemies();
	void check_collisions();

	ShipFactory ship_factory;
};

#endif // SHIP_MANAGER_HPP
