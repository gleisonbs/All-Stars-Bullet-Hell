#ifndef SHIP_DETAILS_HPP
#define SHIP_DETAILS_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

struct ShipDetails
{
	ShipDetails(int shoot_int, int hp, int dmge, sf::Vector2f max_speed) {
		shooting_interval = shoot_int;
		hit_points = hp;
		damage = dmge;
		speed = max_speed;
	};

	int shooting_interval;
	int hit_points;
	int damage;
	sf::Vector2f speed;
};

#endif // SHIP_DETAILS_HPP