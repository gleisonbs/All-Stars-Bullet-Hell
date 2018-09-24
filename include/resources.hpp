#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

class Resources {
    //std::string spritesPath = nullptr;
    //ResourceManager resourceManager = nullptr;
    //ResourceManager() {}

public:
    /*void loadSprites(const std::string &path){

    }

    ResourceManager get() {
        if (resourceManager == nullptr) {
            resourceManager = ResourceManager();
        }
        return resourceManager;
    }*/

	static void addTexture(const std::string &name, const std::string &path) {
		sf::Texture tex;
		tex.loadFromFile(path);
		Resources::Textures[name] = tex;
	}

	static void addFont(const std::string &name, const std::string &path) {
		sf::Font font;
		font.loadFromFile(path);
		Resources::Fonts[name] = font;
	}

	static std::map<std::string, sf::Texture> Textures;
	static std::map<std::string, sf::Font> Fonts;
};

#endif // RESOURCES_HPP
