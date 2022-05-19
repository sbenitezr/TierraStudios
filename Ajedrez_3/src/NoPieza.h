#ifndef __NOPIEZA_H__
#define __NOPIEZA_H__
#include "TableroGL.h"
#include "Pieza.h"

class NoPieza :public Pieza {
private:
	tipo_t tipo;
	color_p color;
	Vector pos;
public:
	NoPieza(Vector p) :pos(p), tipo(CASILLA_VACIA), color(NO_COLOR) {}
	void draw() { return; }
};
#endif