#ifndef ENEMY_WAVES_HPP
#define ENEMY_WAVES_HPP

#include "../include/enemy.hpp"
#include "../include/enemy_waves_details.hpp"

#include <set>
#include <utility>
#include <vector>

class EnemyWaves {
public:
	EnemyWaves() {};
	EnemyWaves(int);
	void setUpWaves();
	void setUpTimings();
	std::vector<Enemy> getEnemyWave(int);
	void setLevel(int);

private:
	int _level;
	std::map<int, EnemyWaveDetails> waves;
	std::vector<std::vector<std::pair<int, int>>> waveTimingsPerLevel;
	std::vector<std::set<int>> wavesMadePerLevel;
};

#endif // ENEMY_WAVES_HPP
