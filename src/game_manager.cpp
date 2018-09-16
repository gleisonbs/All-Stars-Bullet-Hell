#include "game_manager.hpp"
#include <iostream>

using namespace std;
using namespace sf;

stack<GameState*> GameManager::game_states;// = stack();
RenderWindow *GameManager::window = 0;
sf::Clock GameManager::pause_timer;

GameManager::GameManager(RenderWindow *window) {
	this->window = window;
}

GameManager::~GameManager() {
	while(not game_states.empty()) pop_state();
}

void GameManager::push_state(GameState *state) {
	cout << 1 << endl;
	game_states.push(state);
}

void GameManager::pop_state() {
	delete game_states.top();
	game_states.pop();
}

void GameManager::handle_input() {
	
}

void GameManager::run() {
	Event event;
	while(not game_states.empty()) {
		if(game_states.top()->handle_input()) {
			pop_state();
			continue;
		}
		game_states.top()->update();
		game_states.top()->draw();
	}
}