#ifndef __COORDINADOR_AJ_H__
#define __COORDINADOR_AJ_H__
#pragma once
#include"TableroGL.h"


class CoordinadorAj
{
	friend TableroGL;
public:
	CoordinadorAj();
	virtual ~CoordinadorAj();

	void draw();
	void teclaEspecial(int x, int y, int button, bool down, bool sKey, bool ctrlKey);
	void Tecla(unsigned char key);
	void mueve();
	

protected:
	TableroGL tablerogl;
	enum Estado { INICIO, JUEGO, VICTORIA, DERROTA, TABLAS, PAUSA };
	Estado modo;

};

#endif