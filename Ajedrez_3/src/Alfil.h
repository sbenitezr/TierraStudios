#ifndef __ALFIL_H__
#define __ALFIL_H__

#include "Objeto.h"
#include "TableroGL.h"

class Alfil :public Objeto {

public:
	Alfil(color_p _color, int _x, int _y);
	Alfil() {};
	~Alfil() {};

	void Dibuja();
	void Color();
	//bool movValido(int destX, int destY, ColorPieza c);
	//Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);


	//Definicion de Sprite
	SpriteSequence spritealfilB{ "imagenes/alfil_blanco.png", 1 };
	SpriteSequence spritealfilN{ "imagenes/alfil_negro.png", 1 };

};

#endif 