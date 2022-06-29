#ifndef __CABALLO_H__
#define __CABALLO_H__
#include "TableroGL.h"
#include "Pieza.h"

class Caballo :public Pieza {
protected:
	//Definicion de Sprite
	SpriteSequence spritecaballoB{ "imagenes/caballo_blanco.png", 1 };
	SpriteSequence spritecaballoN{ "imagenes/caballo_negro.png", 1 };
public:
	Caballo(Vector p, color_p c) { pos = p; tipo = CABALLO; color = c; }

	void draw();
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	virtual void coutPieza(int x, int y, color_p color, tipo_t tipo = CABALLO) {
		if (color == 0) cout << "(" << x << "," << y << ")" << "Caballo Blanco" << endl;
		if (color == 1) cout << "(" << x << "," << y << ")" << "Caballo Negro" << endl;
	}
};
#endif