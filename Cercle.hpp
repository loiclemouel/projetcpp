#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

class Cercle : public Forme {
  private:
    uint rayon;
    void ecrire(ostream & os) const override;

  public:
    Cercle(uint _epaisseur, ulong _couleur, uint _x, uint _y, uint _rayon);
    Cercle(istream & is);
    ~Cercle();
    virtual void dessiner(EZWindow & fenetre, bool isActive=false) const;
    inline uint getRayon() const { return rayon; }
    inline void setRayon(uint _rayon) { rayon = _rayon; }
    double perimetre() const override;
};
#endif
