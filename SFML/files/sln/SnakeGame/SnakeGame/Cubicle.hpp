#pragma once
#include "Drawable.hpp"

enum class cellDirection
{
	Left,
	Right,
	Up,
	Down
};

class Cell :public Drawable
{
public:
	Cell();

	Cell  createCell();
	void  setDirection(cellDirection direction); 
	cellDirection getDirection();
	float getSize();
	void  setSize(float size);
	void  setSpeed(float speed);
	float getSpeed();
	void  movement();
	void  setColor(sf::Color color);
	void  draw(Window& window) override; 

private:
	cellDirection m_direction;
	sf::RectangleShape m_shape;
	float m_size;
	float m_speed;
};