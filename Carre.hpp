#ifndef CARRE_HPP
#define CARRE_HPP

#include "Forme.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

class Carre : public Forme {
  private:
    uint longueur;
    void ecrire(ostream & os) const override;

  public:
    Carre(uint _epaisseur, ulong _couleur, uint _x, uint _y, uint _longueur);
    Carre(istream & is);
    ~Carre();
    virtual void dessiner(EZWindow & fenetre, bool isActive=false) const;
    inline uint getLongueur() const { return longueur; }
    inline void setLongueur(uint _longueur) { longueur = _longueur; }
    double perimetre() const override;
};
#endif
