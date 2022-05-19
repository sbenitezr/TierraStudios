#include "Casilla.h"
#include "ETSIDI.h"

void Casilla::drawN() {
	glDisable(GL_LIGHTING);
	glColor3ub(1,1,1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex2f(ancho, -ancho);
	glTexCoord2d(1, 1); glVertex2f(ancho, 0);
	glTexCoord2d(1, 0); glVertex2f(0, 0);
	glTexCoord2d(0, 0); glVertex2f(0, -ancho);
	glEnd();
	glEnable(GL_LIGHTING);
}
void Casilla::drawB() {
	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex2f(ancho, -ancho);
	glTexCoord2d(1, 1); glVertex2f(ancho, 0);
	glTexCoord2d(1, 0); glVertex2f(0, 0);
	glTexCoord2d(0, 0); glVertex2f(0, -ancho);
	glEnd();
	glEnable(GL_LIGHTING);
}