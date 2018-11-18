#include <iostream>

#include "../include/constants.hpp"
#include "../include/game_manager.hpp"
#include "../include/level.hpp"
#include "../include/resources.hpp"

using namespace sf;
using std::string;
using std::to_string;

Level::Level(int levelNumber) {
	_levelNumber = levelNumber;
	loadBackground();
}

void Level::update() {
	moveBackground();
}

void Level::draw() {
	GameManager::window->draw(background);
}

void Level::moveBackground() {
	if (background.getPosition().y >= 0) complete = true;

	if (scrollTimer.getElapsedTime().asMilliseconds() > Background::ScrollIntervalMs) {
		background.move(0, Background::ScrollSpeed);
		scrollTimer.restart();
	}
}

void Level::loadBackground() {
	string bkgImgPath = Background::Images::Level + to_string(_levelNumber);

	background.setTexture(Resources::getTexture(bkgImgPath));
	background.setColor(Color(255, 255, 255, 255));

	int y_pos = -(background.getLocalBounds().height - WINDOW_HEIGHT);
	background.setPosition(0, y_pos);
};
