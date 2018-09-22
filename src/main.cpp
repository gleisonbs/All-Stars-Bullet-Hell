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
	ResourceManager::addTexture("faction3", IMAGES_SHIPS +  Races::race3 + "\\alien4.png");
	ResourceManager::addTexture("faction2", IMAGES_SHIPS + Races::race2 + "\\blueship4.png");
	ResourceManager::addTexture("faction5", IMAGES_SHIPS + Races::race5 + "\\F5S3.png");
	ResourceManager::addTexture("Bullet", IMAGES_DIR + "bullet.png");
	ResourceManager::addTexture("Selector", IMAGES_DIR + "faction4-Spacestations\\Spacestation.png");
	ResourceManager::addTexture("Explosion", IMAGES_DIR + "explosions\\explosion.png");
	ResourceManager::addTexture("L1_background", IMAGES_DIR + "level1_background.png");
}

void load_fonts() {
	ResourceManager::addFont("Cardiff", "C:\\Users\\Gleison\\Desktop\\Projetos\\AllStars\\res\\fonts\\cardiff.ttf");
	ResourceManager::addFont("SpaceAge", "C:\\Users\\Gleison\\Desktop\\Projetos\\AllStars\\res\\fonts\\space_age.ttf");
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

	string name = Races::race2;
	if(argc > 1) name = argv[1];

	RenderWindow window {{WINDOW_WIDTH, WINDOW_HEIGHT}, GAME_TITLE };
	window.setFramerateLimit(60);

	//window.setMouseCursorVisible(false);

	GameManager::window = &window;
	GameManager::push_state(new MainMenu());

	GameManager::run();

	return 0;
}
