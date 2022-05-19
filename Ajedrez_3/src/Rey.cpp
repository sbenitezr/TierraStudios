#include "Rey.h"

void Rey::Dibuja()
{
	if (colorPieza == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritereyB.setCenter(ancho / 2, ancho / 2);
		spritereyB.setSize(1, 1);
		spritereyB.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

	if (colorPieza == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritereyN.setCenter(ancho / 2, ancho / 2);
		spritereyN.setSize(1, 1);
		spritereyN.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

}


//Queda definir como obtener el color
void Rey::Color()
{
}