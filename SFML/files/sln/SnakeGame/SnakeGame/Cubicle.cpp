#include "Cubicle.hpp"
#include "Window.hpp"

void Cell::draw(Window& window)
{
	m_shape.setPosition(m_position);
	window.draw(m_shape);
}

Cell::Cell()
{
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setOutlineThickness(2);
	setSize(30);
	setSpeed(5);
	setDirection(cellDirection::Right);
}

Cell Cell::createCell()
{
	sf::Vector2f newPosition = m_position;

	// Determines how the snake will orient itself inside the cell.

	switch (m_direction)
	{
	case cellDirection::Right:
		newPosition.x -= m_size;
		break;
	case cellDirection::Left:
		newPosition.x += m_size;
		break;
	case cellDirection::Up:
		newPosition.y += m_size;
		break;
	case cellDirection::Down:
		newPosition.y -= m_size;
		break;
	}

	Cell newCell;
	newCell.setPosition(newPosition);
	newCell.setDirection(m_direction);
	return newCell;
}

void Cell::setDirection(cellDirection direction)
{
	m_direction = direction;
}

cellDirection Cell::getDirection()
{
	return m_direction;
}

float Cell::getSize()
{
	return m_size;
}

void Cell::setSize(float size)
{
	m_size = size;
	m_shape.setSize(sf::Vector2f(m_size, m_size));
}

void Cell::setSpeed(float speed)
{
	m_speed = speed;
}

float Cell::getSpeed()
{
	return m_speed;
}

void Cell::setColor(sf::Color color)
{
	m_shape.setFillColor(color);
}

void Cell::movement()
{
	// Allows the snake to move inside the cell.

	switch (m_direction)
	{
	case cellDirection::Right:
		m_position.x += m_speed;
		break;
	case cellDirection::Left:
		m_position.x -= m_speed;
		break;
	case cellDirection::Up:
		m_position.y -= m_speed;
		break;
	case cellDirection::Down:
		m_position.y += m_speed;
		break;
	}
}