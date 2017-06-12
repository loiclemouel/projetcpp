#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Forme.hpp"
#include <cmath>

typedef unsigned int uint;
typedef unsigned long int ulong;

class Ellipse : public Forme {
	private:
		uint demilargeur;
		uint demihauteur;
		void ecrire(ostream & os) const override;

	public:
		Ellipse(uint _epaisseurk, ulong _couleur, uint _x, uint _y, uint _demilargeur, uint _demihauteur);
		Ellipse(istream & is);
		~Ellipse();
		virtual void dessiner(EZWindow & fenetre, bool isActive=false) const;
		inline uint getDemiLargeur() const { return demilargeur; }
		inline void setDemiLargeur(uint _demilargeur) { demilargeur = _demilargeur; }
		inline uint getDemiHauteur() const { return demihauteur; }
		inline void setDemiHauteur(uint _demihauteur) { demihauteur = _demihauteur; }
		double perimetre() const override ;
};
#endif
