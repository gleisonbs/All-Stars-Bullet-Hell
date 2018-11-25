#ifndef COLLISION_CHECKER_HPP
#define COLLISION_CHECKER_HPP

#include <vector>

#include "../include/enemy.hpp"
#include "../include/players.hpp"
#include "../include/projectile.hpp"

class CollisionChecker {
public:
	void static check(std::vector<Projectile>&, std::vector<Enemy>&);
	void static check(Player&, std::vector<Enemy>&);
private:
	CollisionChecker();
};

#endif // COLLISION_CHECKER_HPP
