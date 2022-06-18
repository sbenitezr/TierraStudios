#include "Rey.h"

void Rey::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y, -pos.x - 8, 0);
		spritereyB.setCenter(0, 0);
		spritereyB.setSize(1, 1);
		spritereyB.draw();
		glTranslatef(-pos.y, pos.x + 8, 0);
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y+1, -pos.x, 0);
		spritereyN.setCenter(0, 0);
		spritereyN.setSize(1, 1);
		spritereyN.flip(true, true);
		spritereyN.draw();
		glTranslatef(-pos.y-1, pos.x, 0);
		glEnable(GL_LIGHTING);
	}
}

bool Rey::mover(Vector pos1, Vector pos2, int color, int color2) {
	if (abs(pos2.x - pos1.x) > 1 || abs(pos2.y - pos1.y) > 1)
		return FALSE;
	else { return TRUE; }
}