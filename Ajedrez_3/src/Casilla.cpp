#include "Casilla.h"
#include "ETSIDI.h"

Casilla::Casilla() {
	posicion.x = 0;
	posicion.y = 0;
}

void Casilla::dibuja() {
	glDisable(GL_LIGHTING);

	//El color hay que establecerlo bien
	glColor3ub(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(posicion.x + ancho, posicion.y + ancho);
	glVertex2f(posicion.x + ancho, posicion.y - ancho);
	glVertex2f(posicion.x - ancho, posicion.y - ancho);
	glVertex2f(posicion.x - ancho, posicion.y + ancho);
	glEnd();
	glEnable(GL_LIGHTING);
}

