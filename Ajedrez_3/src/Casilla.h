#ifndef __CASILLA_H__
#define __CASILLA_H__

#include "Vector2D.h"
#include "TableroGL.h"
#include "Pieza.h"

class Casilla {
private:
	float ancho;
	Vector posicion;
	Pieza* pieza;

public:
	Casilla() : posicion(Vector(-1, -1)), ancho(1.0f){}

	void drawN();
	void drawB();
	void setPos(Vector pos){ this->posicion = pos; }
	Vector getPos() { return posicion; }
	Pieza* getPieza() { return pieza; }

	void setPieza(Pieza* pieza) { this->pieza = pieza; }
};
#endif
