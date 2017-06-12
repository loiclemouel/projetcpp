#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

class Triangle : public Forme {
	private:
		Point point1;
		Point point2;
		void ecrire(ostream & os) const override;

	public:
		Triangle(uint _thick, ulong _couleur, uint _x, uint _y, Point _point1, Point _point2);
		Triangle(istream & is);
		~Triangle();
		virtual void dessiner(EZWindow & fenetre, bool isActive=false) const;
		double perimetre() const override ;
};
#endif
