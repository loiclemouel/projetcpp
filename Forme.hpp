#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;


class Forme {
	private:
		ulong couleur;
		Point ancre;
		bool selected;

	public:
		Forme(ulong _couleur, uint _x, uint _y);
		Forme(const Forme& origine);
		Forme(istream& is);
		virtual ~Forme();
		inline ulong getCouleur() const {return couleur;}
		inline void setCouleur(ulong _couleur) { couleur = _couleur; }
		inline const Point getAncre() const {return ancre;}
		inline void setAncre(uint x, uint y) { ancre.setXY(x, y); }
		bool isOver (uint x, uint y) const;
		virtual void dessiner(EZWindow & fenetre, bool active=false) const;
		virtual double perimetre() const=0;
		virtual void ecrire(ostream  &os) const;
		friend ostream &operator<<(ostream  &os, const Forme& forme);
		static Forme * charger(istream &is);
};
#endif
