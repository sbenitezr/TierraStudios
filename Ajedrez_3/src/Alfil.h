#ifndef __ALFIL_H__
#define __ALFIL_H__
#include "TableroGL.h"
#include "Pieza.h"

class Alfil :public Pieza {
private:
	tipo_t tipo;
	color_p color;
	Vector pos;
protected:
	//Definicion de Sprite
	SpriteSequence spritealfilB{ "imagenes/alfil_blanco.png", 1 };
	SpriteSequence spritealfilN{ "imagenes/alfil_negro.png", 1 };
public:
	Alfil(Vector p, color_p c) :pos(p), tipo(ALFIL),  color(c) {}

	void draw();
};
#endif 