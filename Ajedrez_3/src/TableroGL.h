#ifndef __TABLERO_GL_H__
#define __TABLERO_GL_H__

#include <string>
#include <vector>
#include "Tablero.h"
#include "Pieza.h"

//Enumeraciones para no escribir sobre comandos de la glut
enum { MOUSE_LEFT_BUTTON, MOUSE_RIGHT_BUTTON, MOUSE_MIDDLE_BUTTON };
enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

using namespace std;

class TableroGL {
public:
	TableroGL(Tablero* t) :m_tablero(t) {
		ancho = 0.15;
		N = t->getTamanio();
		dist = 2;
		centro_z = 0;
	}
	virtual ~TableroGL() {}

	//Inicializacion
	void init();
	//Gestor de eventos
	void draw();
	void drawMatriz();
	void drawCasilla(int i, int j);
	//void KeyDown(unsigned char key);
	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);
	//Info
	void setTamanio(int tam) { N = tam; }
	int getTamanio() { return N; }
	//Coordinador
	void casillaCentral(int cas_x, int cas_y, float& glx, float& gly) {
		//¡OJO! cas_x, cas_y son las coordenadas de las casillas en el tablero, se pondra la superior izq como 0,0
		//glx, gly son el centro de cada casilla respecto a las coordenadas del mundo
		glx = cas_y * ancho + ancho / 2.0f;
		gly = cas_x * ancho - ancho / 2.0f;
	}
	void casillaMundo(double x, double y, int& cas_x, int& cas_y) {
		cas_x = (int)(abs(y / ancho));
		cas_y = (int)(x / ancho);
	}
	

protected:
	float ancho;
	int N; //Tamanio
	Tablero* m_tablero;

	double centro_x, centro_y, centro_z;
	double dist;

	int xcas_sel, ycas_sel; //Seleccion de casilla con el raton

	//int tipo;

	bool controlKey;
	bool shiftKey;
	bool leftButton;
	bool rightButton;
	bool midButton;
};

#endif