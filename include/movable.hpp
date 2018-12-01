#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Movable
{
public:
    Movable(sf::Vector2f, sf::Vector2f, sf::Vector2f, double, std::string, double scale);
    void move(bool, bool, bool, bool);

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

protected:
    sf::Vector2f position {0, 0};
    sf::Vector2f maxSpeed {0, 0};

private:
    void accelerate(bool, bool, bool, bool);

    sf::Vector2f acceleration {0, 0};
    sf::Vector2f currentSpeed {0, 0};
    double backingSpeedFactor;
};

#endif // MOVABLE_HPP
