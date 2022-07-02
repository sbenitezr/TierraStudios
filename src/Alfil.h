#ifndef __ALFIL_H__
#define __ALFIL_H__
#include "TableroGL.h"
#include "Pieza.h"

class Alfil :public Pieza {
protected:
	//Definicion de Sprite
	SpriteSequence spritealfilB{ "imagenes/alfil_blanco.png", 1 };
	SpriteSequence spritealfilN{ "imagenes/alfil_negro.png", 1 };

	//Definicion de Sprite Alfil Universidad
	SpriteSequence spritealfilBU{ "imagenes/alfilBlancoETSIDI.png", 1 };
	SpriteSequence spritealfilNU{ "imagenes/alfilNegroETSIDI.png", 1 };
public:
	Alfil(Vector p, color_p c) { pos = p; tipo = ALFIL; color = c; }

	void draw(int x);
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	friend class TableroGL;

	virtual void coutPieza(int x, int y, color_p color, tipo_t tipo = ALFIL) {
		if (color == 0) cout << "(" << x << "," << y << ")" << "Alfil Blanco" << endl;
		if (color == 1) cout << "(" << x << "," << y << ")" << "Alfil Negro" << endl;
	}
};
#endif 