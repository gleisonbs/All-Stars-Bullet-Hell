#include "ships.hpp"

using namespace std;

map<string, ShipDetails*> Ships::details { 
	{"Alien", new ShipDetails(180, 50, 40, sf::Vector2f({15, 10})) },
	{"Robot",  new ShipDetails(180, 100, 40, sf::Vector2f({15, 10})) },
	{"Human", new ShipDetails(160, 100, 50, sf::Vector2f({15, 10})) }
};