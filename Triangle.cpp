#include "Triangle.hpp"

Triangle::Triangle(uint _epaisseur,ulong _couleur, uint _x, uint _y, Point _point1, Point _point2)
	: Forme(_epaisseur, _couleur, _x, _y), point1(_point1), point2(_point2)
{
	cout << "Construction Triangle" << endl;
}

Triangle::Triangle(istream& is)
	: Forme(is), point1(0,0), point2(0,0)
{
	is >> point2 >> point1;
}

Triangle::~Triangle(){
	
}

double Triangle::perimetre() const
{
	return(2)*2;
}

void Triangle::ecrire(ostream & os) const
{
  os << "Triangle";
  Forme::ecrire(os);
  os << point1 << " " << point2;
}

void Triangle::dessiner(EZWindow & fenetre, bool isactive) const
{
  Forme::dessiner(fenetre, isactive);
  const Point & ancre = getAncre();
  if(getRemplissage())
	  fenetre.fillTriangle(ancre.getX(), ancre.getY(),point1.getX(),point1.getY(),point2.getX(),point2.getY());
  else
	  fenetre.drawTriangle(ancre.getX(), ancre.getY(),point1.getX(),point1.getY(),point2.getX(),point2.getY());
}