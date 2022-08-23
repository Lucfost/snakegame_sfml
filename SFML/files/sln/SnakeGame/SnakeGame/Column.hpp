#pragma once
#include "Drawable.hpp"

/// 
/// This was done only for the snake to move smoothly in the cells, we can briefly say debug.
/// 

class Column :public Drawable
{
public:
	Column();
	void set(float length, float range);
	virtual void draw(Window& window) override;

private:

	float m_range;
	float m_length;
	int   m_lines;
	sf::RectangleShape m_horizontalLine;
	sf::RectangleShape m_verticalLine;
};