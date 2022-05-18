#include "Alfil.h"

void Alfil::Dibuja()
{
	if (colorPieza == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritealfilB.setCenter(ancho / 2, ancho / 2);
		spritealfilB.setSize(1, 1);
		spritealfilB.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

	if (colorPieza == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritealfilN.setCenter(ancho / 2, ancho / 2);
		spritealfilN.setSize(1, 1);
		spritealfilN.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

}


//Queda definir como obtener el color
void Alfil::Color()
{
}