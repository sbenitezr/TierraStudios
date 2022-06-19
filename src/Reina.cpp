#include "Reina.h"

void Reina::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y, -pos.x - 8, 0);
		spritereinaB.setCenter(0, 0);
		spritereinaB.setSize(1, 1);
		spritereinaB.draw();
		glTranslatef(-pos.y, pos.x + 8, 0);
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y+1, -pos.x, 0);
		spritereinaN.setCenter(0, 0);
		spritereinaN.setSize(1, 1);
		spritereinaN.flip(true, true);
		spritereinaN.draw();
		glTranslatef(-pos.y-1, pos.x, 0);
		glEnable(GL_LIGHTING);
	}
}
bool Reina::mover(Vector pos1, Vector pos2, int color, int color2) 
{
	if (movt(pos1,pos2,color,color2) == TRUE || mova(pos1,pos2, color,color2) == TRUE)
	{
		return TRUE;
	}
	else
		return FALSE;
}
bool Reina::movt(Vector pos1, Vector pos2, int color, int color2) {
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
bool Reina::mova(Vector pos1, Vector pos2, int color, int color2) {
	int dif = abs(pos2.x - pos1.x);
	if (abs(pos2.y - pos1.y) != dif) { return FALSE; }
	else {
		if (pos2.y > pos1.y) {
			if (pos2.x > pos1.x) {
				int acum = 0;
				int counter = 0;
				int i = (pos1.x + 1);
				int j = (pos1.y + 1);
				if (dif > 1) {
					do {
						int col = TableroGL::m_tablero->getCas()[i][j].getPieza()->getTipo();
						i++;
						j++;
						counter++;
						if (col != -1)
							acum++;
					} while (counter != (dif - 1));
					if (acum != 0) { return FALSE; }
					else { return TRUE; }
				}
				else { return TRUE; }
			}
			else if (pos2.x < pos1.x) {
				int acum = 0;
				int counter = 0;
				int i = (pos1.x - 1);
				int j = (pos1.y + 1);
				if (dif > 1) {
					do {
						int col = TableroGL::m_tablero->getCas()[i][j].getPieza()->getTipo();
						i--;
						j++;
						counter++;
						if (col != -1)
							acum++;
					} while (counter != (dif - 1));
					if (acum != 0) { return FALSE; }
					else { return TRUE; }
				}
				else { return TRUE; }
			}
		}
		else if (pos2.y < pos1.y) {

			if (pos2.x > pos1.x) {
				int acum = 0;
				int counter = 0;
				int i = (pos1.x + 1);
				int j = (pos1.y - 1);
				if (dif > 1) {
					do {
						int col = TableroGL::m_tablero->getCas()[i][j].getPieza()->getTipo();
						i++;
						j--;
						counter++;
						if (col != -1)
							acum++;
					} while (counter != (dif - 1));
					if (acum != 0) { return FALSE; }
					else { return TRUE; }
				}
				else { return TRUE; }
			}
			else if (pos2.x < pos1.x) {
				int acum = 0;
				int counter = 0;
				int i = (pos1.x - 1);
				int j = (pos1.y - 1);
				if (dif > 1) {
					do {
						int col = TableroGL::m_tablero->getCas()[i][j].getPieza()->getTipo();
						i--;
						j--;
						counter++;
						if (col != -1)
							acum++;
					} while (counter != (dif - 1));
					if (acum != 0) { return FALSE; }
					else { return TRUE; }
				}
				else { return TRUE; }
			}
			else { return FALSE; }
		}
	}
}