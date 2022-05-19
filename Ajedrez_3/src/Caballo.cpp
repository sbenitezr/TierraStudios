#include "Caballo.h"

void Caballo::Dibuja()
{
	if (colorPieza == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritecaballoB.setCenter(ancho / 2, ancho / 2);
		spritecaballoB.setSize(1, 1);
		spritecaballoB.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

	if (colorPieza == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritecaballoN.setCenter(ancho / 2, ancho / 2);
		spritecaballoN.setSize(1, 1);
		spritecaballoN.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

}


//Queda definir como obtener el color
void Caballo::Color()
{
}