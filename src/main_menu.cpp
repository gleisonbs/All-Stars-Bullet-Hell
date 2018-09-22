#include "main_menu.hpp"
#include "constants.hpp"
#include "playing_state.hpp"
#include "game_manager.hpp"

#include <iostream>

using namespace std;
using namespace sf;

MainMenu::MainMenu() {

	mnu_start.setFont(ResourceManager::Fonts["SpaceAge"]);
	mnu_start.setString("Start");
	mnu_start.setCharacterSize(48);
	mnu_start.setPosition((WINDOW_WIDTH-mnu_start.getLocalBounds().width)/2,
		WINDOW_HEIGHT/4);

	mnu_options.setFont(ResourceManager::Fonts["SpaceAge"]);
	mnu_options.setString("Options");
	mnu_options.setCharacterSize(48);
	mnu_options.setPosition((WINDOW_WIDTH-mnu_options.getLocalBounds().width)/2,
		2*(WINDOW_HEIGHT/4));

	mnu_exit.setFont(ResourceManager::Fonts["SpaceAge"]);
	mnu_exit.setString("Exit");
	mnu_exit.setCharacterSize(48);
	mnu_exit.setPosition((WINDOW_WIDTH-mnu_exit.getLocalBounds().width)/2,
		3*(WINDOW_HEIGHT/4));

	selector.setTexture(ResourceManager::Textures["Selector"]);
	selector.scale(0.2, 0.2);
	selector.setOrigin(selector.getGlobalBounds().width/2,
		selector.getGlobalBounds().height/2);
}

bool MainMenu::handle_input() {
	Event e;
	while(GameManager::window->pollEvent(e)) {
		if(e.type == Event::KeyPressed) {
			if(e.key.code == Keyboard::Key::Up) {
				if(index == 0) index = 2;
				else --index;
			}
			else if(e.key.code == Keyboard::Key::Down) {
				if(index == 2) index = 0;
				else ++index;
			}
			else if(e.key.code == Keyboard::Key::Return) {
				if(index == 0) {
					GameManager::push_state(new PlayingState());
				}
				if(index == 2) {
					return true;
				}
			}
		}
	}
	return false;
}

void MainMenu::draw() {
	GameManager::window->clear(Color::Black);

	GameManager::window->draw(mnu_start);
	GameManager::window->draw(mnu_options);
	GameManager::window->draw(mnu_exit);
	GameManager::window->draw(selector);

	GameManager::window->display();
}

void MainMenu::update() {
	if(index == 0) {
		selector.setPosition(mnu_start.getGlobalBounds().left - selector.getGlobalBounds().width,
			mnu_start.getGlobalBounds().top-50);
	}
	else if(index == 1) {
		selector.setPosition(mnu_options.getGlobalBounds().left - selector.getGlobalBounds().width,
			mnu_options.getGlobalBounds().top-50);
	}
	else if(index == 2) {
		selector.setPosition(mnu_exit.getGlobalBounds().left - selector.getGlobalBounds().width,
			mnu_exit.getGlobalBounds().top-50);
	}
}
