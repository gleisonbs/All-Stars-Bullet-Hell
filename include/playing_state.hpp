#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include <vector>
#include <memory>

#include "../include/collision_checker.hpp"
#include "../include/game_state.hpp"
#include "../include/ship_manager.hpp"
#include "../include/level.hpp"

class PlayingState : public GameState {
public:
	PlayingState();
	virtual void draw();
	virtual bool handle_input();
	virtual void update();

	Level level;
private:
	void draw_players();
	void draw_enemies();
	sf::Clock dt;
	CollisionChekcer collisions;
	ShipManager ship_manager;
};

#endif // PLAYING_STATE_HPP
