#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../include/enemy.hpp"
#include "../include/enemy_waves.hpp"

#include <SFML/Graphics.hpp>

class Level {
public:
	Level() {};
	Level(int);

	void draw();
	void update();

	bool isComplete() { return complete; }

	sf::Sprite background;
	int levelNumber;
	EnemyWaves enemyWaves;
	std::vector<Enemy> enemies;
private:
	void scrollBackground();
	void loadBackground();
	void makeEnemies();

	bool complete = false;
	sf::Clock scrollTimer;
	sf::Clock levelTimer;
};

#endif // LEVEL_HPP

