#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

class Animation {
public:
	Animation();
	void set(const std::string, int=100);
	void add_frame(int, int, int, int);
	sf::Sprite frame();
	void set_position(sf::Vector2f);
	bool played = false;
protected:
	sf::Clock timer;
	sf::Texture texture;
	sf::Sprite sprite;
	int interval;
	int i;
	int frame_width, frame_height;
	std::vector<sf::IntRect> frames;
};

#endif // ANIMATION_HPP
