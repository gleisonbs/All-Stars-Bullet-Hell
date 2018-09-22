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

class Spaceship : public Drawable {
public:
	Spaceship();
	Spaceship(std::string);
	void shoot();
	int take_hit(int);
	sf::Sprite frame();
//	sf::FloatRect rect() { return sprite.getGlobalBounds(); }
	std::vector<Bullet> bullets;
	int hit_points, max_hit_points;
	int damage;
	bool exploding {};
	bool destroyed {};
//	sf::Sprite sprite;
	Animation explosion;

protected:
	int shooting_interval;
	sf::Clock timer;
	sf::Vector2f max_speed {0, 0};
	sf::Vector2f current_speed {0, 0};
};

#endif //SPACESHIP_HPP
