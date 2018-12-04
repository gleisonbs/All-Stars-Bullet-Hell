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
	void loop(bool shouldLoop) { _shouldLoop = shouldLoop; }
	sf::Sprite frame();
	void setPosition(sf::Vector2f);
	void setScale(double);
	void setOrigin(int, int);
	void reset();

	bool played = false;
protected:
	sf::Clock timer;
	sf::Texture texture;
	sf::Sprite sprite;
	int i;
	int frame_width, frame_height;
	std::vector<sf::IntRect> frames;
private:
	int _frameInterval;
	bool _shouldLoop = false;
};

#endif // ANIMATION_HPP
