#ifndef COLLISION_CHECKER_HPP
#define COLLISION_CHECKER_HPP

#include <vector>

#include "../include/enemy.hpp"
#include "../include/players.hpp"
#include "../include/projectile.hpp"

class CollisionChekcer {
public:
	void check(std::vector<Projectile>&, std::vector<Enemy>&);
	void check(Player&, std::vector<Enemy>&);
private:
};

#endif // COLLISION_CHECKER_HPP
