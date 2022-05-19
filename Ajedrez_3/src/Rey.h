#ifndef __REY_H__
#define __REY_H__
#include "TableroGL.h"
#include "Pieza.h"

class Rey :public Pieza {
private:
	tipo_t tipo;
	color_p color;
	Vector pos;
protected:
	//Definicion de Sprite
	SpriteSequence spritereyN{ "imagenes/rey_negro.png", 1 };
	SpriteSequence spritereyB{ "imagenes/rey_blanco.png", 1 };
public:
	Rey(Vector p, color_p c) :pos(p), tipo(REY), color(c) {}

	void draw();
};

#endif 