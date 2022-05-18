#include "Peon.h"

void Peon::Dibuja()
{
	if (colorPieza == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritepeonB.setCenter(ancho / 2, ancho / 2);
		spritepeonB.setSize(1, 1);
		spritepeonB.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

	if (colorPieza == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritepeonN.setCenter(ancho / 2, ancho / 2);
		spritepeonN.setSize(1, 1);
		spritepeonN.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

}


//Queda definir como obtener el color
void Peon::Color()
{
}
