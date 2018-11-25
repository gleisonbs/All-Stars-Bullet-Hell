#include <iostream>

#include "../include/constants.hpp"
#include "../include/game_manager.hpp"
#include "../include/level.hpp"
#include "../include/resources.hpp"

using namespace sf;
using std::string;
using std::to_string;
using std::vector;

Level::Level(int levelNumber) {
	this->levelNumber = levelNumber;
	enemyWaves = EnemyWaves(levelNumber-1);
	loadBackground();
}

void Level::update() {
	scrollBackground();
	vector<Enemy> newEnemyWave = enemyWaves.getEnemyWave(levelTimer.getElapsedTime().asSeconds());
	if (newEnemyWave.size() > 0) {
		enemies.reserve(enemies.size() + newEnemyWave.size());
		enemies.insert(enemies.end(), newEnemyWave.begin(), newEnemyWave.end());
	}
	for (auto &enemy : enemies)
		enemy.update();
}

void Level::draw() {
	GameManager::window->draw(background);
}

void Level::scrollBackground() {
	if (background.getPosition().y >= 0) complete = true;

	if (scrollTimer.getElapsedTime().asMilliseconds() > Background::ScrollIntervalMs) {
		background.move(0, Background::ScrollSpeed);
		scrollTimer.restart();
	}
}

void Level::loadBackground() {
	string bkgImgPath = Background::Images::Level + to_string(levelNumber);

	background.setTexture(Resources::getTexture(bkgImgPath));
	background.setColor(Color(255, 255, 255, 255));

	int y_pos = -(background.getLocalBounds().height - WINDOW_HEIGHT);
	background.setPosition(0, y_pos);
};

void makeEnemies() {

}
