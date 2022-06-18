#ifndef __REINA_H__
#define __REINA_H__
#include "TableroGL.h"
#include "Pieza.h"

class Reina :public Pieza {

protected:
	//Definicion de Sprite
	SpriteSequence spritereinaN{ "imagenes/reina_negro.png", 1 };
	SpriteSequence spritereinaB{ "imagenes/reina_blanco.png", 1 };

	/*
	//MODELO NUEVO
	SpriteSequence spritereinaN{ "imagenes/reinaNegro.png", 1 };
	SpriteSequence spritereinaB{ "imagenes/reinaBlanco.png", 1 };

	//MODELO ETSIDI
	SpriteSequence spritereinaN{ "imagenes/reinaNegroETSIDI.png", 1 };
	SpriteSequence spritereinaB{ "imagenes/reinaBlancoETSIDI.png", 1 };
	*/

public:
	Reina(Vector p, color_p c) { pos = p; tipo = REINA; color = c; }
	void draw();
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	friend class Torre;
	friend class Alfil;
};

#endif 