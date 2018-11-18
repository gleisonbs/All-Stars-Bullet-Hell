#include "../include/overlay.hpp"

using namespace sf;
using namespace std;

void Overlay::makeScore() {
	string score_str = string(6, '0');
	txt_score.setString(score_str);
	txt_score.setCharacterSize(48);
	txt_score.setPosition(350, 50);
}

void Overlay::makeLifebar() {
	RectangleShape lifebarFilling;
	lifebarFilling.setSize(Vector2f(200, 50));
	//lifebarFilling.setSize(Vector2f(hit_points, 50));
	lifebarFilling.setOutlineThickness(0);
	lifebarFilling.setFillColor(Color::Green);
	lifebarFilling.setPosition(50, 50);

	RectangleShape lifebarFrame;
	lifebarFrame.setSize(Vector2f(200, 50));
	//lifebarFrame.setSize(Vector2f(max_hit_points, 50));
	lifebarFrame.setOutlineColor(Color::White);
	lifebarFrame.setOutlineThickness(5);
	lifebarFrame.setFillColor(Color(255, 255, 255, 0));
	lifebarFrame.setPosition(50, 50);
}
