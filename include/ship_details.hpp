#ifndef SHIP_DETAILS_HPP
#define SHIP_DETAILS_HPP

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

struct ShipDetails
{
	ShipDetails(int shooting_interval, int hit_points, int body_damage, sf::Vector2f max_speed,
		sf::Vector2f acceleration, double backingSpeedFactor) {
		this->shooting_interval = shooting_interval;
		this->hit_points = hit_points;
		this->body_damage = body_damage;
		this->acceleration = acceleration;
		this->max_speed = max_speed;
		this->backingSpeedFactor = backingSpeedFactor;
	};

	int shooting_interval;
	int hit_points;
	int body_damage;
	double backingSpeedFactor;
	sf::Vector2f max_speed;
	sf::Vector2f acceleration;

};

#endif // SHIP_DETAILS_HPP
