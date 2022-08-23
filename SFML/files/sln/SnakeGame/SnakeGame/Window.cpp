#include "Window.hpp"


void Window::create(unsigned int height, unsigned int width, const sf::String& title)
{
	m_window.create(sf::VideoMode(width, height), title);
}

void Window::draw(sf::Drawable& shape)
{
	m_window.draw(shape);
}

void Window::processEvent()
{
	// Makes any in-app 'Keyboard' or 'Mouse' interaction.

	sf::Event event;
 
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			for (auto next : m_pressedKeyFunction)
				next(event.key.code);
		}
		if (event.type == sf::Event::MouseMoved)
		{
			for (auto next : m_mouseMoveFunction)
				next(event.mouseMove);
		}
	}
}

bool Window::isOpenWindow()
{
	return m_window.isOpen();
}

void Window::clean()
{
	m_window.clear();
}

void Window::render()
{
	m_window.display();
}

void Window::close()
{
	m_window.close();
}

void Window::pressedKeyFunction(KeyboardFunction newFunction)
{
	m_pressedKeyFunction.push_back(newFunction);
}

void Window::releasedKeyFunction(KeyboardFunction newFunction)
{
	m_releasedKeyFunction.push_back(newFunction);
}

void Window::mouseMoveFunction(MouseMoveFunction newFunction)
{
	m_mouseMoveFunction.push_back(newFunction);
}

void Window::mouseClickFunction(MouseClickFunction newFunction)
{
	m_mouseClickFunction.push_back(newFunction);
}

