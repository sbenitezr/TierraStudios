#ifndef __PIEZA_H__
#define __PIEZA_H__

#include <iostream>
#include "herramientasgl.h"
#include "freeglut.h"
#include "Vector2D.h"
#include "ETSIDI.h"

using namespace std;
using ETSIDI::SpriteSequence;

class Pieza {
public:
	enum tipo_t { CASILLA_VACIA = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY };
	enum color_p { NO_COLOR = -1, BLANCO, NEGRO };
	
protected:
	Vector pos;
	tipo_t tipo;
	color_p color;
public:

	Pieza() :pos(-1, -1), tipo(CASILLA_VACIA), color(NO_COLOR) {}

	void setCas(Vector p) { this->pos = p; }

	void getNumCas(Vector& p) { p = this->pos; }

	virtual void draw() = 0;

	tipo_t getTipo() { if (nullptr) return CASILLA_VACIA; else { return tipo; } }
	color_p getColor() { if (nullptr) return NO_COLOR; else { return color; } }
	Vector getPosicion() { return pos; }
	
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2) = 0;

	virtual void coutPieza(int x, int y, color_p color, tipo_t tipo) = 0;
};
#endif