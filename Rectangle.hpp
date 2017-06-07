#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "MyWindow.cpp"
#include "Forme.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

class Rectangle : public Forme {
	private:
		uint largeur;
		uint hauteur;
		void ecrire(ostream & os) const override;
	public:
		Rectangle(ulong couleur, uint x, uint y, uint largeur, uint hauteur);
		Rectangle(istream & is);
		~Rectangle();
		virtual void dessiner(EZWindow & fenetre, bool isActive=false);
		inline uint getLongueur() const {return largeur};
		inline uint setLargeur(uint _largueur) {return largueur};
		inline void setLargeur(uint _largeur) {largueur= _largeur};
		inline uint getHauteur() const {return hauteur};
		inline void setHauteur(uint _hauteur) {hauteur = _lhauteur};
		void double perimetre() const override;
};
#endif
