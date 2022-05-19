#ifndef __TORRE_H__
#define __TORRE_H__

#include "Objeto.h"
#include "TableroGL.h"

class Torre :public Objeto {

public:
	Torre(color_p _color, int _x, int _y);
	Torre() {};
	~Torre() {};

	void Dibuja();
	void Color();
	//bool movValido(int destX, int destY, ColorPieza c);
	//Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);


	//Definicion de Sprite
	SpriteSequence spritetorreB{ "imagenes/torre_blanco.png", 1 };
	SpriteSequence spritetorreN{ "imagenes/torre_negro.png", 1 };
};

#endif