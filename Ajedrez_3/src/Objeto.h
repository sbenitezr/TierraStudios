#ifndef __OBJETO_H__
#define __OBJETO_H__

#include <iostream>
#include "herramientasgl.h"
#include "freeglut.h"

//LO ANTERIOR

/*class Objeto {
public:
	enum tipo_t { CASILLA_VACIA = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY};
	enum color_p {NO_COLOR = -1, BLANCO, NEGRO};
	void getNumCas(int& x, int& y) {}
	virtual tipo_t getTipo() = 0;
};*/

//LO NUEVO
enum tipo_t { CASILLA_VACIA = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY };;
enum color_p { NO_COLOR = -1, BLANCO, NEGRO };;


class Objeto {
protected:
	tipo_t tipoPieza;
	color_p colorPieza;

public:
	color_p getColor() const { return colorPieza; }
	tipo_t getPieza() const { return tipoPieza; }

};


#endif