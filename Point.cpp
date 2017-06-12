#include "Point.hpp"

Point::Point(uint _x, uint _y)
	: x(_x), y(_y)
{
	
}

Point::Point(const Point& orig)
	: Point(orig.x, orig.y)
{
	
}

Point::Point(istream& is)
	: x(0), y(0)
{
	is >> x >> y;
}

Point::~Point() {
	
}

bool Point::isOver(uint _x, uint _y) const
{
  uint x1=(_x <= x ? x:_x), x2(_x <= x ? _x:x);
  uint y1=(_y <= y ? y:_y), y2(_y <= y ? _y:y);
  uint dx = x1 - x2;
  uint dy = y1 - y2;
  return (dx <= taille && dy <= taille);
}

void Point::dessiner(EZWindow& fenetre, bool isActive) const
{
	fenetre.setColor(ez_black);
	fenetre.setThick(1);
	
	if(isActive)
		fenetre.fillRectangle(x-taille, y-taille, x+taille, y+taille);
	else
		fenetre.drawRectangle(x-taille, y-taille, x+taille, y+taille);
}

ostream &operator<<(ostream& os, const Point &p)
{
	return os << p.x <<  " " << p.y;
}
istream &operator>>(istream& is, Point& p)
{
	return is >> p.x >> p.y;
}
