#ifndef __TABLERO_H__
#define __TABLERO_H__
#include <iostream>
#include "Peon.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include "Reina.h"
#include "Torre.h"
#include "NoPieza.h"
#include "Casilla.h"

using namespace std;

class Tablero {
private:
	friend class Casilla;
protected:
	const int N;
	Casilla** cas;
	Pieza* pieza;
	int turnos;
public:
	friend class Alfil;
	Tablero(int n);
	~Tablero() {}
	void tableroInicio();
	int getTamanio() { return N; }
	Pieza* getPieza(){return pieza;}
	Casilla** getCas() { return cas; }
	friend class TableroGL;
	bool enable(int x1, int x2, int y1, int y2, int color, int color2);
	bool jaque(int col);
	bool mate(int col);
};
#endif