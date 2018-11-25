#ifndef ENEMY_WAVES_DETAILS_HPP
#define ENEMY_WAVES_DETAILS_HPP

#include <vector>

#include <SFML/Graphics.hpp>

class EnemyWaveDetails {
public:
	EnemyWaveDetails() {};
	EnemyWaveDetails(std::string, std::string, int, std::vector<sf::Vector2f>);
	std::string faction_;
	std::string shipCode_;
	int numberOfEnemies_;
	std::vector<sf::Vector2f> positions_;
};

#endif //ENEMY_WAVES_DETAILS_HPP
