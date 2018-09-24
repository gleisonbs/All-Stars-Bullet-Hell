#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "../include/game_state.hpp"
#include "../include/resources.hpp"
#include "../include/star.hpp"

class MainMenu : public GameState {
public:
	MainMenu();
	virtual void draw();
	virtual bool handle_input();
	virtual void update();
private:
	sf::Sprite selector;
	sf::Text mnu_start;
	sf::Text mnu_options;
	sf::Text mnu_exit;
	int index = 0;
};

#endif // MAIN_MENU_HPP
