#include "Peon.h"

void Peon::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y, -pos.x - 6, 0);
		spritepeonB.setCenter(0, 0);
		spritepeonB.setSize(1, 1);
		spritepeonB.draw();
		glTranslatef(-pos.y, pos.x + 6, 0);
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y + 1, pos.x - 2, 0);
		spritepeonN.setCenter(0, 0);
		spritepeonN.setSize(1, 1);
		spritepeonN.flip(true, true);
		spritepeonN.draw();
		glTranslatef(-pos.y - 1, -pos.x + 2, 0);
		glEnable(GL_LIGHTING);
	}
}

bool Peon::mover(Vector pos1, Vector pos2, int color, int color2) {
	if ((pos1.x == 1) || (pos1.x == 6)) {
		if (color == Pieza::BLANCO) {
			if ((color2 == Pieza::NO_COLOR) && ((pos2.y - pos1.y) == 0) && (((pos2.x - pos1.x) == -2) || (pos2.x - pos1.x) == -1))
				return TRUE;
			else if ((color2 == Pieza::NEGRO) && ((pos2.x - pos1.x) == -1) && (abs(pos2.y - pos1.y) == 1))
				return TRUE;
			else
				return FALSE;
		}
		else if (color == Pieza::NEGRO) {
			if ((color2 == Pieza::NO_COLOR) && ((pos2.y - pos1.y) == 0) && (((pos2.x - pos1.x) == 2) || (pos2.x - pos1.x) == 1)) { return TRUE; }
			else if ((color2 == Pieza::BLANCO) && ((pos2.x - pos1.x) == 1) && (abs(pos2.y - pos1.y) == 1)) { return TRUE; }
			else { return FALSE; }
		}
		else { return FALSE; }
	}
	else {
		if (color == Pieza::BLANCO) {
			if ((color2 == Pieza::NO_COLOR) && ((pos2.y - pos1.y) == 0) && ((pos2.x - pos1.x) == -1)) { return TRUE; }
			else if ((color2 == Pieza::NEGRO) && ((pos2.x - pos1.x) == -1) && (abs(pos2.y - pos1.y) == 1)) { return TRUE; }
			else { return FALSE; }
		}
		else if (color == Pieza::NEGRO) {
			if ((color2 == Pieza::NO_COLOR) && ((pos2.y - pos1.y) == 0) && ((pos2.x - pos1.x) == 1)) { return TRUE; }
			else if ((color2 == Pieza::BLANCO) && ((pos2.x - pos1.x) == 1) && (abs(pos2.y - pos1.y) == 1)) { return TRUE; }
			else { return FALSE; }
		}
	}
}