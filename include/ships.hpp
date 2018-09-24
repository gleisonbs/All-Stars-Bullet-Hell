#ifndef SHIPS_HPP
#define SHIPS_HPP

#include <map>

#include <SFML/Graphics.hpp>

#include "../include/ship_details.hpp"

class Ships {
public:
	Ships() {};
	static std::map<std::string, ShipDetails*> details;
};

#endif // SHIPS_HPP
