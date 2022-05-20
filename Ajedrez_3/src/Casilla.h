#ifndef __CASILLA_H__
#define __CASILLA_H__

#include "Vector2D.h"
#include "TableroGL.h"
#include "Pieza.h"
#include "ColorCasilla.h"

class Casilla {
private:
	float ancho;
	Vector posicion;
	Pieza* pieza;
	ColorCas color;
public:
	Casilla() : posicion(Vector(-1, -1)), ancho(1.0f) {}

	void draw();
	void setPos(Vector pos){ this->posicion = pos; }
	Vector getPos() { return posicion; }
	Pieza* getPieza() { return pieza; }

	void setColor(int c) {
		if (c == 0)color.setColor(1, 1, 1);
		if (c == 1)color.setColor(222, 184, 135);
	}
	void setPieza(Pieza* pieza) { this->pieza = pieza; }
	void selCas() { color.setColor(255, 255, 255); }
};
#endif