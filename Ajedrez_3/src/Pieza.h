#ifndef __PIEZA_H__
#define __PIEZA_H__

#include <iostream>
#include "herramientasgl.h"
#include "freeglut.h"
#include "Objeto.h"
#include "Vector2D.h"

using namespace std;

class Pieza : public Objeto{
protected:
	Vector pos;
	Vector pos2;
	tipo_t tipo;
	color_p color;
public:
	Pieza() :pos(-1, -1), pos2(pos), tipo(CASILLA_VACIA), color(NO_COLOR) {}
	void setCas(Vector p) { this->pos; }
	void setPos2(Vector p) { this->pos2; }
	void setCas(Vector p, tipo_t t, color_p c) { this->pos = p; this->tipo = t; this->color = c; }
	void getNumCas(Vector& p) { p = this->pos; }
	Vector getNumCas2() { return pos2; }
	virtual tipo_t getTipo() { return tipo; }
	virtual color_p getColor() { return color; }
};
#endif