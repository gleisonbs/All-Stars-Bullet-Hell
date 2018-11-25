#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Projectile {
public:
	Projectile(int, int, int, const std::string&);
	Projectile(const Projectile &b) = default;
	void update();
	void takeHit(int);
	bool isOutOfScreen();
	bool isDestroyed();
	sf::FloatRect rect() { return sprite.getGlobalBounds(); }

	sf::Sprite sprite;
	int damage_;
	int health_ = 1;
private:
	sf::Vector2f speed {0, -20};

	float x() 		 	 		 { return sprite.getPosition().x; }
	float y() 		 	 		 { return sprite.getPosition().y; }
	float width()  	 		 { return rect().width; }
	float height() 	 		 { return rect().height; }
	float left()	 	 		 { return x() - width()/2; }
	float right()	 	 		 { return x() + width()/2; }
	float top()	 	 	 		 { return y() - height()/2; }
	float bottom() 	 		 { return y() + height()/2; }
};

#endif // PROJECTILE_HPP
