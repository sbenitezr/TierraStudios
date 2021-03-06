#ifndef __TORRE_H__
#define __TORRE_H__
#include "TableroGL.h"
#include "Pieza.h"

class Torre :public Pieza {

protected:
	//Definicion de Sprite
	SpriteSequence spritetorreB{ "imagenes/torreBlanca.png", 1 };
	SpriteSequence spritetorreN{ "imagenes/torreNegra.png", 1 };

	//Definicion de Sprite
	SpriteSequence spritetorreBU{ "imagenes/torreBlancoETSIDI.png", 1 };
	SpriteSequence spritetorreNU{ "imagenes/torreNegraETSIDI.png", 1 };
public:
	Torre(Vector p, color_p c) { pos = p; tipo = TORRE; color = c; }

	void draw(int x);
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	friend class Tablero;
	virtual void coutPieza(int x, int y, color_p color, tipo_t tipo = TORRE) {
		if (color == 0) cout << "(" << x << "," << y << ")" << "Torre Blanca" << endl;
		if (color == 1) cout << "(" << x << "," << y << ")" << "Torre Negra" << endl;
	}
};
#endif