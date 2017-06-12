#ifndef POINT_HPP
#define POINT_HPP

using namespace std;

#include <iostream>
#include "ez-draw++.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

class Point {
	private:
		static const uint taille=3;
		uint x,y;

	public:
		Point(uint x, uint y);
		Point(const Point& orig);
		Point(istream& is);
		~Point();
		inline uint getX() const {return x;};
		inline uint getY() const {return y;};
		inline void setXY(uint _x, uint _y) { x = _x; y = _y; }
		bool isOver(uint _x, uint _y) const;
		void dessiner(EZWindow& fenetre, bool isActive=false) const;
		friend ostream &operator<<(ostream& os, const Point &p);
		friend istream &operator>>(istream& is, Point& p);
};
#endif
