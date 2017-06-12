#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

class Rectangle : public Forme {
	private:
		uint largeur;
		uint hauteur;
		void ecrire(ostream & os) const override;

	public:
		Rectangle(uint _eppaisseur, ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur);
		Rectangle(istream & is);
		~Rectangle();
		virtual void dessiner(EZWindow & fenetre, bool isActive=false) const;
		inline uint getLargeur() const { return largeur; }
		inline void setLargeur(uint _largeur) { largeur = _largeur; }
		inline uint getHauteur() const { return hauteur; }
		inline void setHauteur(uint _hauteur) { hauteur = _hauteur; }
		double perimetre() const override ;
};
#endif
