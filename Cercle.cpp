#include "Cercle.hpp"

Cercle::Cercle(uint _epaisseur, ulong _couleur, uint _x, uint _y, uint _rayon)
  : Forme(_epaisseur,_couleur, _x, _y), rayon(_rayon)
{
  cout << "Construction Cercle" << endl;
}

Cercle::Cercle(istream & is)
  : Forme(is), rayon(0)
{
  is >> rayon;
}

Cercle::~Cercle()
{}

double Cercle::perimetre() const
{
  return 2*rayon*3.14159265359;
}

void Cercle::ecrire(ostream & os) const
{
  os << "Cercle";
  Forme::ecrire(os);
  os << rayon;
}

void Cercle::dessiner(EZWindow & fenetre, bool isActive) const
{
  Forme::dessiner(fenetre, isActive);
  const Point & ancre = getAncre();
  if(getRemplissage())
	  fenetre.fillCircle(ancre.getX(), ancre.getY(), ancre.getX() + rayon, ancre.getY() + rayon);
  else
	  fenetre.drawCircle(ancre.getX(), ancre.getY(), ancre.getX() + rayon, ancre.getY() + rayon);
}
