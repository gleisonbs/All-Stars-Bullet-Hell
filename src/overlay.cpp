#include <iostream>

#include "../include/constants.hpp"
#include "../include/game_manager.hpp"
#include "../include/overlay.hpp"
#include "../include/resources.hpp"

using namespace sf;
using namespace std;

void Overlay::init(int maxHealth) {
	this->maxHealth = maxHealth;
	currentHealth = maxHealth;

	makeLifebar();
	makeScore();
}

void Overlay::update(int currentHealth) {
	currentScore++;
	string scoreStr = getScoreString();
	txtScore.setString(scoreStr);
}

void Overlay::draw() {
	drawLifebar();
	drawScore();
}

void Overlay::makeScore() {
	string scoreStr = getScoreString();
	txtScore.setString(scoreStr);
	txtScore.setFont(Resources::getFont(Fonts::Score));
	txtScore.setCharacterSize(48);
	txtScore.setPosition(350, 50);
}

void Overlay::makeLifebar() {
	lifebarFilling.setSize(Vector2f(300, 50));
	lifebarFilling.setOutlineThickness(0);
	lifebarFilling.setFillColor(Color::Green);
	lifebarFilling.setPosition(50, 50);

	lifebarFrame.setSize(Vector2f(300, 50));
	lifebarFrame.setOutlineColor(Color::White);
	lifebarFrame.setOutlineThickness(5);
	lifebarFrame.setFillColor(Color(255, 255, 255, 0));
	lifebarFrame.setPosition(50, 50);
}

void Overlay::drawScore() {
	GameManager::window->draw(txtScore);
}

void Overlay::drawLifebar() {
	GameManager::window->draw(lifebarFilling);
	GameManager::window->draw(lifebarFrame);
}

string Overlay::getScoreString() {
	string scoreStr = to_string(currentScore);
	scoreStr.insert(scoreStr.begin(), scoreSize - scoreStr.size(), '0');

	return scoreStr;
}

