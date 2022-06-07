#ifndef __TORRE_H__
#define __TORRE_H__
#include "TableroGL.h"
#include "Pieza.h"

class Torre :public Pieza {

protected:
	//Definicion de Sprite
	SpriteSequence spritetorreB{ "imagenes/torre_blanco.png", 1 };
	SpriteSequence spritetorreN{ "imagenes/torre_negro.png", 1 };
public:
	Torre(Vector p, color_p c) { pos = p; tipo = TORRE; color = c; }
	friend class Tablero;
	void draw();
	bool mover(Vector pos1, Vector pos2, int color, int color2);
};
#endif