#include "Torre.h"

void Torre::Dibuja()
{
	if (colorPieza == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritetorreB.setCenter(ancho / 2, ancho / 2);
		spritetorreB.setSize(1, 1);
		spritetorreB.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

	if (colorPieza == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritetorreN.setCenter(ancho / 2, ancho / 2);
		spritetorreN.setSize(1, 1);
		spritetorreN.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

}


//Queda definir como obtener el color
void Torre::Color()
{
}