#include "Application.hpp"
#include<iostream>

Application::Application()
{
	
}

void Application::build(int width, int height)
{
	m_window.create(width, height);
	m_column.set(width, 50);
	m_snake.set(50, width, height);

	m_window.pressedKeyFunction(
		std::bind(&Application::keyPressed, this, std::placeholders::_1)
	);
	m_window.mouseMoveFunction(
		std::bind(&Application::mouseMove, this, std::placeholders::_1)
	);
	m_window.mouseClickFunction(
		std::bind(&Application::mouseClick, this, std::placeholders::_1)
	);
	m_window.releasedKeyFunction(
		std::bind(&Application::keyReleased, this, std::placeholders::_1)
	);
}

void Application::run(int fps)
{
	float cerfps = 1.0f / fps;
	m_framerate = sf::seconds(cerfps);
	m_passingTime = m_clock.restart();
	while (m_window.isOpenWindow())
	{
		m_window.processEvent();
		m_passingTime = m_clock.getElapsedTime();
		if (m_passingTime >= m_framerate)
		{
			createFrame();
			m_passingTime = sf::seconds(0.0f);
			m_clock.restart();
		}
		else
		{
			sf::sleep(m_passingTime - m_passingTime - m_framerate);
		}
		//std::cout << fps << std::endl;
	}
}

void Application::createFrame()
{
	updateScene();
	drawFunction();
}

void Application::drawFunction()
{
	m_window.clean();
	m_snake.draw(m_window);
    //m_column.draw(m_window);
	m_window.render();
}

void Application::updateScene()
{
	m_snake.movement(); 
}

void Application::keyPressed(sf::Keyboard::Key key)
{
	// Any in-game key addition is done here

	if (key == sf::Keyboard::Left)
		m_snake.setDirection(cellDirection::Left);
	if (key == sf::Keyboard::Right)
		m_snake.setDirection(cellDirection::Right);
	if (key == sf::Keyboard::Up)
		m_snake.setDirection(cellDirection::Up);
	if (key == sf::Keyboard::Down)
		m_snake.setDirection(cellDirection::Down);
	if (key == sf::Keyboard::Space)
		m_snake.addQueue();
	if (key == sf::Keyboard::D)
		m_window.close();
}

void Application::keyReleased(sf::Keyboard::Key key)
{
	// You can customize it as you want by adding the button release feature you want here.
}

void Application::mouseMove(sf::Event::MouseMoveEvent event)
{
	std::cout << "POS.X " << event.x << "    " << "POS.Y " << event.y << std::endl;

}

void Application::mouseClick(sf::Event::MouseButtonEvent event)
{
	// You can customize it by adding mouse feature here as you wish.
}