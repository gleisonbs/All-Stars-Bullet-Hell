#include <iostream>

#include "../include/game_manager.hpp"
#include "../include/overlay.hpp"

using namespace sf;
using namespace std;

void Overlay::init(int maxHealth) {
	this->maxHealth = maxHealth;
	currentHealth = maxHealth;

	makeLifebar();
	makeScore();
}

void Overlay::update(int currentHealth) {

}

void Overlay::draw() {

}

void Overlay::makeScore() {
	string scoreStr = to_string(currentScore);
	scoreStr.insert(scoreStr.begin(), scoreSize - scoreStr.size(), '0');

	txtScore.setString(scoreStr);
	txtScore.setCharacterSize(48);
	txtScore.setPosition(350, 50);
}

void Overlay::makeLifebar() {
	lifebarFilling.setSize(Vector2f(200, 50));
	//lifebarFilling.setSize(Vector2f(hit_points, 50));
	lifebarFilling.setOutlineThickness(0);
	lifebarFilling.setFillColor(Color::Green);
	lifebarFilling.setPosition(50, 50);

	lifebarFrame.setSize(Vector2f(200, 50));
	//lifebarFrame.setSize(Vector2f(max_hit_points, 50));
	lifebarFrame.setOutlineColor(Color::White);
	lifebarFrame.setOutlineThickness(5);
	lifebarFrame.setFillColor(Color(255, 255, 255, 0));
	lifebarFrame.setPosition(50, 50);
}

void Overlay::drawScore() {

}

void Overlay::drawLifebar() {

}

