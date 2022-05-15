#include <stdio.h>
#include <iostream>
#include<math.h>
using namespace std;
//En este código se comprobará el correcto movimiento de las piezas según su tipo
enum color {WHITE, BLACK, NONE};
enum pieza{PEON,ALFIL,CABALLO,TORRE,DAMA,REY};
char tablero[7][7];
//void tabin();
//void tabpint();
//void movpieza();
int movrey(int&, int&, int&, int&);
int movtorre(int&, int&, int&, int&);
int movalfil(int&, int&, int&, int&);
int movcaballo(int&, int&, int&, int&);
int movreina(int&, int&, int&, int&);
int main() {
	//Definicion de posiciones iniciales y finales
	int i1, j1;
	int i2, j2;
	int enableglobal = 0;
	int mov = 1;
	int c_reyb = 0,c_reyn=0, c_peon=0;
	do {
		//bool tablas = false, mate = false;
		//void tabin();
		cout << "Movimiento numero " << mov <<":"<< endl;
		do {
			int enablerey = movrey(i1, j1, i2, j2);
			enableglobal = enablerey;
			if (enablerey == 0)
				cout << "Movimiento ilegal, repita su movimiento" << endl;
		}while (enableglobal == 0);
		mov++;
	} while (mov !=100);//bucle que repite la secuencia hasta que se alcanzan 100 movimientos, tablas o mate.
}
	int movrey(int& i1, int& i2, int& j1, int& j2)
	{
		cout << "Introduzca sus coordenadas inciales"<< endl;
		cin >> i1;
		cin >> j1;
		cout << "Introduzca sus coordenadas finales" << endl;
		cin >> i2;
		cin >> j2;
		if (abs(i2 - i1) > 1 || abs(j2 - j2) > 1)
			return 0;
		else if ((i2 or j2) < 0 || (i2 or j2) > 7)
			return 0;
		else
			return 1;
	}

	int movtorre(int& i1, int& i2, int& j1, int& j2)
	{
		cout << "Introduzca sus coordenadas inciales" << endl;
		cin >> i1;
		cin >> j1;
		cout << "Introduzca sus coordenadas finales" << endl;
		cin >> i2;
		cin >> j2;
		if (abs(i2 - i1) != 0 && abs(j2 - j1) != 0)
			return 0;
		else if ((i2 or j2) < 0 || (i2 or j2) > 7)
			return 0;
		else
			return 1;
	}
	int movalfil(int& i1, int& i2, int& j1, int& j2)
	{
		cout << "Introduzca sus coordenadas inciales" << endl;
		cin >> i1;
		cin >> j1;
		cout << "Introduzca sus coordenadas finales" << endl;
		cin >> i2;
		cin >> j2;
		int dif = abs(i2 - i1);
		if (abs(j2 - j1) != dif)
			return 0;
		else if ((i2 or j2) < 0 || (i2 or j2) > 7)
			return 0;
		else
			return 1;
	}
	int movcaballo(int& i1, int& i2, int& j1, int& j2)
	{
		cout << "Introduzca sus coordenadas inciales" << endl;
		cin >> i1;
		cin >> j1;
		cout << "Introduzca sus coordenadas finales" << endl;
		cin >> i2;
		cin >> j2;
		int dif = abs(i2 - i1);
		if ((dif != 1) || (dif != 2))
			return 0;
		if ((dif == 1 && (j2 - j1) != 2) || (dif == 2 && (j2 - j1) != 1))
			return 0;
		else if ((i2 or j2) < 0 || (i2 or j2) > 7)
			return 0;
		else
			return 1;
	}
	int movreina(int& i1, int& i2, int& j1, int& j2)
	{
		int enablequeen1 = movalfil(i1, i2, j1, j2);
		int enablequeen2 = movtorre(i1, i2, j1, j2);
		if (enablequeen1 == 1 || enablequeen2 == 1)
			return 1;
		else
			return 0;
	}