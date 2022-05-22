#include "Caballo.h"

void Caballo::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y, -pos.x - 8, 0);
		spritecaballoB.setCenter(0, 0);
		spritecaballoB.setSize(1, 1);
		spritecaballoB.draw();
		glTranslatef(-pos.y, pos.x + 8, 0);
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y, -pos.x - 1, 0);
		spritecaballoN.setCenter(0, 0);
		spritecaballoN.setSize(1, 1);
		spritecaballoN.draw();
		glTranslatef(-pos.y, pos.x + 1, 0);
		glEnable(GL_LIGHTING);
	}
}