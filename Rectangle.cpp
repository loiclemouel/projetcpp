#include "Rectangle.hpp"

Rectangle::Rectangle(uint _epaisseur,ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur)
	: Forme(_epaisseur, _couleur, _x, _y), largeur(_largeur), hauteur(_hauteur)
{
	cout << "Construction rectangle" << endl;
}

Rectangle::Rectangle(istream& is)
	: Forme(is), largeur(0), hauteur(0)
{
	is >> hauteur >> largeur;
}

Rectangle::~Rectangle(){
	
}

double Rectangle::perimetre() const
{
	return(largeur+hauteur)*2;
}

void Rectangle::ecrire(ostream & os) const
{
  os << "Rectangle";
  Forme::ecrire(os);
  os <<" "<< largeur << " " << hauteur;
}

void Rectangle::dessiner(EZWindow & fenetre, bool isactive) const
{
  Forme::dessiner(fenetre, isactive);
  const Point & ancre = getAncre();
  if(getRemplissage())
	  fenetre.fillRectangle(ancre.getX(), ancre.getY(), ancre.getX() + largeur, ancre.getY() + hauteur);
  else
	  fenetre.drawRectangle(ancre.getX(), ancre.getY(), ancre.getX() + largeur, ancre.getY() + hauteur);
}