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
		glTranslatef(pos.y, -pos.x - 1, 0);
		spritealfilN.setCenter(0, 0);
		spritealfilN.setSize(1, 1);
		spritealfilN.draw();
		glTranslatef(-pos.y, pos.x + 1, 0);
		glEnable(GL_LIGHTING);
	}

}