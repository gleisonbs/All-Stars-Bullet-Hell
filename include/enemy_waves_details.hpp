#ifndef ENEMY_WAVES_DETAILS_HPP
#define ENEMY_WAVES_DETAILS_HPP

#include <vector>

#include <SFML/Graphics.hpp>

class EnemyWaveDetails {
public:
	EnemyWaveDetails() {};
	EnemyWaveDetails(std::string, int, std::vector<sf::Vector2f>);
	std::string _faction;
	int _numberOfEnemies;
	std::vector<sf::Vector2f> _positions;
};

#endif //ENEMY_WAVES_DETAILS_HPP
