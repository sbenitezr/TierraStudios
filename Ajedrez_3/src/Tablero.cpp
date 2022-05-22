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

bool Tablero::enable(int x1, int x2, int y1, int y2, int color, int color2) {
	if (((x2 || y2) < 0) || ((x2 || y2) > 7) || (x2 == x1) && (y2 == y1)) { return FALSE; }
	else if (color == color2) { return FALSE; }
	else { return TRUE; }
}
bool Tablero::movalfil(int x1, int x2, int y1, int y2, int color, int color2) {
	int dif = abs(x2 - x1);
	if (abs(y2 - y1) != dif) return FALSE;
	else { return TRUE; }

}
bool Tablero::movtorre(int x1, int x2, int y1, int y2, int color, int color2) {
	if ((abs(x2 - x1) != 0) && abs(y2 - y1) != 0)
		return FALSE;
	else {
		cout << "Primer else" << endl;
		if (y1 == y2) {
			cout << "Primer if" << endl;
			if (x2 > x1) {
				//cout << "Segundo if" << endl;
				int acum = 0;
				for (int i = (x1 + 1); i < x2; i++) {
					int col = getCas()[i][y1].getPieza()->getTipo();
					//cout << "posintcall:" <<col<< endl;
					if (col != -1)
						acum++;
					//cout << acum << endl;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
			else if (x2 < x1) {
				int acum = 0;
				//cout << "Segundo else if" << endl;
				for (int i = (x1 - 1); i > x2; i--) {
					int col = getCas()[i][y1].getPieza()->getTipo();
					cout << "posincall:" << col << endl;
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
		}
		else if (x1 == x2) {
			int acum = 0;
			cout << "Primer else if:" << endl;
			if (y2 > y1) {
				cout << "Segundo if" << endl;
				for (int i = (y1 + 1); i < y2; i++) {
					int col = getCas()[x1][i].getPieza()->getTipo();
					cout << "pisincall:" << col << endl;
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
			else if (y2 < y1) {
				for (int i = (y1 - 1); i > y2; i--) {
					int col = getCas()[x1][i].getPieza()->getTipo();
					cout << col << endl;
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
			else { return FALSE; }
		}
		else { return FALSE; }
	}
}
bool Tablero::movcaballo(int x1, int x2, int y1, int y2, int color, int color2) {
	int dif = abs(x2 - x1);
	if ((dif > 3) || (dif < 1))
		return FALSE;
	else if ((dif == 1) && (abs(y2 - y1) != 2) || (dif == 2) && (abs(y2 - y1) != 1))
		return FALSE;
	else { return TRUE; }
}
bool Tablero::movrey(int x1, int x2, int y1, int y2, int color, int color2) {
	if (abs(x2 - x1) > 1 || abs(y2 - y1) > 1)
		return FALSE;
	else { return TRUE; }
}
bool Tablero::movpeon(int x1, int x2, int y1, int y2, int color, int color2) {
	if ((x1 == 1) || (x1 == 6)) {
		if (color == Pieza::BLANCO) {
			if ((color2 == Pieza::NO_COLOR) && ((y2 - y1) == 0) && (((x2 - x1) == -2) || (x2 - x1) == -1))
				return TRUE;
			else if ((color2 == Pieza::NEGRO) && ((x2 - x1) == -1) && (abs(y2 - y1) == 1))
				return TRUE;
			else
				return FALSE;
		}
		else if (color == Pieza::NEGRO) {
			if ((color2 == Pieza::NO_COLOR) && ((y2 - y1) == 0) && (((x2 - x1) == 2) || (x2 - x1) == 1)) { return TRUE; }
			else if ((color2 == Pieza::BLANCO) && ((x2 - x1) == 1) && (abs(y2 - y1) == 1)) { return TRUE; }
			else { return FALSE; }
		}
		else { return FALSE; }
	}
	else {
		if (color == Pieza::BLANCO) {
			if ((color2 == Pieza::NO_COLOR) && ((y2 - y1) == 0) && ((x2 - x1) == -1)) { return TRUE; }
			else if ((color2 == Pieza::NEGRO) && ((x2 - x1) == -1) && (abs(y2 - y1) == 1)) { return TRUE; }
			else { return FALSE; }
		}
		else if (color == Pieza::NEGRO) {
			if ((color2 == Pieza::NO_COLOR) && ((y2 - y1) == 0) && ((x2 - x1) == 1)) { return TRUE; }
			else if ((color2 == Pieza::BLANCO) && ((x2 - x1) == 1) && (abs(y2 - y1) == 1)) { return TRUE; }
			else { return FALSE; }
		}
	}
}