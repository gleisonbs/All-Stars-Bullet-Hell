#include "../include/constants.hpp"
#include "../include/ships.hpp"

using namespace std;

map<string, ShipDetails*> Ships::details {
	{Factions::faction1, new ShipDetails(180, 90, 40, sf::Vector2f({15, 10}), sf::Vector2f({.4, .4}), .8)},
	{Factions::faction2, new ShipDetails(220, 90, 40, sf::Vector2f({.02, .02}), sf::Vector2f({.02, .02}), .2)},
	{Factions::faction3, new ShipDetails(220, 90, 40, sf::Vector2f({.02, .02}), sf::Vector2f({.02, .02}), .2)},
	{Factions::faction4, new ShipDetails(180, 90, 40, sf::Vector2f({15, 10}), sf::Vector2f({.4, .4}), .8)},
	{Factions::faction5, new ShipDetails(160, 90, 50, sf::Vector2f({15, 20}), sf::Vector2f({.4, .4}), .8)}
};
