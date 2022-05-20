#include "Tablero.h"

Tablero::Tablero(int n) :N(n){
	cas = new Casilla * [N];
	for (int i = 0; i < N; i++)
	{
		cas[i] = new Casilla[N];
	}
}
void Tablero::tableroInicio() {

	//INICIALIZAMOS TODAS LAS CASILLAS CON PIEZAS VACIAS
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cas[i][j].setPieza(new NoPieza(Vector(i, j)));
		}
	}

	//Inicializacion Piezas Negras
	for (int j = 0; j < N; j++)
	{
		cas[1][j].setPieza(new Peon(Vector(1, j), Pieza::NEGRO));
	}
	Pieza* RN = cas[0][4].setPieza(new Reina(Vector(0, 4), Pieza::NEGRO));		//necesitamos que esta variable no sea local para usarla en TableroGl y poder asignarle la nueva posicion del click 
	//cas[0][4].setPieza(new Reina(Vector(0, 4), Pieza::NEGRO));
	cas[0][3].setPieza(new  Rey(Vector(0, 3), Pieza::NEGRO));
	cas[0][0].setPieza(new Torre(Vector(0, 0), Pieza::NEGRO));
	cas[0][N - 1].setPieza(new Torre(Vector(0, N - 1), Pieza::NEGRO));
	cas[0][1].setPieza(new Caballo(Vector(0, 1), Pieza::NEGRO));
	cas[0][N - 2].setPieza(new Caballo(Vector(0, N - 2), Pieza::NEGRO));
	cas[0][2].setPieza(new Alfil(Vector(0, 2), Pieza::NEGRO));
	cas[0][N - 3].setPieza(new Alfil(Vector(0, N - 3), Pieza::NEGRO));

	//Inicializacion Piezas Blancas
	for (int j = 0; j < N; j++)
	{
		cas[N - 2][j].setPieza(new Peon(Vector(1, j), Pieza::BLANCO));
	}
	cas[N - 1][4].setPieza(new Reina(Vector(0, 4), Pieza::BLANCO));
	cas[N - 1][3].setPieza(new  Rey(Vector(0, 3), Pieza::BLANCO));
	cas[N - 1][0].setPieza(new Torre(Vector(0, 0), Pieza::BLANCO));
	cas[N - 1][N - 1].setPieza(new Torre(Vector(0, N - 1), Pieza::BLANCO));
	cas[N - 1][1].setPieza(new Caballo(Vector(0, 1), Pieza::BLANCO));
	cas[N - 1][N - 2].setPieza(new Caballo(Vector(0, N - 2), Pieza::BLANCO));
	cas[N - 1][2].setPieza(new Alfil(Vector(0, 2), Pieza::BLANCO));
	cas[N - 1][N - 3].setPieza(new Alfil(Vector(0, N - 3), Pieza::BLANCO));
}