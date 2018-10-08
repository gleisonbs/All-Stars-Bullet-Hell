#ifndef SHIP_DETAILS_HPP
#define SHIP_DETAILS_HPP

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

struct ShipDetails
{
	ShipDetails(int shooting_interval, int hit_points, int damage, sf::Vector2f max_speed, double backingSpeedFactor) {
		this->shooting_interval = shooting_interval;
		this->hit_points = hit_points;
		this->damage = damage;
		this->max_speed = max_speed;
		this->backingSpeedFactor = backingSpeedFactor;
	};

	int shooting_interval;
	int hit_points;
	int damage;
	double backingSpeedFactor;
	sf::Vector2f max_speed;

};

#endif // SHIP_DETAILS_HPP
