#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../include/animation.hpp"
#include "../include/constants.hpp"
#include "../include/enemy.hpp"
#include "../include/game_manager.hpp"
#include "../include/level.hpp"
#include "../include/main_menu.hpp"
#include "../include/ship_factory.hpp"
#include "../include/spaceship.hpp"
#include "../include/resources.hpp"

using namespace std;
using namespace sf;

void check_pause(sf::Clock &timer) {
	if(timer.getElapsedTime().asMilliseconds() <= 300)
		return;

	if(Keyboard::isKeyPressed(Keyboard::Key::P)) {
		timer.restart();
		while(true) {
			if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) exit(0);
			if(timer.getElapsedTime().asMilliseconds() <= 300) continue;
			if(Keyboard::isKeyPressed(Keyboard::Key::P)) {
				timer.restart();
				break;
			}
		}
	}
}

int main(int argc, char* argv[])
{
    Resources::scan(ROOT_PATH);

	RenderWindow window {{WINDOW_WIDTH, WINDOW_HEIGHT}, GAME_TITLE };
	window.setFramerateLimit(120);
	window.setMouseCursorVisible(false);

	GameManager::window = &window;
	GameManager::push_state(new MainMenu());

	GameManager::run();

	return 0;
}
