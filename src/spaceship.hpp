#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
#include <vector>

#include "bullet.hpp"
#include "animation.hpp"
 
class Spaceship {
public:
	Spaceship();
	Spaceship(std::string);
	void shoot();
	int take_hit(int);
	sf::Sprite frame();
	sf::FloatRect rect() { return sprite.getGlobalBounds(); }
	std::vector<Bullet> bullets;
	int hit_points, max_hit_points;
	int damage;
	bool exploding {};
	bool destroyed {};
	sf::Sprite sprite;
	Animation explosion;

	float x() 		 	 		 { return sprite.getPosition().x; }
	float y() 		 	 		 { return sprite.getPosition().y; }
	float width()  	 		 { return rect().width; }
	float height() 	 		 { return rect().height; }
	float left()	 	 		 { return x() - width()/2; }
	float right()	 	 		 { return x() + width()/2; }
	float top()	 	 	 		 { return y() - height()/2; }
	float bottom() 	 		 { return y() + height()/2; }

protected:
	int shooting_interval;
	sf::Clock timer;
	sf::Vector2f max_speed {0, 0};
	sf::Vector2f current_speed {0, 0};
};

#endif //SPACESHIP_HPP