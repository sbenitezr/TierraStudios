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
	int turnos;
	const int N;
	Casilla** cas;
	Pieza* pieza;
public:
	Tablero(int n);
	~Tablero() {
		/*for (int i = 0; i < N; i++)
		{
			delete[] cas[i];
		}
		delete[] cas;*/
	}
	void tableroInicio();
	int getTamanio() { return N; }
	Pieza* getPieza(){return pieza;}
	Casilla** getCas() { return cas; }
	friend class TableroGL;
};
#endif