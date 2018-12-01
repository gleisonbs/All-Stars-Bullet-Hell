#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class Drawable {
public:
    Drawable() {};
    Drawable(std::string, int, int, double);
    sf::Sprite frame();
    void setPosition(sf::Vector2f position) { sprite.setPosition(position); }

    sf::FloatRect rect() { return sprite.getGlobalBounds(); }

    float x()       { return sprite.getPosition().x; }
	float y()       { return sprite.getPosition().y; }
	float width()   { return rect().width; }
	float height()  { return rect().height; }
	float left()    { return x() - width()/2; }
	float right()   { return x() + width()/2; }
	float top()     { return y() - height()/2; }
	float bottom()  { return y() + height()/2; }

    sf::Sprite sprite;
    sf::Texture texture;
};

#endif // DRAWABLE_HPP
