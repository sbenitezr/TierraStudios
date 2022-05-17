#include "Tablero.h"

Tablero::Tablero(int n) :N(n){
	tab = new Pieza * [N];
	for (int i = 0; i < N; i++)
	{
		tab[i] = new Pieza[N];
	}
}
void Tablero::tableroInicio() {
	for (int j = 0; j < N; j++)
	{
		tab[1][j].setCas(Vector(0, j), Pieza::PEON, Pieza::NEGRO);
	}
	tab[0][4].setCas(Vector(0, 4), Pieza::REINA, Pieza::NEGRO);
	tab[0][3].setCas(Vector(0, 3), Pieza::REY, Pieza::NEGRO);
	tab[0][0].setCas(Vector(0, 0), Pieza::TORRE, Pieza::NEGRO);
	tab[0][N - 1].setCas(Vector(0, N - 1), Pieza::TORRE, Pieza::NEGRO);
	tab[0][1].setCas(Vector(0, 1), Pieza::CABALLO, Pieza::NEGRO);
	tab[0][N - 2].setCas(Vector(0, N - 2), Pieza::CABALLO, Pieza::NEGRO);
	tab[0][2].setCas(Vector(0, 2), Pieza::ALFIL, Pieza::NEGRO);
	tab[0][N - 3].setCas(Vector(0, N - 3), Pieza::ALFIL, Pieza::NEGRO);
	for (int j = 0; j < N; j++)
	{
		tab[N - 2][j].setCas(Vector(0, j), Pieza::PEON, Pieza::BLANCO);
	}
	tab[N - 1][4].setCas(Vector(0, 4), Pieza::REINA, Pieza::BLANCO);
	tab[N - 1][3].setCas(Vector(0, 3), Pieza::REY, Pieza::BLANCO);
	tab[N - 1][0].setCas(Vector(0, 0), Pieza::TORRE, Pieza::BLANCO);
	tab[N - 1][N - 1].setCas(Vector(0, N - 1), Pieza::TORRE, Pieza::BLANCO);
	tab[N - 1][1].setCas(Vector(0, 1), Pieza::CABALLO, Pieza::BLANCO);
	tab[N - 1][N - 2].setCas(Vector(0, N - 2), Pieza::CABALLO, Pieza::BLANCO);
	tab[N - 1][2].setCas(Vector(0, 2), Pieza::ALFIL, Pieza::BLANCO);
	tab[N - 1][N - 3].setCas(Vector(0, N - 3), Pieza::ALFIL, Pieza::BLANCO);
}
void Tablero::tableroSetPieza(int i, int j, Vector v) {
	tab[i][j].setCas(v);
}