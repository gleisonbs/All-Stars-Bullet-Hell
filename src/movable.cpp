#include <cmath>
#include <iostream>

#include "../include/constants.hpp"
#include "../include/movable.hpp"
#include "../include/resources.hpp"

using namespace std;

Movable::Movable(sf::Vector2f initialPosition, sf::Vector2f maxSpeed, sf::Vector2f acceleration, double backingSpeedFactor, string textureKey, double scale)
{
    this->position.x = initialPosition.x;
    this->position.y = initialPosition.y;
    this->maxSpeed.x = maxSpeed.x;
    this->maxSpeed.y = maxSpeed.y;
    this->acceleration.x = acceleration.x;
    this->acceleration.y = acceleration.y;
    this->backingSpeedFactor = backingSpeedFactor;

    sprite.setTexture(Resources::getTexture(textureKey));
    sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    sprite.setColor(sf::Color(255, 255, 255, 255));
    sprite.setPosition(initialPosition.x, initialPosition.y);
    sprite.scale(scale, scale);
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

    if (goingDown and std::abs(currentSpeed.y) < (int)(maxSpeed.y * backingSpeedFactor))
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
}

void Movable::move(bool goingLeft, bool goingRight, bool goingUp, bool goingDown) {
    accelerate(goingLeft, goingRight, goingUp, goingDown);

	if ((goingLeft and left() > 0) or (goingRight and right() < WINDOW_WIDTH))
    	position.x += currentSpeed.x;

	if ((goingUp and top() > 0) or (goingDown and bottom() < WINDOW_HEIGHT))
    	position.y += currentSpeed.y;
}
