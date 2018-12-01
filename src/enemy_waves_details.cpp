#include "../include/enemy_waves_details.hpp"

using namespace std;
using namespace sf;

EnemyWaveDetails::EnemyWaveDetails(string faction, string shipCode, int numberOfEnemies, vector<Vector2f> positions, double scale) {
	faction_ = faction;
	shipCode_ = shipCode;
	numberOfEnemies_ = numberOfEnemies;
	positions_ = positions;
	scale_ = scale;
}
