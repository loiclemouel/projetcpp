#include "Rectangle.hpp"

Rectangle::Rectangle(ulong couleur, uint x, uint y, uint _hauteyr, uint _largeur)
	: Forme(couleur x,y), hauteur(_hauteur), margeur(_largeur)
{
	cout << "Construction" << endl;
}

Rectangle::Rectangle(istream& is)
	: Forme(is), hauteur(0), largeur(0)
{
	is >> hauteur >> largeur >> endl;
}