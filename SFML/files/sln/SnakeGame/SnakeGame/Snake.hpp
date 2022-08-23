#pragma once
#include "Cubicle.hpp"
#include <vector>

class Snake :public Drawable
{
public:
	Snake();

	void set(float cellSize,
		float windowWidth,
		float windowHeight);
	void addQueue();
	void movement();
	void setDirection(cellDirection newDirection);
	void draw(Window& window) override; 
	void baitCheck();
	bool baitBorder();
	bool crash();

private:
	
	void refreshBait();
	Cell m_bait;
	std::vector<Cell> m_cells;
	float m_distance;
	float m_cellSize;
	float m_windowWidth;
	float m_windowHeight;

	cellDirection m_newDirection;
};