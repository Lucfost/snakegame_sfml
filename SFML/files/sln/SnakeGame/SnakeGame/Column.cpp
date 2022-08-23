#include "Column.hpp"
#include "Window.hpp"

Column::Column()
{
	set(100, 10);
	m_horizontalLine.setFillColor(sf::Color::Green);
	m_verticalLine.setFillColor(sf::Color::Green);
}

void Column::set(float length, float range)
{
	m_range = range;
	m_length = length;
	m_lines = length / range;

	m_verticalLine.setSize(sf::Vector2f(1.0f, m_length));
	m_horizontalLine.setSize(sf::Vector2f(m_length, 1.0f));
}

void Column::draw(Window& window)
{
	sf::Vector2f position;
	for (int i = 0; i <= m_lines; i++)
	{
		// Drawing of debug columns inside the window.

		position.x = 0.0f;
		position.y = i * m_range;
		m_horizontalLine.setPosition(position);
		window.draw(m_horizontalLine);
		//
		position.x = i * m_range;
		position.y = 0.0f;
		m_verticalLine.setPosition(position);
		window.draw(m_verticalLine);
	}
}