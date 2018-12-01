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
	set<int> lvl2WavesMadeSet = {};
	wavesMadePerLevel.push_back(lvl1WavesMadeSet);
	wavesMadePerLevel.push_back(lvl2WavesMadeSet);
}

vector<Enemy> EnemyWaves::getEnemyWave(int secondsPassed) {
	vector<Enemy> enemies;
	for (auto const &waveTiming : waveTimingsPerLevel[_level]) {
		if (waveTiming.second <= secondsPassed and wavesMadePerLevel[_level].count(waveTiming.second) == 0) {
			wavesMadePerLevel[_level].insert(waveTiming.second);
			string faction = waves[waveTiming.first].faction_;
			string shipCode = waves[waveTiming.first].shipCode_;
			for (int i = 0; i < waves[waveTiming.first].numberOfEnemies_; i++) {
				Vector2f position = waves[waveTiming.first].positions_[i];
				enemies.push_back(Enemy(faction, shipCode, position));
			}
		}
	}
	return enemies;
}

void EnemyWaves::setUpWaves() {
	vector<Vector2f> wave0Positions = { Vector2f(100, 0), Vector2f(200, 0), Vector2f(300, 0), Vector2f(400, 0) };
	waves[0] = EnemyWaveDetails(Factions::faction1, ShipCodes::ship1, 4, wave0Positions);
	waves[1] = EnemyWaveDetails(Factions::faction2, ShipCodes::ship2, 4, wave0Positions);
	waves[2] = EnemyWaveDetails(Factions::faction3, ShipCodes::ship3, 4, wave0Positions);
	waves[3] = EnemyWaveDetails(Factions::faction4, ShipCodes::ship4, 4, wave0Positions);
}

void EnemyWaves::setUpTimings() {
	vector<pair<int, int>> lvl1WaveTimings;
	lvl1WaveTimings.push_back(make_pair<int, int>(0, 5));
	lvl1WaveTimings.push_back(make_pair<int, int>(1, 7));
	lvl1WaveTimings.push_back(make_pair<int, int>(2, 9));
	lvl1WaveTimings.push_back(make_pair<int, int>(3, 11));
	waveTimingsPerLevel.push_back(lvl1WaveTimings);

	vector<pair<int, int>> lvl2WaveTimings;
	lvl2WaveTimings.push_back(make_pair<int, int>(0, 5));
	lvl2WaveTimings.push_back(make_pair<int, int>(1, 7));
	lvl2WaveTimings.push_back(make_pair<int, int>(2, 9));
	lvl2WaveTimings.push_back(make_pair<int, int>(3, 11));
	waveTimingsPerLevel.push_back(lvl2WaveTimings);
}

void EnemyWaves::setLevel(int level) {
	_level = level;
}

