#include "Ellipse.hpp"

Ellipse::Ellipse(uint _epaisseur,ulong _couleur, uint _x, uint _y, uint _demilargeur, uint _demihauteur)
	: Forme(_epaisseur,_couleur, _x, _y), demilargeur(_demilargeur), demihauteur(_demihauteur)
{
	cout << "Construction ellipse" << endl;
}

Ellipse::Ellipse(istream& is)
	: Forme(is), demilargeur(0), demihauteur(0)
{
	is >> demihauteur >> demilargeur;
}

Ellipse::~Ellipse(){
	
}

double Ellipse::perimetre() const
{
	return 2*PI*sqrt(0.5* (demihauteur*demihauteur + demilargeur*demilargeur)) ;
}

void Ellipse::ecrire(ostream & os) const
{
  os << "Ellipse";
  Forme::ecrire(os);
  os << " "<<demilargeur << " " << demihauteur;
}

void Ellipse::dessiner(EZWindow & fenetre, bool isactive) const
{
  Forme::dessiner(fenetre, isactive);
  const Point & ancre = getAncre();
  if(getRemplissage())
	  fenetre.fillCircle(ancre.getX(), ancre.getY(), ancre.getX() + demilargeur*2, ancre.getY() + demihauteur*2);
  else
	  fenetre.drawCircle(ancre.getX(), ancre.getY(), ancre.getX() + demilargeur*2, ancre.getY() + demihauteur*2);
}