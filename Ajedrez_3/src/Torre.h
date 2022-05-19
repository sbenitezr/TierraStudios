#ifndef __TORRE_H__
#define __TORRE_H__
#include "TableroGL.h"
#include "Pieza.h"

class Torre :public Pieza {
private:
	tipo_t tipo;
	color_p color;
	Vector pos;
protected:
	//Definicion de Sprite
	SpriteSequence spritetorreB{ "imagenes/torre_blanco.png", 1 };
	SpriteSequence spritetorreN{ "imagenes/torre_negro.png", 1 };
public:
	Torre(Vector p, color_p c) :pos(p), tipo(TORRE), color(c) {}

	void draw();
};
#endif