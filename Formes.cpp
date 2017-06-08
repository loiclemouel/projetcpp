#include "Formes.hpp"


Formes::Formes(size_t taille)
	: maxFormes(taille), nbFormes(0), formes(nullptr)
{
	formes = new Forme * [maxFormes];
}

Formes::~Formes()
{
	for(size_t i=0; i<nbFormes; i++)
		delete formes[i];
	delete[] formes;
}

void Formes::ajouter(Forme *f)
{
  if (nbFormes < maxFormes)
  {
    formes[nbFormes++]=f;
  }
  else
  {
    throw runtime_error("Aucune nouvelle forme ne peut être ajoutée");
  }
}

void Formes::dessiner(EZWindow& fenetre)
{
	for (size_t i=0 ; i < nbFormes ; ++i)
		formes[i]->dessiner(fenetre);
}

Forme * Formes::isOver(uint x, uint y)
{
	for(size_t i=0; i < nbFormes; ++i)
	{
		if(formes[i]->isOver(x,y))
			return formes[i];
	}
	return nullptr;
}

void Formes::sauver(ostream& os) const
{
	os << nbFormes << endl;
	for (size_t i=0 ; i < nbFormes ; i++)
		os << *formes[i] << endl;
}

void Formes::charger(istream& is)
{
	for(size_t i=0 ; i<nbFormes ; i++)
		delete formes[i];
	nbFormes=0;
	size_t combien=0;
	is >> combien;
	if(combien < maxFormes)
		for(size_t i=0 ; i < combien ; i++)
			ajouter(Forme::charger(is));
}

ostream &operator<<(ostream &os, const Formes &f)
{
	f.sauver(os);
	return os;
}
