#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../include/animation.hpp"
#include "../include/constants.hpp"
#include "../include/enemy.hpp"
#include "../include/game_manager.hpp"
#include "../include/main_menu.hpp"
#include "../include/ship_factory.hpp"
#include "../include/spaceship.hpp"
#include "../include/resources.hpp"

using namespace std;
using namespace sf;

//void load_textures() {
//	Resources::addTexture("faction3", IMAGES_SHIPS +  Races::race3 + "\\alien4.png");
//	Resources::addTexture("faction2", IMAGES_SHIPS + Races::race2 + "\\blueship4.png");
//	Resources::addTexture("faction5", IMAGES_SHIPS + Races::race5 + "\\F5S3.png");
//	Resources::addTexture("Bullet", IMAGES_DIR + "bullet.png");
//	Resources::addTexture("Selector", IMAGES_DIR + "faction4-Spacestations\\Spacestation.png");
//	Resources::addTexture("Explosion", IMAGES_DIR + "explosions\\explosion.png");
//	Resources::addTexture("L1_background", IMAGES_DIR + "level1_background.png");
//}
//
//void load_fonts() {
//	Resources::addFont("Cardiff", "C:\\Users\\Gleison\\Desktop\\Projetos\\AllStars\\res\\fonts\\cardiff.ttf");
//	Resources::addFont("SpaceAge", "C:\\Users\\Gleison\\Desktop\\Projetos\\AllStars\\res\\fonts\\space_age.ttf");
//}

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
//    auto resourceManager = ResourceManager.get(ROOT_PATH);
    Resources::scan(ROOT_PATH);

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
