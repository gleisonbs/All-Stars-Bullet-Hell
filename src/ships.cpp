#include "../include/constants.hpp"
#include "../include/ships.hpp"

using namespace std;

map<string, ShipDetails*> Ships::details {
	{Factions::faction1, new ShipDetails(180, 90, 40, sf::Vector2f({2, 2}), sf::Vector2f({.1, .1}), .5)},
	{Factions::faction2, new ShipDetails(220, 90, 40, sf::Vector2f({2, .5}), sf::Vector2f({.05, .05}), .2)},
	{Factions::faction3, new ShipDetails(220, 90, 40, sf::Vector2f({1.5, 1}), sf::Vector2f({.05, .03}), .4)},
	{Factions::faction4, new ShipDetails(180, 90, 40, sf::Vector2f({3, 10}), sf::Vector2f({.4, .4}), .8)},
	{Factions::faction5, new ShipDetails(160, 90, 50, sf::Vector2f({2, 20}), sf::Vector2f({.4, .4}), .8)}
};
