#ifndef __PIEZA_H__
#define __PIEZA_H__

#include <iostream>
#include "herramientasgl.h"
#include "freeglut.h"
#include "Objeto.h"
using namespace std;

class Pieza : public Objeto{
public:
protected:
	int x;
	int y;
	tipo_t tipo;
	color_p color;
public:
	Pieza() :x(-1), y(-1), tipo(CASILLA_VACIA), color(NO_COLOR) {}
	void setCas(int x, int y, tipo_t t, color_p c) { this->x = x; this->y = y; this->tipo = t; this->color = c; }
	void getNumCas(int& x, int& y) { x = this->x; y = this->y; }
	virtual tipo_t getTipo() { return tipo; }
	virtual color_p getColor() { return color; }
};
#endif