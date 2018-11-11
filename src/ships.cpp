#include "../include/constants.hpp"
#include "../include/ships.hpp"

using namespace std;

map<string, ShipDetails*> Ships::details {
	{Races::race2, new ShipDetails(220, 50, 40, sf::Vector2f({15, 10}), sf::Vector2f({.4, .4}), .8)},
	{Races::race5, new ShipDetails(180, 90, 40, sf::Vector2f({15, 10}), sf::Vector2f({.4, .4}), .8)},
	{Races::race3, new ShipDetails(160, 90, 50, sf::Vector2f({15, 20}), sf::Vector2f({.4, .4}), .8)}
};
