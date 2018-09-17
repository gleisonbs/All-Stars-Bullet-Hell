#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

class Drawable {
public:
    Drawable(sf::Texture, int, int, double, double);
    sf::Sprite frame();
protected:
    sf::FloatRect rect() { return sprite.getGlobalBounds(); }

    float x()       { return sprite.getPosition().x; }
	float y()       { return sprite.getPosition().y; }
	float width()   { return rect().width; }
	float height()  { return rect().height; }
	float left()    { return x() - width()/2; }
	float right()   { return x() + width()/2; }
	float top()     { return y() - height()/2; }
	float bottom()  { return y() + height()/2; }

    sf::Sprite sprite;
};

#endif // DRAWABLE_HPP
