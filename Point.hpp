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
		~Point();
		Point(const Point& orig);
		Point(istream& is);
		inline int getX() const {return x;};
		inline int getY() const {return y;};
		void setXY(uint x, uint y);
		bool isOver(uint x, uint y) const;
		void dessiner(EZWindow& w, bool isActive=false) const;
		friend ostream operator<<(ostream& os, Point p);
		friend ostream operator>>(istream& is, Point& p);
};
#endif
