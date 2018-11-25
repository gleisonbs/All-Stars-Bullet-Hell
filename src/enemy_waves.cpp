#include "../include/constants.hpp"
#include "../include/enemy_waves.hpp"

#include <iostream>

using namespace std;
using namespace sf;

EnemyWaves::EnemyWaves(int level) {
	setLevel(level);
	setUpWaves();
	setUpTimings();

	set<int> lvl1WavesMadeSet = {};
	wavesMadePerLevel.push_back(lvl1WavesMadeSet);
}

vector<Enemy> EnemyWaves::getEnemyWave(int secondsPassed) {
	vector<Enemy> enemies;
	for (auto const &waveTiming : waveTimingsPerLevel[_level]) {
		if (waveTiming.second <= secondsPassed and wavesMadePerLevel[_level].count(waveTiming.second) == 0) {
			wavesMadePerLevel[_level].insert(waveTiming.second);
			string faction = waves[waveTiming.first]._faction;
			for (int i = 0; i < waves[waveTiming.first]._numberOfEnemies; i++) {
				Vector2f position = waves[waveTiming.first]._positions[i];
				enemies.push_back(Enemy(faction + "_1", faction, position));
			}
		}
	}
	return enemies;
}

void EnemyWaves::setUpWaves() {
	vector<Vector2f> wave0Positions = { Vector2f(40, 40), Vector2f(80, 40), Vector2f(120, 400), Vector2f(160, 40) };
	waves[0] = EnemyWaveDetails(Factions::faction1, 4, wave0Positions);
	waves[1] = EnemyWaveDetails(Factions::faction2, 4, wave0Positions);
	waves[2] = EnemyWaveDetails(Factions::faction3, 4, wave0Positions);
	waves[3] = EnemyWaveDetails(Factions::faction4, 4, wave0Positions);
}

void EnemyWaves::setUpTimings() {
	vector<pair<int, int>> lvl1WaveTimings;
	lvl1WaveTimings.push_back(make_pair<int, int>(0, 5));
	lvl1WaveTimings.push_back(make_pair<int, int>(1, 7));
	lvl1WaveTimings.push_back(make_pair<int, int>(2, 9));
	lvl1WaveTimings.push_back(make_pair<int, int>(3, 11));

	waveTimingsPerLevel.push_back(lvl1WaveTimings);
}

void EnemyWaves::setLevel(int level) {
	_level = level;
}

