#include "Alfil.h"

void Alfil::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y, -pos.x - 8, 0);
		spritealfilB.setCenter(0, 0);
		spritealfilB.setSize(1, 1);
		spritealfilB.draw();
		glTranslatef(-pos.y, pos.x + 8, 0);
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y + 1, -pos.x, 0);
		spritealfilN.setCenter(0, 0);
		spritealfilN.setSize(1, 1);
		spritealfilN.flip(true, true);
		spritealfilN.draw();
		glTranslatef(-pos.y - 1, pos.x, 0);
		glEnable(GL_LIGHTING);
	}

}

bool Alfil::mover(Vector pos1, Vector pos2, int color, int color2) {
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
						int col = getCas()[i][j].getPieza()->getTipo();
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
						int col = getCas()[i][j].getPieza()->getTipo();
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
						int col = getCas()[i][j].getPieza()->getTipo();
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
						int col = getCas()[i][j].getPieza()->getTipo();
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