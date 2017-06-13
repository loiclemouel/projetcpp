#ifndef FORMES_HPP
#define FORMES_HPP

#include "Point.hpp"
#include "Forme.hpp"
#include <iostream>

using namespace std;



class Formes {
	private:
		size_t maxFormes;
		size_t nbFormes;
		Forme * * formes;

	public:
		Formes(size_t taille=200);
		~Formes();
		void ajouter(Forme * forme);
		Forme * isOver(uint x, uint y);
		void dessiner(EZWindow & fenetre);
		friend ostream &operator<<(ostream &os, const Formes &f);
		void sauver(ostream &os) const;
		void charger(istream &is);
};
#endif
