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
	int levelNumber;
private:
	bool complete = false;
	sf::Clock dt, scrollTimer;
	void scrollBackground();
	void loadBackground();
};

#endif // LEVEL_HPP

