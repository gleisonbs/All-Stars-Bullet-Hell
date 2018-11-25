#include "../include/collision_checker.hpp"

void CollisionChekcer::check(std::vector<Projectile> &projectiles, std::vector<Enemy> &enemies) {
	for(auto &enemy : enemies) {
		for(auto &projectile : projectiles) {
			if(enemy.isOutOfScreen() or enemy.isDestroyed() or enemy.isExploding() or projectile.isDestroyed())
				continue;

			if(projectile.rect().intersects(enemy.rect())) {
				enemy.takeHit(projectile.damage_);
				projectile.takeHit(1);
			}
		}
	}
}

void CollisionChekcer::check(Player &player, std::vector<Enemy> &enemies) {
	if(player.invulnerable)
		return;

	for(auto &enemy : enemies) {
		if(enemy.isExploding())
			continue;

		if(player.rect().intersects(enemy.rect()))
			player.take_hit(90);
	}
}
