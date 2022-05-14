#ifndef __OBJETO_H__
#define __OBJETO_H__

#include <iostream>
#include "herramientasgl.h"
#include "freeglut.h"

class Objeto {
public:
	enum tipo_t { CASILLA_VACIA = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY};
	enum color_p {NO_COLOR = -1, BLANCO, NEGRO};
	void getNumCas(int& x, int& y) {}
	virtual tipo_t getTipo() = 0;
};
#endif