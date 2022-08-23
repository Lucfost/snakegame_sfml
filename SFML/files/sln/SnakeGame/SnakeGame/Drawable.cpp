#include "Drawable.hpp"

Drawable::Drawable()
{
	m_drawable = true;
}

sf::Vector2f Drawable::getPosition()
{
	return m_position;
}

void Drawable::setPosition(const sf::Vector2f& position)
{
	m_position = position;
}



