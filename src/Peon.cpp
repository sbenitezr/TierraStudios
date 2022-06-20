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
		glTranslatef(pos.y+1, -pos.x, 0);
		spritepeonN.setCenter(0, 0);
		spritepeonN.setSize(1, 1);
		spritepeonN.flip(true, true);
		spritepeonN.draw();
		glTranslatef(-pos.y-1, pos.x, 0);
		glEnable(GL_LIGHTING);
	}
}