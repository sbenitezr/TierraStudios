#ifndef __COLORCASILLA_H__
#define __COLORCASILLA_H__
#include "freeglut.h"
typedef unsigned char Byte;

class ColorCas {
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	ColorCas(Byte r, Byte g, Byte b) : r(r), g(g), b(b){}
	ColorCas() : r(1), g(1), b(1) {}
	void setColor(unsigned char red, unsigned char green, unsigned char blue) { r = red; g = green; b = blue; }
};
#endif