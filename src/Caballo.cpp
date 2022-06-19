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
		glTranslatef(pos.y+1, -pos.x, 0);
		spritecaballoN.setCenter(0, 0);
		spritecaballoN.setSize(1, 1);
		spritecaballoN.flip(true, true);
		spritecaballoN.draw();
		glTranslatef(-pos.y-1, pos.x, 0);
		glEnable(GL_LIGHTING);
	}
}

bool Caballo::mover(Vector pos1, Vector pos2, int color, int color2) {
	int dif = abs(pos2.x - pos1.x);
	if ((dif > 2) || (dif < 1))
		return FALSE;
	else if ((dif == 1) && (abs(pos2.y - pos1.y) != 2) || (dif == 2) && (abs(pos2.y - pos1.y) != 1))
		return FALSE;
	else { return TRUE; }
}