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
		glTranslatef(pos.y, -pos.x - 1, 0);
		spritetorreN.setCenter(0, 0);
		spritetorreN.setSize(1, 1);
		spritetorreN.draw();
		glTranslatef(-pos.y, pos.x + 1, 0);
		glEnable(GL_LIGHTING);
	}

}