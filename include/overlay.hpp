#ifndef OVERLAY_HPP
#define OVERLAY_HPP

#include <SFML/Graphics.hpp>

class Overlay {
public:
	void init(int);
	void draw();
	void update(int);
private:
	int maxHealth;
	int currentHealth;
	long currentScore = 0;
	int scoreSize = 6;

	sf::Text txtScore;
	sf::RectangleShape lifebarFilling;
	sf::RectangleShape lifebarFrame;

	void drawScore();
	void drawLifebar();

	void makeScore();
	void makeLifebar();

	std::string getScoreString();
};

#endif //OVERLAY_HPP
