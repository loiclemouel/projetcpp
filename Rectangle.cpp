#include "Rectangle.hpp"

Rectangle::Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur)
	: Forme(_couleur, _x, _y), largeur(_largeur), hauteur(_hauteur)
{
	cout << "Construction" << endl;
}

Rectangle::Rectangle(istream& is)
	: Forme(is), largeur(0), hauteur(0)
{
	is >> hauteur >> largeur;
}
