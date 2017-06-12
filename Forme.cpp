#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Ellipse.hpp"
#include "Cercle.hpp"
#include "Carre.hpp"
#include "Triangle.hpp"

Forme::Forme(uint _epaisseur,ulong _couleur, uint x, uint y)
	: epaisseur (_epaisseur), couleur(_couleur), ancre(x, y)
{
		cerr << "creation forme" << endl;
}

Forme::Forme(const Forme& orig)
	: epaisseur (orig.epaisseur), couleur(orig.couleur), ancre(orig.ancre)
{
		cerr << "creation copie forme" << endl;
}

Forme::Forme(istream& is)
	: Forme(0,0,0,0)
{
	int x, y;
	is >> epaisseur >> couleur >> x >> y;
	ancre.setXY(x, y);
}

Forme::~Forme()
{
		cerr << "destruction de forme" << endl;
}

bool Forme::isOver(uint _x, uint _y) const
{
		return ancre.isOver(_x,_y);
}

void Forme::dessiner(EZWindow& fenetre, bool isActive) const
{
	ancre.dessiner(fenetre, isActive);
	fenetre.setColor(couleur);
	fenetre.setThick(epaisseur);
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
    else if(type_forme == "Ellipse") {
	 	return new Ellipse(is);
	}
	else if(type_forme == "Carré") {
	 	return new Carre(is);
	 }
	else if(type_forme == "Cercle") {
		return new Cercle(is);
	}
	else if(type_forme == "Triangle") {
		return new Triangle(is);
	}
	else {
		throw runtime_error("Type de forme inconnu");
	}
}
