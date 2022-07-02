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
void Casilla::creaPieza(int x, int y, int type, Pieza::color_p color) {
	if (type == -1) { setPieza(new NoPieza(Vector(x, y))); }
	if (type == 0) { setPieza(new Peon(Vector(x, y), color)); }
	if (type == 1) { setPieza(new Caballo(Vector(x, y), color)); }
	if (type == 2) { setPieza(new Torre(Vector(x, y), color)); }
	if (type == 3) { setPieza(new Alfil(Vector(x, y), color)); }
	if (type == 4) { setPieza(new Reina(Vector(x, y), color)); }
	if (type == 5) { setPieza(new Rey(Vector(x, y), color)); }
}