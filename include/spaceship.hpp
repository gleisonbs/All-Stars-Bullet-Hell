#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <memory>
#include <string>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../include/projectile.hpp"
#include "../include/animation.hpp"
#include "../include/movable.hpp"

class Spaceship : public Movable {
public:
	Spaceship();
	Spaceship(const std::string, const std::string, double=0.3);
	void shoot();
	int takeHit(int);
	sf::Sprite frame();
	bool isExploding();
	bool isDestroyed();

	std::vector<Projectile> projectiles;
	int hit_points, max_hit_points;
	int damage;
	bool isExploding_ = false;
	bool isDestroyed_ = false;
	Animation explosion;
	Animation movingUpAnimation;

protected:
	bool goingUp = false, goingDown = false, goingLeft = false, goingRight = false;
	int shooting_interval;
	std::string _faction;
	sf::Clock timer;
};

#endif //SPACESHIP_HPP
