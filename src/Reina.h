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
	virtual bool mover(Vector pos1, Vector pos2, int color, int color2);
	bool movt(Vector pos1, Vector pos2, int color, int color2);
	bool mova(Vector pos1, Vector pos2, int color, int color2);
	friend class Torre;
	friend class Alfil;
	virtual void coutPieza(int x, int y, color_p color, tipo_t tipo = REINA) {
		//INCLUIR SONIDO DE REINA: ETSIDI::play("sonidos/la reina.wav");
		if (color == 0) cout << "(" << x << "," << y << ")" << "Reina Blanca" << endl;
		if (color == 1) cout << "(" << x << "," << y << ")" << "Reina Negra" << endl;
	}
};

#endif 