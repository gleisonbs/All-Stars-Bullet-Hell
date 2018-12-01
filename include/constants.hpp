#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

const std::string IMAGES_DIR = "C:\\Users\\Gleison\\Desktop\\Projetos\\AllStars\\res\\sprites\\";
const std::string IMAGES_SHIPS = "C:\\Users\\Gleison\\Desktop\\Projetos\\AllStars\\res\\sprites\\spaceships\\";
const std::string ROOT_PATH = "./res/";
constexpr int WINDOW_WIDTH = 1900;
constexpr int WINDOW_HEIGHT = 1060;
constexpr int STAR_COUNT = 600;

namespace Fonts {
    const std::string ResourcePrefix = "fonts_";
    const std::string MainMenu = ResourcePrefix + "space_age";
    const std::string Paused = ResourcePrefix + "space_age";
    const std::string Score = ResourcePrefix + "space_age";
    const std::string Cardiff = ResourcePrefix + "cardiff";
}

namespace Factions {
    const std::string ResourcePrefix = "sprites_factions_";
    const std::string faction1 = ResourcePrefix + "faction1";
    const std::string faction2 = ResourcePrefix + "faction2";
    const std::string faction3 = ResourcePrefix + "faction3";
    const std::string faction4 = ResourcePrefix + "faction4";
    const std::string faction5 = ResourcePrefix + "faction5";
    const std::string faction6 = ResourcePrefix + "faction6";
    const std::string faction7 = ResourcePrefix + "faction7";
    const std::string faction8 = ResourcePrefix + "faction8";
    const std::string faction9 = ResourcePrefix + "faction9";
};

namespace ShipCodes {
    const std::string ship1 = "1";
    const std::string ship2 = "2";
    const std::string ship3 = "3";
    const std::string ship4 = "4";
}

namespace Menu {
    const std::string Start = "Start";
    const std::string Options = "Options";
    const std::string Exit = "Exit";
    const std::string Cursor = "sprites_factions_faction10_cruiser";
	const int CharachterSize = 60;
}

namespace Background {
	const int ScrollSpeed = 6;
	const int ScrollIntervalMs = 15;

	namespace Images {
    	const std::string ResourcePrefix = "sprites_backgrounds_";
		const std::string MainMenu = ResourcePrefix + "main_menu";
		const std::string Level1 = ResourcePrefix + "lvl_1";
		const std::string Level = ResourcePrefix + "lvl_";
	}
}

const std::string GAME_TITLE = "All Stars";
const std::string PROJECTILE = "Bullet";

//constexpr sf::Vector2f BULLET_SPEED = {-4,0};

#endif //CONSTANTS_HPP
