#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include <SFML/Graphics.hpp>

#include <string>

#include "../include/overlay.hpp"
#include "../include/spaceship.hpp"

class Player : public Spaceship {
public:
	Player();
	Player(std::string);
	bool invulnerable {};
	sf::Clock invulnerable_timer;
	sf::Text txt_score;

	void draw();

	int take_hit(int);
	void add_score(int);
	void update();
private:
	Overlay overlay;
};

#endif // PLAYERS_HPP
