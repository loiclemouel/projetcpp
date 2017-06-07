#include "Forme.hpp"
#include "Rectangle.hpp"
Forme::Forme(ulong _couleur, uint _x, uint _y)
	: couleur(_couleur), ancre(_x, _y)
{
		cerr << "" << endl;
}

Forme::Forme(const Forme& origine)
	: couleur(origine.couleur), ancre(origine.ancre)
{
		cerr << "" << endl;
}

Forme::Forme(istream& is)
	: Forme(0,0,0)
{
	int x, y;
	is >> couleur >> x >> y;
	ancre.setXY(x, y);
}

Forme::~Forme()
{
		cerr << "" << endl;
}

bool Forme::isOver(uint x, uint y) const
{
		return ancre.isOver(x,y);
}

void Forme::dessiner(EZWindow& w, bool isActive) const
{
	w.setColor(ez_black);
	ancre.dessiner(w, isActive);
	w.setColor(couleur);
}

void Forme::ecrire(ostream& os) const
{
	os << couleur << " " << ancre;
}

ostream& operator<<(ostream  &os, const Forme& forme)
{
	forme.ecrire(os);
	return os;
}

Forme * Forme::charger(istream& is)
{
	string type_forme;
	is >> type_forme;
	if(type_forme == "Rectangle") {
		return new Rectangle(is);
	}
	// else if(type_forme == "Ellipse") {
	// 	return new Ellipse(is);
	// }
	// else if(type_forme == "Carré") {
	// 	return new Carre(is);
	// }
	// else if(type_forme == "Cercle") {
		//return new Cercle(is);
	//}
	else {
		throw runtime_error("Type de forme inconnu");}
}
