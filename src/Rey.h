#ifndef __REY_H__
#define __REY_H__
#include "TableroGL.h"
#include "Pieza.h"

class Rey :public Pieza {
protected:
	//Definicion de Sprite
	SpriteSequence spritereyN{ "imagenes/rey_negro.png", 1 };
	SpriteSequence spritereyB{ "imagenes/rey_blanco.png", 1 };

	//Definicion de Sprite Rey Universidad
	SpriteSequence spritereyNU{ "imagenes/reyNegroETSIDI.png", 1 };
	SpriteSequence spritereyBU{ "imagenes/reyBlancoETSIDI.png", 1 };
public:
	Rey(Vector p, color_p c) { pos = p; tipo = REY; color = c; }

	void draw(int x);
    virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	virtual void coutPieza(int x, int y, color_p color, tipo_t tipo = REY) {
		if (color == 0) cout << "(" << x << "," << y << ")" << "Rey Blanco" << endl;
		if (color == 1) cout << "(" << x << "," << y << ")" << "Rey Negro" << endl;
	}
};

#endif 