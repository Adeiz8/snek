#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const location& loc, Color c);
	void DrawBorder();
	int getGridWidth() const;
	int getGridHeight() const;
	bool IsInsideBoard(const location& loc) const;

private:
	static constexpr Color bordercolor = Colors::Yellow;
	static constexpr int dimension = 20;
	static constexpr int borderwidth = 4;
	static constexpr int borderpadding = 2;
	static constexpr int cellpadding = 1;
	static constexpr int x = 70;
	static constexpr int y = 50;
	static constexpr int width = 32;
	static constexpr int height = 24;
	Graphics& gfx;
};
