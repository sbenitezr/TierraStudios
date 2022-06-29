#ifndef __PEON_H__
#define __PEON_H__
#include "TableroGL.h"
#include "Pieza.h"

class Peon :public Pieza {
protected:
	//Definicion de Sprite para mostrar la imagen de peon
	SpriteSequence spritepeonN{ "imagenes/peon_negro.png", 1 };
	SpriteSequence spritepeonB{ "imagenes/peon_blanco.png", 1 };
public:
	Peon(Vector p, color_p c) { pos = p; tipo = PEON; color = c; }
	Peon(Vector p) { pos = p; }
	void draw();
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	virtual void coutPieza(int x, int y, color_p color, tipo_t tipo = PEON) {
		if (color == 0) cout << "(" << x << "," << y << ")" << "Peon Blanco" << endl;
		if (color == 1) cout << "(" << x << "," << y << ")" << "Peon Negro" << endl;
	}
};
#endif