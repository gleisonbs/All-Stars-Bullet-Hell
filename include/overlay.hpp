#ifndef OVERLAY_HPP
#define OVERLAY_HPP

#include <SFML/Graphics.hpp>

class Overlay {
public:
	void init();
	void draw();
	void update();
private:
	sf::Text txt_score;
	sf::RectangleShape lifebarFilling;
	sf::RectangleShape lifebarFrame;

	void drawScore();
	void drawLifebar();

	void makeScore();
	void makeLifebar();
};

#endif //OVERLAY_HPP
