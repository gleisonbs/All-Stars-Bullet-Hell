#ifndef SHIP_FACTORY_HPP
#define SHIP_FACTORY_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
#include <vector>

#include "enemy.hpp"
#include "players.hpp"

class ShipFactory {
public:
	ShipFactory();
	void update();
	void make_player1(std::string);
	void make_wave1();
	void make_wave2();
	int waves_made = 0;
	std::vector<Enemy> enemies;
	Player player1;
	int wave_counter = 0;

private:
	sf::Clock timer;
};

#endif // SHIP_FACTORY_HPP
