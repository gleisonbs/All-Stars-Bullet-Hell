#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

const std::string IMAGES_DIR = "C:\\Users\\Gleison\\Desktop\\Projetos\\AllStars\\res\\sprites\\";
const std::string IMAGES_SHIPS = "C:\\Users\\Gleison\\Desktop\\Projetos\\AllStars\\res\\sprites\\spaceships\\";
constexpr int WINDOW_WIDTH = 1900;
constexpr int WINDOW_HEIGHT = 1060;
constexpr int STAR_COUNT = 600;

namespace Races {
    const std::string race1 = "faction1";
    const std::string race2 = "faction2";
    const std::string race3 = "faction3";
    const std::string race4 = "faction4";
    const std::string race5 = "faction5";
    const std::string race6 = "faction6";
    const std::string race7 = "faction7";
    const std::string race8 = "faction8";
    const std::string race9 = "faction9";
};

const std::string GAME_TITLE = "All Stars";
const std::string PROJECTILE = "Bullet";



//constexpr sf::Vector2f BULLET_SPEED = {-4,0};

#endif //CONSTANTS_HPP
