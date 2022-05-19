#ifndef __PEON_H__
#define __PEON_H__

#include "Objeto.h"
#include "TableroGL.h"

class Peon :public Objeto {

public:
	Peon(color_p _color, int _x, int _y);
	Peon() {};
	~Peon() {};

	void Dibuja();
	void Color();
	//bool movValido(int destX, int destY, ColorPieza c);
	//Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);


	//Definicion de Sprite
	SpriteSequence spritepeonN{ "imagenes/peon_negro.png", 1 };
	SpriteSequence spritepeonB{ "imagenes/peon_blanco.png", 1 };

};

#endif 