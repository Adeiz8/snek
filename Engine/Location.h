#pragma once

class location
{
public:
	void add(const location& val)
	{
		x += val.x;
		y += val.y;
	}
	bool operator== (const location& rhs) const
	{
		return x == rhs.x && y == rhs.y;

	}
	int x;
	int y;
};