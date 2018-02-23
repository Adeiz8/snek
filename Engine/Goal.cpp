#include "Goal.h"

Goal::Goal(std::mt19937 & rng, const Board & brd, const Snek & snek)
{
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937 & rng, const Board & brd, const Snek & snek)
{
	std::uniform_int_distribution<int> xDist(0, brd.getGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.getGridHeight() - 1);

	location newloc;
	do 
	{
		newloc.x = xDist(rng);
		newloc.y = yDist(rng);
	} while (snek.IsInTile(newloc));
	loc = newloc;
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const location & Goal::GetLoc() const
{
	return loc;
}
