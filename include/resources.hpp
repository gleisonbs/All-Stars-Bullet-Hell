#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

class Resources {
public:
	static void scan(const std::string&);

	static sf::Font& getFont(const std::string&);
	static sf::Texture& getTexture(const std::string&);

	static std::map<std::string, sf::Font> Fonts;
    static std::map<std::string, sf::Texture> Textures;

private:
    static void listFolderFiles(const std::string&, int, std::string);
    static void addTexture(const std::string&, const std::string&);
	static void addFont(const std::string&, const std::string&);
};

#endif // RESOURCES_HPP
