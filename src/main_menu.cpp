#include <iostream>

#include "../include/main_menu.hpp"
#include "../include/constants.hpp"
#include "../include/playing_state.hpp"
#include "../include/game_manager.hpp"

using namespace std;
using namespace sf;

MainMenu::MainMenu() {

	mnu_start.setFont(Resources::getFont(Fonts::MainMenu));
	mnu_start.setString(Menu::Start);
	mnu_start.setCharacterSize(Menu::CharachterSize);
	mnu_start.setPosition((WINDOW_WIDTH-mnu_start.getLocalBounds().width)/2,
		WINDOW_HEIGHT/4);

	mnu_options.setFont(Resources::getFont(Fonts::MainMenu));
	mnu_options.setString(Menu::Options);
	mnu_options.setCharacterSize(Menu::CharachterSize);
	mnu_options.setPosition((WINDOW_WIDTH-mnu_options.getLocalBounds().width)/2,
		2*(WINDOW_HEIGHT/4));

	mnu_exit.setFont(Resources::getFont(Fonts::MainMenu));
	mnu_exit.setString(Menu::Exit);
	mnu_exit.setCharacterSize(Menu::CharachterSize);
	mnu_exit.setPosition((WINDOW_WIDTH-mnu_exit.getLocalBounds().width)/2,
		3*(WINDOW_HEIGHT/4));

	selector.setTexture(Resources::getTexture(Menu::Cursor));
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
	sf::Text mnu_item;
	if(index == 0)
		mnu_item = mnu_start;
	else if(index == 1)
		mnu_item = mnu_options;
	else if(index == 2)
		mnu_item = mnu_exit;

	selector.setPosition(mnu_item.getGlobalBounds().left - selector.getGlobalBounds().width,
		mnu_item.getGlobalBounds().top - mnu_item.getGlobalBounds().height/2);
}
