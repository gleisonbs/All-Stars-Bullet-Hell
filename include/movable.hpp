#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Movable
{
public:
    Movable(sf::Vector2f, sf::Vector2f, sf::Vector2f, double);
    void move(bool, bool, bool, bool);

protected:
    sf::Vector2f position {0, 0};

private:
    void accelerate(bool, bool, bool, bool);

    sf::Vector2f acceleration {0, 0};
    sf::Vector2f currentSpeed {0, 0};
    sf::Vector2f maxSpeed {0, 0};
    double backingSpeedFactor;
};

#endif // MOVABLE_HPP
