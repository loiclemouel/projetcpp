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
		Forme(ulong couleur, uint x, uint y);
		Forme(const Forme& orig);
		Forme(istream& is);
		virtual ~Forme();
		inline ulong getCouleur() const {return couleur;};
		void setCouleur(ulong couleur);
		inline const Point getAncre() const {return ancre;};
		void setAncre(uint x, uint y);
		bool isOver (uint x, uint y) const;
		virtual void dessiner(EZWindow & fenetre, bool active=false) const;
		virtual double perimetre() const=0;
		friend ostream &operator<<(ostream  &os, const Forme& forme);
		virtual void ecrire(ostream  &os) const = 0;
		static Forme * charger(istream &is);
};
#endif
