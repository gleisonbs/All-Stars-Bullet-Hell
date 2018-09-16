#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>

class GameState {
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual bool handle_input() = 0;
};

#endif // GAME_STATE_HPP