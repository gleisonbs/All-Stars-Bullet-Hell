#include <cstdlib>
#include <iostream>

#include "constants.hpp"
#include "star.hpp"

using namespace std;
using namespace sf;

Star::Star() {
	speed.x = 0;
	speed.y = rand() % 4 + 1;

	int x_pos = rand() % WINDOW_WIDTH;
	int y_pos = -(rand() % WINDOW_HEIGHT);

	shape.setPosition(x_pos, y_pos);
	shape.setRadius(1.f+(speed.y/4.f));
	shape.setFillColor(Color::White);
}

void Star::update() {
	shape.move(speed);
	if (shape.getPosition().y >= WINDOW_HEIGHT) 
		delete_star = true;
}