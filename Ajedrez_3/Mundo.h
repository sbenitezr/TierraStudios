#pragma once
#include "Tablero.h"
#include "TableroGL.h"

class Mundo {
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;

public:
	Mundo();
	~Mundo();
	TableroGL tablero;
	void dibuja();
	void tecla(unsigned char key);
};