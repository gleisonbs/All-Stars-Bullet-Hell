#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "animation.hpp"
#include "constants.hpp"
#include "enemy.hpp"
#include "game_manager.hpp"
#include "main_menu.hpp"
#include "ship_factory.hpp"
#include "spaceship.hpp"
#include "resource_manager.hpp"

using namespace std;
using namespace sf;

void load_textures() {
	ResourceManager::addTexture("Alien", IMAGES_SHIPS + "Alien/ship.png");
	ResourceManager::addTexture("Human", IMAGES_SHIPS + "Human/ship.png");
	ResourceManager::addTexture("Robot", IMAGES_SHIPS + "Robot/ship.png");
	ResourceManager::addTexture("Bullet", IMAGES_DIR + "bullet.png");
	ResourceManager::addTexture("Selector", IMAGES_DIR + "tribase-u2-d0.png");
	ResourceManager::addTexture("Explosion", IMAGES_DIR + "explosions/explosion.png");
	ResourceManager::addTexture("L1_background", IMAGES_DIR + "level1_background.png");
}

void load_fonts() {
	ResourceManager::addFont("Cardiff", "Fonts/cardiff.ttf");
	ResourceManager::addFont("SpaceAge", "Fonts/space_age.ttf");
}

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

/* -------------------------- MAIN STARTS HERE -------------------------- */

int main(int argc, char* argv[])
{
	load_textures();
	load_fonts();

	string name = "Human";
	if(argc > 1) name = argv[1];

	RenderWindow window {{WINDOW_WIDTH, WINDOW_HEIGHT}, "All Stars" };
	window.setFramerateLimit(60);

	window.setMouseCursorVisible(false);

	GameManager::window = &window;
	GameManager::push_state(new MainMenu());

	GameManager::run();

	return 0;
}