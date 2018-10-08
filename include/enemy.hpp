#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

#include "../include/spaceship.hpp"

class Enemy : public Spaceship {
public:
	Enemy(const std::string, const std::string, sf::Vector2f);
	void update();
	bool out_of_screen();
};

#endif // ENEMY_HPP
