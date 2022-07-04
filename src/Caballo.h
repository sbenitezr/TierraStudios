#ifndef __CABALLO_H__
#define __CABALLO_H__
#include "TableroGL.h"
#include "Pieza.h"

class Caballo :public Pieza {
protected:
	//Definicion de Sprite
	SpriteSequence spritecaballoB{ "imagenes/caballoBlanco.png", 1 };
	SpriteSequence spritecaballoN{ "imagenes/caballoNegro.png", 1 };

	//Definicion de Sprite
	SpriteSequence spritecaballoBU{ "imagenes/caballoBlancoETSIDI.png", 1 };
	SpriteSequence spritecaballoNU{ "imagenes/caballoNegroETSIDI.png", 1 };
public:
	Caballo(Vector p, color_p c) { pos = p; tipo = CABALLO; color = c; }

	void draw(int x);
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	virtual void coutPieza(int x, int y, color_p color, tipo_t tipo = CABALLO) {
		if (color == 0) cout << "(" << x << "," << y << ")" << "Caballo Blanco" << endl;
		if (color == 1) cout << "(" << x << "," << y << ")" << "Caballo Negro" << endl;
	}
};
#endif