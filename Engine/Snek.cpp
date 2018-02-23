#include "Snek.h"

Snek::Snek(const location & loc)
{
	segments[0].InitHead(loc);
}

void Snek::MoveBy(const location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

location Snek::getnextheadloc(const location & delta_loc) const
{
	location l(segments[0].GetLoc());
	l.add(delta_loc);
	return l;
}

void Snek::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody();
		++nSegments;
	}

}

void Snek::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

bool Snek::IsInTileexceptEnd(const location & target) const
{
	for (int i = 0; i < nSegments - 1; ++i)
	{
		if (segments[i].GetLoc() == target)
		{
		return true;
		}
	}
	return false;
}

bool Snek::IsInTile(const location & target) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].GetLoc() == target)
		{
			return true;
		}
	}
	return false;
}

void Snek::Segment::InitHead(const location & in_loc)
{
	loc = in_loc;
	c = Snek::headColor;
}

void Snek::Segment::InitBody()
{
	c = Snek::bodyColor;
}

void Snek::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snek::Segment::MoveBy(const location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
}

void Snek::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const location& Snek::Segment::GetLoc() const
{
	return loc;
}
