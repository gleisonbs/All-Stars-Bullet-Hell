#include "../include/paused_state.hpp"
#include "../include/game_manager.hpp"
#include "../include/resources.hpp"
#include "../include/constants.hpp"

#include <iostream>

using namespace std;
using namespace sf;

PausedState::PausedState()
{
	txt_pause = new Text();
	txt_pause->setFont(Resources::getFont(Fonts::ResourcePrefix + Fonts::SpaceAge));
	txt_pause->setString("PAUSED");
	int string_width = txt_pause->getLocalBounds().width;
	int string_height = txt_pause->getLocalBounds().height;
	txt_pause->setCharacterSize(100);
	txt_pause->setPosition((WINDOW_WIDTH/2)-string_width*2,
												 WINDOW_HEIGHT/2-string_height);
}

void PausedState::update() {

}

void PausedState::draw() {
	GameManager::window->draw(*txt_pause);
	GameManager::window->display();
}

bool PausedState::handle_input() {
	Event e;
	while(GameManager::window->pollEvent(e)) {
		if(e.type == Event::KeyPressed) {
			if(e.key.code == Keyboard::Key::P) {
				if(GameManager::pause_timer.getElapsedTime().asMilliseconds() >= 250) {
					GameManager::pause_timer.restart();
					return true;
				}
			}
		}
	}
	return false;
}
