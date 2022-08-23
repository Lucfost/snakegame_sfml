#pragma once
#include <SFML/Graphics.hpp>
#include "Functions.hpp"

class Window
{
public:
	
	void create(unsigned int height,
		unsigned int width,
		const sf::String& title = "Snake");
	void draw(sf::Drawable& shape);
	void processEvent();
	bool isOpenWindow();
	void clean();
	void render();
	void close();
	void pressedKeyFunction(KeyboardFunction newFunction);
	void releasedKeyFunction(KeyboardFunction newFunction);
	void mouseMoveFunction(MouseMoveFunction newFunction);
	void mouseClickFunction(MouseClickFunction newFunction);
	
private:
	sf::RenderWindow m_window;
	KeyboardFunctionList m_pressedKeyFunction;
	KeyboardFunctionList m_releasedKeyFunction;
	MouseMoveFunctionList m_mouseMoveFunction;
	MouseClickFunctionList m_mouseClickFunction;
};