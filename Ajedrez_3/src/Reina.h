#ifndef __REINA_H__
#define __REINA_H__

#include "Objeto.h"
#include "TableroGL.h"

class Reina :public Objeto {

public:
	Reina(color_p _color, int _x, int _y);
	Reina() {};
	~Reina() {};

	void Dibuja();
	void Color();
	//bool movValido(int destX, int destY, ColorPieza c);
	//Vector2D* getTrayectoria(Vector2D origen, Vector2D destino);


	//Definicion de Sprite
	SpriteSequence spritereinaN{ "imagenes/reina_negro.png", 1 };
	SpriteSequence spritereinaB{ "imagenes/reina_blanco.png", 1 };

};

#endif 