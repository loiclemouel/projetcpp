#include "Carre.hpp"

Carre::Carre(uint _epaisseur, ulong _couleur, uint _x, uint _y, uint _longueur)
  : Forme(_epaisseur, _couleur, _x, _y), longueur(_longueur)
{
  cout << "Construction Carre" << endl;
}

Carre::Carre(istream & is)
  : Forme(is), longueur(0)
{
  is >> longueur;
}

Carre::~Carre()
{}

double Carre::perimetre() const
{
  return(longueur*4);
}

void Carre::ecrire(ostream & os) const
{
  os << "Carre";
  Forme::ecrire(os);
  os << " "<<longueur;
}

void Carre::dessiner(EZWindow & fenetre, bool isActive) const
{
  Forme::dessiner(fenetre, isActive);
  const Point & ancre = getAncre();
  if(getRemplissage())
	  fenetre.fillRectangle(ancre.getX(), ancre.getY(), ancre.getX() + longueur, ancre.getY() + longueur);
  else
	  fenetre.drawRectangle(ancre.getX(), ancre.getY(), ancre.getX() + longueur, ancre.getY() + longueur);
}
