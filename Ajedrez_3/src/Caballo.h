#ifndef __CABALLO_H__
#define __CABALLO_H__

#include "Objeto.h"
#include "TableroGL.h"

class Caballo :public Objeto {

public:
	Caballo(color_p _color, int _x, int _y);
	Caballo() {};
	~Caballo() {};

	void Dibuja();
	void Color();
	//bool movValido(int destX, int destY, ColorPieza c);
	//Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);


	//Definicion de Sprite
	SpriteSequence spritecaballoB{ "imagenes/caballo_blanco.png", 1 };
	SpriteSequence spritecaballoN{ "imagenes/caballo_negro.png", 1 };
};

#endif