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
	Tablero(int n) :N(n) {
		tab = new Pieza * [N];
		for (int i = 0; i < N; i++)
		{
			tab[i] = new Pieza[N];
		}
		for (int j = 0; j < N; j++)
		{
			tab[0][j].setCas(0, j, Pieza::REINA_NEGRO);
		}
		for (int j = 0; j < N; j++)
		{
			tab[N - 1][j].setCas(0, j, Pieza::REINA_BLANCO);
		}
	}

	~Tablero() {
		for (int i = 0; i < N; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
	}
	int getTamanio() { return N; }
	Pieza** getTab() { return tab; }
};
#endif