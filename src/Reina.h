#ifndef __REINA_H__
#define __REINA_H__
#include "TableroGL.h"
#include "Pieza.h"

class Reina :public Pieza {

protected:
	//Definicion de Sprite
	SpriteSequence spritereinaN{ "imagenes/reina_negro.png", 1 };
	SpriteSequence spritereinaB{ "imagenes/reina_blanco.png", 1 };
public:
	Reina(Vector p, color_p c) { pos = p; tipo = REINA; color = c; }

	void draw();
};

#endif 