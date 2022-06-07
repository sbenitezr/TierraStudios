#include "Torre.h"

void Torre::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y, -pos.x - 8, 0);
		spritetorreB.setCenter(0, 0);
		spritetorreB.setSize(1, 1);
		spritetorreB.draw();
		glTranslatef(-pos.y, pos.x + 8, 0);
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y + 1, -pos.x, 0);
		spritetorreN.setCenter(0, 0);
		spritetorreN.setSize(1, 1);
		spritetorreN.flip(true, true);
		spritetorreN.draw();
		glTranslatef(-pos.y - 1, pos.x, 0);
		glEnable(GL_LIGHTING);
	}
}
bool Torre::mover(Vector pos1, Vector pos2, int color, int color2) {
	if ((abs(pos2.x - pos1.x) != 0) && abs(pos2.y - pos1.y) != 0)
		return FALSE;
	else {
		if (pos1.y == pos2.y) {
			if (pos2.x > pos1.x) {
				int acum = 0;
				for (int i = (pos1.x + 1); i < pos2.x; i++) {
					int col = getCas()[i][y1].getPieza()->getTipo();
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
			else if (pos2.x < pos1.x) {
				int acum = 0;
				for (int i = (pos1.x - 1); i > pos2.x; i--) {
					int col = getCas()[i][y1].getPieza()->getTipo();
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
		}
		else if (pos1.x == pos2.x) {
			int acum = 0;
			if (pos2.y > pos1.y) {
				for (int i = (pos1.y + 1); i < pos2.y; i++) {
					int col = getCas()[pos1.x][i].getPieza()->getTipo();
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
			else if (pos2.y < pos1.y) {
				for (int i = (pos1.y - 1); i > pos2.y; i--) {
					int col = getCas()[pos1.x][i].getPieza()->getTipo();
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
			else { return FALSE; }
		}
		else { return FALSE; }
	}
}