#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>

class Level {
public:
	Level() {};
	Level(int);
	void draw();
	void update();
	//getBackground();
	sf::Sprite background;
	bool isComplete() { return complete; }
private:
	bool complete;
	sf::Clock dt, scrollTimer;
	int _levelNumber;
	void moveBackground();
	void loadBackground();
};

#endif // LEVEL_HPP

