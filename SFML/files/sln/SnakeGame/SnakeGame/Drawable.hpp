#pragma once
#include <SFML/Graphics.hpp>

class Window;
class Drawable
{
public:
	Drawable();
	virtual void draw(Window& window) = 0;

	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	
protected:
	bool m_drawable;
	sf::Vector2f m_position;
};