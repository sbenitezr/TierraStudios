#include "Casilla.h"
#include "ETSIDI.h"
#include "ColorCasilla.h"

void Casilla::draw() {
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex2f(ancho, -ancho);
	glTexCoord2d(1, 1); glVertex2f(ancho, 0);
	glTexCoord2d(1, 0); glVertex2f(0, 0);
	glTexCoord2d(0, 0); glVertex2f(0, -ancho);
	glEnd();
	glEnable(GL_LIGHTING);
}