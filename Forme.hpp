#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

const double PI = 3.14;

class Forme {
	private:
		ulong couleur;
		Point ancre;
		bool remplissage=false;
		uint epaisseur;

	public:
		Forme(uint epaisseur,ulong couleur, uint x, uint y);
		Forme(const Forme& orig);
		Forme(istream& is);
		virtual ~Forme();
		inline ulong getCouleur() const {return couleur;}
		inline void setCouleur(ulong _couleur) { couleur = _couleur; }
		inline uint getEpaisseur() const {return epaisseur;}
		inline void setEpaisseur(uint _epaisseur) {epaisseur = _epaisseur;}
		inline void plusEpaisseur(){epaisseur++;}
		inline void moinsEpaisseur(){epaisseur--;}
		inline bool getRemplissage() const {return remplissage;}
		inline void setRemplissage(bool _remplissage) {remplissage = _remplissage;}
		inline const Point getAncre() const {return ancre;}
		inline void setAncre(uint _x, uint _y) { ancre.setXY(_x, _y); }
		bool isOver (uint _x, uint _y) const;
		virtual void dessiner(EZWindow & fenetre, bool active=false) const;
		virtual double perimetre() const=0;
		virtual void ecrire(ostream  &os) const;
		friend ostream &operator<<(ostream  &os, const Forme& forme);
		static Forme * charger(istream &is);
};
#endif
