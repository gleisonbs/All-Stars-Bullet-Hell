#include "../include/animation.hpp"
#include "../include/constants.hpp"
#include "../include/resources.hpp"

#include <iostream>

using namespace std;
using namespace sf;

Animation::Animation() { i = 0; }

void Animation::set(const string textureKey, int frameInterval)
{
	i = 0;
	_frameInterval = frameInterval;

	sprite.setTexture(Resources::getTexture(textureKey));
	sprite.setColor(Color(255, 255, 255, 255));
	sprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
}

void Animation::add_frame(int x, int y,
						int width,
						int height) {
	frame_width = width;
	frame_height = height;
	frames.push_back(IntRect(x, y, width, height));

	sprite.setTextureRect(frames[0]);
}

Sprite Animation::frame() {
	if(timer.getElapsedTime().asMilliseconds() >= _frameInterval) {
		i++;

		if(i >= frames.size()) {
			if (_shouldLoop) reset();
			else played = true;
		}

		sprite.setTextureRect(frames[i]);
		timer.restart();
	}

	return sprite;
}

void Animation::setPosition(Vector2f v) {
	float x = v.x;
	float y = v.y;

	sprite.setPosition({ x, y });
}

void Animation::reset() {
	i = 0;
	played = false;
}

void Animation::setScale(double scale) {
	sprite.scale(scale, scale);
}

void Animation::setOrigin(int x, int y)
{
	sprite.setOrigin(x, y);
}
