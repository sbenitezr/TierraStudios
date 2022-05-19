#include "Rey.h"

void Rey::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		//spritereyB.setCenter(pos.x, pos.y);
		//spritereyB.setSize(1, 1);
		//spritereyB.draw();
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		//spritereyN.setCenter(pos.x, pos.y);
		//spritereyN.setSize(1, 1);
		//spritereyN.draw();
		glEnable(GL_LIGHTING);
	}
}