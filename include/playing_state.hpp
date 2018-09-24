#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include <vector>
#include <memory>

#include "../include/game_state.hpp"
#include "../include/ship_manager.hpp"
#include "../include/star.hpp"

class PlayingState : public GameState {
public:
	PlayingState();
	virtual void draw();
	virtual bool handle_input();
	virtual void update();
private:
	void draw_players();
	void draw_enemies();
	sf::Clock dt, scroll_timer;
	sf::Sprite background;
	std::vector<Star> stars;
	ShipManager ship_manager;
	bool level_cleared;
};

#endif // PLAYING_STATE_HPP
