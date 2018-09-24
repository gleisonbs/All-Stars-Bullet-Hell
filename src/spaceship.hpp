#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
#include <vector>

#include "bullet.hpp"
#include "animation.hpp"
#include "drawable.hpp"
#include "movable.hpp"

class Spaceship : public Drawable, public Movable {
public:
	Spaceship();
	Spaceship(std::string);
	void shoot();
	int take_hit(int);
	sf::Sprite frame();
//	sf::FloatRect rect() { return sprite.getGlobalBounds(); }
	std::vector<Projectile> projectiles;
	int hit_points, max_hit_points;
	int damage;
	bool exploding {};
	bool destroyed {};
//	sf::Sprite sprite;
	Animation explosion;

protected:
	int shooting_interval;
	sf::Clock timer;
};

#endif //SPACESHIP_HPP
