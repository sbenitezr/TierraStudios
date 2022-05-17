#ifndef __TABLERO_H__
#define __TABLERO_H__
#include <iostream>
#include "Pieza.h"

using namespace std;

class Tablero {
protected:
	const int N;
	Pieza ** tab;
public:
	Tablero(int n);
	~Tablero() {
		for (int i = 0; i < N; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
	}
	void tableroInicio();
	void tableroSetPieza(int i, int j, Vector v);
	int getTamanio() { return N; }
	Pieza** getTab() { return tab; }
};
#endif