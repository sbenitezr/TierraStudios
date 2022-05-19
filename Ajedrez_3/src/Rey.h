#ifndef __REY_H__
#define __REY_H__

#include "Objeto.h"
#include "TableroGL.h"

class Rey :public Objeto {

public:
	Rey(color_p _color, int _x, int _y);
	Rey() {};
	~Rey() {};

	void Dibuja();
	void Color();
	//bool movValido(int destX, int destY, ColorPieza c);
	//Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);


	//Definicion de Sprite
	SpriteSequence spritereyN{ "imagenes/rey_negro.png", 1 };
	SpriteSequence spritereyB{ "imagenes/rey_blanco.png", 1 };

};

#endif 