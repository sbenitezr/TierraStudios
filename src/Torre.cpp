#include "Torre.h"

void Torre::draw(int x)
{
	if (x == 1) {
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
			glTranslatef(pos.y + 1, pos.x, 0);
			spritetorreN.setCenter(0, 0);
			spritetorreN.setSize(1, 1);
			spritetorreN.flip(true, true);
			spritetorreN.draw();
			glTranslatef(-pos.y - 1, -pos.x, 0);
			glEnable(GL_LIGHTING);
		}
	}
	if (x == 2) {
		if (color == color_p::BLANCO) {
			glDisable(GL_LIGHTING);
			glTranslatef(pos.y, -pos.x - 8, 0);
			spritetorreBU.setCenter(0, 0);
			spritetorreBU.setSize(1, 1);
			spritetorreBU.draw();
			glTranslatef(-pos.y, pos.x + 8, 0);
			glEnable(GL_LIGHTING);
		}

		if (color == color_p::NEGRO) {
			glDisable(GL_LIGHTING);
			glTranslatef(pos.y + 1, pos.x, 0);
			spritetorreNU.setCenter(0, 0);
			spritetorreNU.setSize(1, 1);
			spritetorreNU.flip(true, true);
			spritetorreNU.draw();
			glTranslatef(-pos.y - 1, -pos.x, 0);
			glEnable(GL_LIGHTING);
		}
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
					int col = TableroGL::m_tablero->getCas()[i][pos1.y].getPieza()->getTipo();
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
			else if (pos2.x < pos1.x) {
				int acum = 0;
				for (int i = (pos1.x - 1); i > pos2.x; i--) {
					int col = TableroGL::m_tablero->getCas()[i][pos1.y].getPieza()->getTipo();
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
					int col = TableroGL::m_tablero->getCas()[pos1.x][i].getPieza()->getTipo();
					if (col != -1)
						acum++;
				}
				if (acum != 0) { return FALSE; }
				else { return TRUE; }
			}
			else if (pos2.y < pos1.y) {
				for (int i = (pos1.y - 1); i > pos2.y; i--) {
					int col = TableroGL::m_tablero->getCas()[pos1.x][i].getPieza()->getTipo();
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