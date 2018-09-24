#ifndef STAR_HPP
#define STAR_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Star {
public:
	Star();
	void update();
	bool should_be_deleted = false;
	sf::CircleShape shape;
private:
	sf::Vector2f speed;
};

#endif //STAR_HPP
