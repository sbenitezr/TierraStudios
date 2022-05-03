#ifndef __PIEZA_H__
#define __PIEZA_H__

#include <iostream>
#include "herramientasgl.h"
#include "freeglut.h"
using namespace std;

class Objeto {
public:
	enum tipo_t { CASILLA_VACIA = -1, REINA_BLANCO, REINA_NEGRO };
	virtual void getNumCasilla(int& x, int& y) = 0;
	virtual tipo_t getTipo() = 0;
};
class Pieza : public Objeto {
public:

protected:
	int x;
	int y;
	tipo_t tipo;
public:
	Pieza() :x(-1), y(-1), tipo(CASILLA_VACIA) {}
	void setCas(int x, int y, tipo_t t) { this->x = x; this->y = y; this->tipo = t; }
	virtual void getNumCas(int& x, int& y) { x = this->x; y = this->y; }
	virtual tipo_t getTipo() { return tipo; }
};
#endif