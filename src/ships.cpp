#include "constants.hpp"
#include "ships.hpp"

using namespace std;

map<string, ShipDetails*> Ships::details {
	{Races::race2, new ShipDetails(220, 50, 40, sf::Vector2f({15, 10})) },
	{Races::race5, new ShipDetails(180, 100, 40, sf::Vector2f({15, 10})) },
	{Races::race2, new ShipDetails(160, 100, 50, sf::Vector2f({15, 10})) }
};
