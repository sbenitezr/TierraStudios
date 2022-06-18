#ifndef __REY_H__
#define __REY_H__
#include "TableroGL.h"
#include "Pieza.h"

class Rey :public Pieza {
protected:
	//Definicion de Sprite
	SpriteSequence spritereyN{ "imagenes/rey_negro.png", 1 };
	SpriteSequence spritereyB{ "imagenes/rey_blanco.png", 1 };

	/*
	//MODELO NUEVO
	SpriteSequence spritereyN{ "imagenes/reyNegro.png", 1 };
	SpriteSequence spritereyB{ "imagenes/reyBlanco.png", 1 };

	//MODELO ETSIDI
	SpriteSequence spritereyN{ "imagenes/reyNegroETSIDI.png", 1 };
	SpriteSequence spritereyB{ "imagenes/reyBlancoETSIDI.png", 1 };
	*/

public:
	Rey(Vector p, color_p c) { pos = p; tipo = REY; color = c; }
	void draw();
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
};

#endif 