#pragma once
#include "Board.h"
#include<assert.h>


class Snek
{
private:
	class Segment
	{
	public:
		void InitHead(const location& in_loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const location& delta_loc);
		void Draw(Board& brd) const;
		const location& GetLoc() const;
	private:
		location loc;
		Color c;
	};
public:
	Snek(const location& loc);
	void MoveBy(const location& delta_loc);
	location getnextheadloc(const location& delta_loc) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTileexceptEnd(const location& target)const;
	bool IsInTile(const location& target)const;
private:
	static constexpr Color headColor = Colors::Blue;
	static constexpr Color bodyColor = Colors::Red;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};