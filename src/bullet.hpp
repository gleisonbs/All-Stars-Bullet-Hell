#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Bullet {
public:
	Bullet(int, int, int);
	Bullet(const Bullet &b) = default;
	void update();
	sf::FloatRect rect() { return sprite.getGlobalBounds(); }
	sf::Sprite sprite;
	bool out_of_screen;
	int damage;
private:
	//sf::Texture texture;
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

#endif // BULLET_HPP