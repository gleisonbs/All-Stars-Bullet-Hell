#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

class ResourceManager {
private:
    ResourceManager resourceManager = nullptr;
    ResourceManager() {}

public:
    ResourceManager get() {
        if (resourceManager == nullptr) {
            resourceManager = ResourceManager();
        }
        return resourceManager;
    }

	void addSprite(const std::string &name, const std::string &path) {
		sf::Texture tex;
		tex.loadFromFile(path);
		ResourceManager::Textures[name] = tex;
	}

	void addFont(const std::string &name, const std::string &path) {
		sf::Font font;
		font.loadFromFile(path);
		ResourceManager::Fonts[name] = font;
	}

	std::map<std::string, sf::Texture> sprites;
	std::map<std::string, sf::Font> fonts;
};

#endif // RESOURCE_MANAGER_HPP
