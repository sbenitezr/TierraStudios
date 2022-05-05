#include "Tablero.h"

Tablero::Tablero(int n) :N(n){
	tab = new Pieza * [N];
	for (int i = 0; i < N; i++)
	{
		tab[i] = new Pieza[N];
	}
	for (int  j = 0; j < N; j++)
	{
		tab[1][j].setCas(0, j, Pieza::PEON, Pieza::NEGRO);
	}
	tab[0][3].setCas(0, 3, Pieza::REINA, Pieza::NEGRO);
	tab[0][4].setCas(0, 4, Pieza::REY, Pieza::NEGRO);
	tab[0][0].setCas(0, 0, Pieza::TORRE, Pieza::NEGRO);
	tab[0][N - 1].setCas(0, N - 1, Pieza::TORRE, Pieza::NEGRO);
	tab[0][1].setCas(0, 1, Pieza::CABALLO, Pieza::NEGRO);
	tab[0][N-2].setCas(0, N-2, Pieza::CABALLO, Pieza::NEGRO);
	tab[0][2].setCas(0, 2, Pieza::ALFIL, Pieza::NEGRO);
	tab[0][N - 3].setCas(0, N - 3, Pieza::ALFIL, Pieza::NEGRO);
	for (int j = 0; j < N; j++)
	{
		tab[N - 2][j].setCas(0, j, Pieza::PEON, Pieza::BLANCO);
	}
	tab[N - 1][3].setCas(0, 3, Pieza::REINA, Pieza::BLANCO);
	tab[N - 1][4].setCas(0, 4, Pieza::REY, Pieza::BLANCO);
	tab[N - 1][0].setCas(0, 0, Pieza::TORRE, Pieza::BLANCO);
	tab[N - 1][N - 1].setCas(0, N - 1, Pieza::TORRE, Pieza::BLANCO);
	tab[N - 1][1].setCas(0, 1, Pieza::CABALLO, Pieza::BLANCO);
	tab[N - 1][N - 2].setCas(0, N - 2, Pieza::CABALLO, Pieza::BLANCO);
	tab[N - 1][2].setCas(0, 2, Pieza::ALFIL, Pieza::BLANCO);
	tab[N - 1][N - 3].setCas(0, N - 3, Pieza::ALFIL, Pieza::BLANCO);
}