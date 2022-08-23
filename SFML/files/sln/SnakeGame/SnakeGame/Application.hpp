#pragma once
#include "Window.hpp"
#include "Column.hpp"
#include "Snake.hpp"

class Application
{
public:
	
	Application();
	void build(int width, int height);
	void run(int fps = 60);

private:

	void createFrame();   // Allows you to create a frame, but it is recommended to be used only once
	void drawFunction(); // Allows the image to be drawn on the screen
	void updateScene(); // Makes the animation play
	void keyPressed(sf::Keyboard::Key key);
	void keyReleased(sf::Keyboard::Key key);
	void mouseMove(sf::Event::MouseMoveEvent event);
	void mouseClick(sf::Event::MouseButtonEvent event);
	Snake  m_snake;
	Column m_column;

	Window m_window;
	sf::Clock m_clock;
	sf::Time m_framerate;
	sf::Time m_passingTime;
};