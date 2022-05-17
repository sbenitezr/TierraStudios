#ifndef __OBJETO_H__
#define __OBJETO_H__

#include <iostream>
#include "herramientasgl.h"
#include "freeglut.h"

class Objeto {
public:
	//Enumeracion para el tipo de pieza o casilla vacia
	enum tipo_t { CASILLA_VACIA = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY};

	//Enumeracion para el color de la casilla o si no está seleccionando nada
	enum color_p {NO_COLOR = -1, BLANCO, NEGRO};

	void getNumCas(int& x, int& y) {}
	virtual tipo_t getTipo() = 0;
};
#endif