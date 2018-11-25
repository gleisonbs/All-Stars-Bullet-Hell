#ifndef GARBAGE_REMOVER_HPP
#define GARBAGE_REMOVER_HPP

#include <vector>

#include "../include/enemy.hpp"

class GarbageRemover {
public:
	static void clean(std::vector<Enemy>&);
	static void clean(std::vector<Projectile>&);
private:
	GarbageRemover();
};

#endif // GARBAGE_REMOVER_HPP
