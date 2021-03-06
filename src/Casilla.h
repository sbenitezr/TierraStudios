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
	~Casilla() { delete[] pieza; }
	void draw();
	void setPos(Vector pos){ this->posicion = pos; }
	Vector getPos() { return posicion; }
	Pieza* getPieza() { return pieza; }

	void setColor(int c) {
		if (c == 0)color.setColor(1, 1, 1);
		if (c == 1)color.setColor(222, 184, 135);
	}
	Pieza* setPieza(Pieza* pieza) { this->pieza = pieza;	return pieza; }
	
	//  PARA LA SOBRECARGA DEL SEGUNDO CLICK
	void creaPieza(int x, int y, int type, Pieza::color_p color);
}; 
#endif