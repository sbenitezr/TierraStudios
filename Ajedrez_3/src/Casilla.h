#ifndef __CASILLA_H__
#define __CASILLA_H__

#include "Vector2D.h"
#include "TableroGL.h"
#include "Pieza.h"

class Casilla {
public:
	//Hay que mirar como pasar el ancho que está puesto en TableroGL porque no he sabido pasarlo :(
	float ancho = 1.0;
	Vector posicion;
	
	//Mirar como relacionar las Piezas para poder establecer un setPieza con todas, ya que si no tenemos distintas clases no podemos establecer un setPieza
	//Lo he intentado con la clase objeto y creo que está bastante bien 

	Objeto* objeto;

	Casilla();
	virtual ~Casilla() {};
	void dibuja();
	void setPos(Vector pos){ this->posicion = pos; }
	Vector getPos() { return posicion; }

	//Relacion con la clase Pieza en el caso de que tengamos distintas piezas
	Objeto* getPieza() { return objeto; }
	void setPieza(Objeto* pieza) { this->objeto = pieza; }
};

#endif // !__CASILLA_H__
