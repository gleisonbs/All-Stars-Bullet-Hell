#include <iostream>

#include "../include/garbage_remover.hpp"

using namespace std;

void GarbageRemover::clean(vector<Enemy> &enemies) {
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].isExploding() and enemies[i].explosion.played)
			enemies.erase(enemies.begin() + i);
	}
}

void GarbageRemover::clean(vector<Projectile> &projectiles) {
	for (int i = 0; i < projectiles.size(); i++) {
		if (projectiles[i].isDestroyed() or projectiles[i].isOutOfScreen())
			projectiles.erase(projectiles.begin() + i);
	}
}
