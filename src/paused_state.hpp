#ifndef PAUSED_STATE_HPP
#define PAUSED_STATE_HPP

#include "game_state.hpp"

class PausedState : public GameState {
public:
	PausedState();
	virtual void update();
	virtual bool handle_input();
	virtual void draw();
private:
	sf::Text *txt_pause;
};

#endif // PAUSED_STATE_HPP