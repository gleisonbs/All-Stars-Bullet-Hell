#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <stack>

#include <SFML/Graphics.hpp>

#include "../include/game_state.hpp"

class GameManager {
public:
	GameManager(sf::RenderWindow *window);
	~GameManager();
	static void push_state(GameState* state);
	static void pop_state();
	static void run();
	static sf::RenderWindow *window;
	static sf::Clock pause_timer;
private:
	void handle_input();
	static std::stack<GameState*> game_states;
};

#endif // GAME_MANAGER_HPP
