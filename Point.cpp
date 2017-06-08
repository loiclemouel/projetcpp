#include "Point.hpp"

Point::Point(uint _x, uint _y)
	: x(_x), y(_y)
{}

Point::Point(const Point& orig)
	: Point(orig.x, orig.y)
{}

Point::Point(istream& is)
	: x(0), y(0)
{
	is >> x >> y;
}

Point::~Point() {}

bool Point::isOver(uint _x, uint _y) const
{
	uint dx;
	uint dy;
	dx = x - _x;
	dy = y - _y;
	if(dx < _x)
		dx = -dx;
	if(dy < _y)
		dy = -dy;
	return(dx <= taille && dy <= taille);
}

void Point::dessiner(EZWindow& w, bool isActive) const
{
	if(isActive)
		w.fillRectangle(x-taille, y-taille, x+taille, y+taille);
	else
		w.drawRectangle(x-taille, y-taille, x+taille, y+taille);
}

ostream &operator<<(ostream& os, const Point &p)
{
	return os << p.x <<  " " << p.y;
}
istream &operator>>(istream& is, Point& p)
{
	return is >> p.x >> p.y;
}
