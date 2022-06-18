#ifndef __ALFIL_H__
#define __ALFIL_H__
#include "TableroGL.h"
#include "Pieza.h"

class Alfil :public Pieza {
protected:
	//Definicion de Sprite
	SpriteSequence spritealfilB{ "imagenes/alfil_blanco.png", 1 };
	SpriteSequence spritealfilN{ "imagenes/alfil_negro.png", 1 };

	/*
	//MODELO NUEVO
	SpriteSequence spritealfilB{ "imagenes/alfilBlanco.png", 1 };
	SpriteSequence spritealfilN{ "imagenes/alfilNegro.png", 1 };

	//MODELO ETSIDI
	SpriteSequence spritealfilB{ "imagenes/alfilBlancoETSIDI.png", 1 };
	SpriteSequence spritealfilN{ "imagenes/alfilNegroETSIDI.png", 1 };
	*/

public:
	Alfil(Vector p, color_p c) { pos = p; tipo = ALFIL; color = c; }
	void draw();
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	friend class TableroGL;
};
#endif 