#include <cmath>
#include "movable.hpp"

Movable::Movable(sf::Vector2f initialPosition, sf::Vector2f maxSpeed, sf::Vector2f acceleration)
{
    this->position.x = initialPosition.x;
    this->position.y = initialPosition.y;
    this->maxSpeed.x = maxSpeed.x;
    this->maxSpeed.y = maxSpeed.y;
    this->acceleration.x = acceleration.x;
    this->acceleration.y = acceleration.y;
}

void Movable::accelerate(bool goingLeft, bool goingRight, bool goingUp, bool goingDown) {
    //TODO: Check screen boundary
    if (goingLeft and std::abs(currentSpeed.x) < maxSpeed.x)
        currentSpeed.x -= acceleration.x;
    else if (goingRight and std::abs(currentSpeed.x) < maxSpeed.x)
        currentSpeed.x += acceleration.x;
    else {
        if (std::abs(currentSpeed.x) < acceleration.x)
            currentSpeed.x = 0;

        if (currentSpeed.x > 0)
            currentSpeed.x -= acceleration.x;
        else if (currentSpeed.x < 0)
            currentSpeed.x += acceleration.x;
    }

    if (goingDown and std::abs(currentSpeed.y) < maxSpeed.y)
        currentSpeed.y += acceleration.y;
    else if (goingUp and std::abs(currentSpeed.y) < maxSpeed.y)
        currentSpeed.y -= acceleration.y;
    else {
        if (std::abs(currentSpeed.y) < acceleration.y)
            currentSpeed.y = 0;

        if (currentSpeed.y > 0)
            currentSpeed.y -= acceleration.y;
        else if (currentSpeed.y < 0)
            currentSpeed.y += acceleration.y;
    }

    if (currentSpeed.x < maxSpeed.x and goingRight)
        currentSpeed.y += acceleration.y;
}

void Movable::move(bool goingLeft, bool goingRight, bool goingUp, bool goingDown) {
    accelerate(goingLeft, goingRight, goingUp, goingDown);

    position.x += currentSpeed.x;
    position.y += currentSpeed.y;
}
