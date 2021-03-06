#ifndef __TABLERO_GL_H__
#define __TABLERO_GL_H__

#include "Tablero.h"
#include "Pieza.h"
#include "ETSIDI.h"
#include "Casilla.h"

using namespace std;

//Enumeraciones para no escribir sobre comandos de la glut
enum { MOUSE_LEFT_BUTTON, MOUSE_RIGHT_BUTTON, MOUSE_MIDDLE_BUTTON };
enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class TableroGL {
private:
	friend class Tablero;
	friend class Casilla;
protected:
	float ancho;
	int N; //Tamanio
	static Tablero* m_tablero;

	double centro_x, centro_y, centro_z;
	double dist;

	/*COORDENADAS*/
	int xcas_sel, ycas_sel;		//Seleccion de casilla con el raton
	int xorig, yorig;		//para guardar la casilla del primer click 

	/*BOTONES DEL TECLADO Y RATON*/
	bool controlKey;
	bool shiftKey;
	bool leftButton;

	/*VARIABLES NECESARIAS*/
	bool seleccion = FALSE;
	bool inicio = TRUE;
	bool fin = FALSE;
	bool paridad = FALSE;
	int modoAnterior = 0;

	enum Modo { INICIO, JUGAR1, JUGAR2, FINAL,PAUSA };

public:
	/*POR COMO FUNCIONAN LAS FUNCIONES DE MOVIMIENTO*/
	friend class Alfil;
	friend class Torre;
	friend class Reina;

	TableroGL(Tablero* t);

	Modo modo;

	/*INICIALIZACION*/
	void init();

	/*GESTOR DE EBENTOS*/
	void draw();
	void drawMatriz();
	void tecla(unsigned char key);


	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);

	void setTamanio(int tam) { N = tam; }
	int getTamanio() { return N; }

	/*COORDINADOR*/
	void casillaCentral(int cas_x, int cas_y, float& glx, float& gly) {
		//?OJO! cas_x, cas_y son las coordenadas de las casillas en el tablero, se pondra la superior izq como 0,0
		//glx, gly son el centro de cada casilla respecto a las coordenadas del mundo
		glx = cas_y * ancho + ancho / 2.0f;
		gly = cas_x * ancho - ancho / 2.0f;
	}

	void casillaMundo(double x, double y, int& cas_x, int& cas_y) {
		cas_x = (int)(abs(y / ancho));
		cas_y = (int)(abs(x / ancho));
	}

};

#endif