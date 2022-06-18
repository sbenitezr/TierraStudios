#ifndef __NOPIEZA_H__
#define __NOPIEZA_H__
#include "TableroGL.h"
#include "Pieza.h"

class NoPieza :public Pieza {
public:
	NoPieza(Vector p) { pos = p; tipo = CASILLA_VACIA; color = NO_COLOR; }
	void draw() { return; }
	static bool mover(Vector pos1, Vector pos2, int color, int color2) { return FALSE; }
};
#endif