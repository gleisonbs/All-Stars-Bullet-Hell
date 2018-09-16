#include "animation.hpp"
#include "constants.hpp"
#include "resource_manager.hpp"

#include <iostream>

using namespace std;
using namespace sf;

Animation::Animation() { i = 0; }

void Animation::set(const string name, int frame_interval)
{
	i = 0;
	interval = frame_interval;

	sprite.setTexture(ResourceManager::Textures[name]);
	//sprite.setOrigin(sprite.getGlobalBounds().widt, , y_origin);
	sprite.setColor(Color(255, 255, 255, 255));
	sprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
}

void Animation::add_frame(int x, int y, 
						int width, 
						int height) {
	frame_width = width;
	frame_height = height;
	frames.push_back(IntRect(x, y, width, height));
}

Sprite Animation::frame() {
	//cout << timer.getElapsedTime().asMilliseconds() << endl;
	if(timer.getElapsedTime().asMilliseconds() >= interval) {
		timer.restart();
		//cout << timer.getElapsedTime().asMilliseconds() << endl;
		if(i < frames.size()) {
			++i;
		}
		else {
			played = true;
		}
	}

	sprite.setTextureRect(frames[i]);
		
	return sprite;
}

void Animation::set_position(Vector2f v) {
	float x = v.x;
	float y = v.y;
	
	sprite.setPosition({x-frame_width/2,y});
}