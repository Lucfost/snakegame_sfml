#include "Snake.hpp"
#include "Application.hpp"
#include "Window.hpp"
#include <SFML/Graphics.hpp>

Snake::Snake()
{
	m_distance = 0.0f; // Makes the last cell of the snake start from the first pixel
	m_newDirection = cellDirection::Right; // Determines which direction the snake will start
}

void Snake::set(float cellSize, float windowWidth, float windowHeight)
{
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	m_cellSize = cellSize;
	refreshBait();
	addQueue();
	addQueue();
	addQueue();
	addQueue();
}

void Snake::baitCheck()
{
	// Sets the cell that will be attached to the snake when the snake eats the bait

	if (m_cells[0].getPosition() == m_bait.getPosition())
	{
		addQueue();
		refreshBait();

		bool collision;

		do
		{
			collision = false;

			for (auto& next : m_cells)
			{
				if (next.getPosition() == m_bait.getPosition())
				{
					refreshBait();
					collision = true;
					break;
				}
			}
		} while (collision);
	}
}

bool Snake::baitBorder()
{
	// Checking if the bait is in the window

	if (m_cells[0].getPosition().x<0 ||
		m_cells[0].getPosition().x + m_cellSize > m_windowWidth ||
		m_cells[0].getPosition().y<0 ||
		m_cells[0].getPosition().y + m_cellSize > m_windowHeight)
		return false;

	return true;
}

bool Snake::crash()
{
	// In case of an accident, you can close the window by pressing the "D" key.

	int cratch = m_cells.size();

	for (int i = 2; i < cratch; i++)
	{
		if (m_cells[0].getPosition() == m_cells[i].getPosition())
			return true;
			
	}
	return false;
}

void Snake::addQueue()
{
	// You can add to the rearmost cell of the snake by pressing the "Space" key.

	Cell newCell;
	if (m_cells.size())
	{
		newCell = m_cells.back().createCell();
	}
	newCell.setSize(m_cellSize);
	
	m_cells.push_back(newCell);
}

void Snake::movement()
{
	if (!baitBorder())
		return;
	if (crash())
		return;

	for (auto& next : m_cells)
	{
		next.movement();
	}

	m_distance += m_cells[0].getSpeed();

	if (m_distance == m_cells[0].getSize())
	{
		baitCheck();

		for (int i = m_cells.size() - 1; i > 0; i--)
		{
			m_cells[i].setDirection(m_cells[i - 1].getDirection());
		}
		m_cells[0].setDirection(m_newDirection);
		m_distance = 0.0f;
	}
}

void Snake::setDirection(cellDirection newDirection)
{
	// It is specified how the snake will orient itself within the cells.

	if (newDirection == cellDirection::Right && m_cells[0].getDirection() == cellDirection::Left) return;

	if (newDirection == cellDirection::Left && m_cells[0].getDirection() == cellDirection::Right) return;

	if (newDirection == cellDirection::Up && m_cells[0].getDirection() == cellDirection::Down)	  return;

	if (newDirection == cellDirection::Down && m_cells[0].getDirection() == cellDirection::Up)    return;

	m_newDirection = newDirection;
}

void Snake::draw(Window& window)
{
	m_bait.draw(window);
	for (auto& next : m_cells)
	{
		next.draw(window);
	}
}

void Snake::refreshBait()
{
	// Checking that the bait is refreshed and that it doesn't spawn in the same pixel as the snake.

	int columnLines = m_windowWidth / m_cellSize;
	int rowLines = m_windowHeight / m_cellSize;
	float x = (rand() % columnLines) * m_cellSize;
	float y = (rand() % rowLines) * m_cellSize;
	m_bait.setPosition(sf::Vector2f(x, y));
	m_bait.setSize(m_cellSize);
	m_bait.setColor(sf::Color::Green);
}