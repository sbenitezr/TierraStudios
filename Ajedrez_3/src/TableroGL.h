#ifndef __TABLERO_GL_H__
#define __TABLERO_GL_H__

#include <string>
#include <vector>
#include "Tablero.h"
#include "Pieza.h"
#include "ETSIDI.h"
#include "Casilla.h"

using ETSIDI::SpriteSequence;
using namespace std;

//Enumeraciones para no escribir sobre comandos de la glut
enum { MOUSE_LEFT_BUTTON, MOUSE_RIGHT_BUTTON, MOUSE_MIDDLE_BUTTON };
enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class TableroGL {
public:
	int i = 8;
	int j = 8;
	Casilla casilla[8][8];

	TableroGL(Tablero* t) :m_tablero(t) {
		ancho = 1; //0.15
		N = t->getTamanio();
		dist = 2;
		centro_z = 0;
	}

	enum Modo { INICIO, JUGAR, FINAL };
	Modo modo;
	virtual ~TableroGL() {}
	TableroGL();

	//Inicializacion
	void init();

	//Gestor de eventos
	void draw();
	void drawMatriz();
	void drawCasillaIni(int i, int j);
	void drawCasilla(Vector a);
	void tecla(unsigned char key);

	//void KeyDown(unsigned char key);
	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);

	//Info REVISAAAAAAAAAAR*********************************************************************************************
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
		cas_y = (int)(abs(x / ancho));
	}
	
protected:
	float ancho;
	int N; //Tamanio
	Tablero* m_tablero;

	double centro_x, centro_y, centro_z;
	double dist;

	//Seleccion de casilla con el raton
	int xcas_sel, ycas_sel; 

	//int tipo;
	bool controlKey;
	bool shiftKey;
	bool leftButton;
	bool rightButton;
	bool midButton;

	bool seleccion = FALSE;
	bool inicio = TRUE;


	//Definicion mediante Sprite de todas las imágenes de las piezas
	SpriteSequence spritepeonN{ "imagenes/peon_negro.png", 1 };
	SpriteSequence spritetorreN{ "imagenes/torre_negro.png", 1 };
	SpriteSequence spritereinaN{ "imagenes/reina_negro.png", 1 };
	SpriteSequence spritealfilN{ "imagenes/alfil_negro.png", 1 };
	SpriteSequence spritereyN{ "imagenes/rey_negro.png", 1 };
	SpriteSequence spritecaballoN{ "imagenes/caballo_negro.png", 1 };

	SpriteSequence spritepeonB{ "imagenes/peon_blanco.png", 1 };
	SpriteSequence spritetorreB{ "imagenes/torre_blanco.png", 1 };
	SpriteSequence spritereinaB{ "imagenes/reina_blanco.png", 1 };
	SpriteSequence spritealfilB{ "imagenes/alfil_blanco.png", 1 };
	SpriteSequence spritereyB{ "imagenes/rey_blanco.png", 1 };
	SpriteSequence spritecaballoB{ "imagenes/caballo_blanco.png", 1 };
};

#endif