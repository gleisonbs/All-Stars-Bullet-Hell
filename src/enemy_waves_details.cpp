#include "../include/enemy_waves_details.hpp"

using namespace std;
using namespace sf;

EnemyWaveDetails::EnemyWaveDetails(string faction, int numberOfEnemies, vector<Vector2f> positions) {
	_faction = faction;
	_numberOfEnemies = numberOfEnemies;
	_positions = positions;
}
