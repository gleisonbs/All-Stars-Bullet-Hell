#ifndef SHIP_MANAGER_HPP
#define SHIP_MANAGER_HPP

#include "enemy.hpp"
#include "ship_factory.hpp"
#include "players.hpp"
#include <vector>

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