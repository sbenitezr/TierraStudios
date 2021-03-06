#include "Tablero.h"

Tablero::Tablero(int n) :N(n){
	cas = new Casilla * [N];
	for (int i = 0; i < N; i++)
	{
		cas[i] = new Casilla[N];
	}
	turnos = 1;
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
	cas[0][4].setPieza(new Reina(Vector(0, 4), Pieza::NEGRO));
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

bool Tablero::jaque(int col) {
	int x2 = -2, y2 = -2, x = -2, y = -2, tipo2 = -2, tipo = -2, color = -2, color2 = -2, count = 0;
	for (int i2 = 0; i2 < 8; i2++) {
		for (int j2 = 0; j2 < 8; j2++) {
			color2 = getCas()[i2][j2].getPieza()->getColor();
			tipo2 = getCas()[i2][j2].getPieza()->getTipo();
			if (color2 == col && tipo2 == Pieza::REY && color2 > -1) {
				x2 = i2;
				y2 = j2;
			}
		}
	}
	color2 = col;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			color = getCas()[i][j].getPieza()->getColor();
			tipo = getCas()[i][j].getPieza()->getTipo();
			
			if (color != col && (color > -1)) {
				x = i;
				y = j;
				if (getCas()[x][y].getPieza()->mover(Vector(x, y), Vector(x2, y2), color, color2) == TRUE) { count++; }
			}
		}
	}
	if (count > 0) { return TRUE; }
	else { return FALSE; }
}

bool Tablero::enable(int x1, int x2, int y1, int y2, int color, int color2) {
	if (((x2 || y2) < 0) || ((x2 || y2) > 7) || (x2 == x1) && (y2 == y1)) { return FALSE; }
	else if (color == color2) { return FALSE; }
	else { return TRUE; }
}

bool Tablero::mate(int col) {
	
	if (jaque(col) == TRUE) {
		int valido = 0;
		int x2 = -2, y2 = -2, x = -2, y = -2, tipo2 = -2, tipo = -2, color = -2, color2 = -2;
		for (int i1 = 0; i1 < 8; i1++) {
			for (int j1 = 0; j1 < 8; j1++) {
				color = getCas()[i1][j1].getPieza()->getColor();
				tipo = getCas()[i1][j1].getPieza()->getTipo();

				if (color == col) {
					x = i1;
					y = j1;

					for (int i2 = 0; i2 < 8; i2++) {
						for (int j2 = 0; j2 < 8; j2++) {
							color2 = getCas()[i2][j2].getPieza()->getColor();
							if (color2 != col && (getCas()[x][y].getPieza()->mover(Vector(x, y), Vector(i2, j2), color, color2) == TRUE) && color2 > -2) {
								int tipoPieza = getCas()[i2][j2].getPieza()->getTipo();
								Pieza::color_p color = getCas()[x][y].getPieza()->getColor();
								Pieza::color_p color2 = getCas()[i2][j2].getPieza()->getColor();

								getCas()[x][y].~Casilla();
								getCas()[x][y].creaPieza(x, y, -1, Pieza::NO_COLOR);
								getCas()[i2][j2].~Casilla();
						
								if (col == 1) {

									if ((color == 0)) { getCas()[i2][j2].creaPieza(i2 - 7, j2, tipo, color); }
									else if (color == 1) { getCas()[i2][j2].creaPieza(-i2, j2, tipo, color); }
									else if (color == -1) { getCas()[i2][j2].creaPieza(i2, j2, tipo, color); }


									if (jaque(col) == FALSE) {
										cout << "Puedes mover a: ";
										getCas()[i2][j2].getPieza()->coutPieza(i2 + 1, j2 + 1, color, (Pieza::tipo_t)tipo); 
										cout << endl;
										valido++;
									}

									getCas()[i2][j2].~Casilla();

									if (color2 == 0) { getCas()[i2][j2].creaPieza(i2 - 7, j2, tipoPieza, color2); }
									else if (color2 == 1) { getCas()[i2][j2].creaPieza(-i2, j2, tipoPieza, color2); }
									else if (color2 == -1) { getCas()[i2][j2].creaPieza(i2, j2, tipoPieza, color2); }

									getCas()[x][y].~Casilla();

									if (color == 0) { getCas()[x][y].creaPieza(x - 7, y, tipo, color); }
									else if (color == 1) { getCas()[x][y].creaPieza(-x, y, tipo, color); }
									else if (color == -1) { getCas()[x][y].creaPieza(x, y, tipo, color); }
								}
								//////////////////////////////////////////////////////////
								if (col == 0) {

									if (color == 0) { getCas()[i2][j2].creaPieza(i2 - 5, j2, tipo, color); }
									else if (color == 1) { getCas()[i2][j2].creaPieza(i2, j2, tipo, color); }
									else if (color == -1) { getCas()[i2][j2].creaPieza(i2, j2, tipo, color); }


									if (jaque(col) == FALSE) {
										cout << "Puedes mover a: ";
										getCas()[i2][j2].getPieza()->coutPieza(i2 + 1, j2 + 1, color, (Pieza::tipo_t)tipo);
										cout << endl;
										valido++;
									}
									getCas()[i2][j2].~Casilla();

									if (color2 == 0) { getCas()[i2][j2].creaPieza(i2 - 7, j2, tipoPieza, color2); }
									else if (color2 == 1) { getCas()[i2][j2].creaPieza(-i2, j2, tipoPieza, color2); }
									else if (color2 == -1) { getCas()[i2][j2].creaPieza(i2, j2, tipoPieza, color2); }

									getCas()[x][y].~Casilla();

									if ((color == 0)) { getCas()[x][y].creaPieza(x - 7, y, tipo, color); }
									else if (color == 1) { getCas()[x][y].creaPieza(-x, y, tipo, color); }
									else if (color == -1) { getCas()[x][y].creaPieza(x, y, tipo, color); }
						
								}
							}
						}
					}
				} 
			}
		}
		cout << "El numero de movimientos posile es:" << valido << endl;
		if (valido == 0) {	
			cout << "JAQUE MATE" << endl;
			return TRUE; 
		}
		else { return FALSE; }
	}
	else { return FALSE; }
}