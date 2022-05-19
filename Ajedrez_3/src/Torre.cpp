#include "Torre.h"

void Torre::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		//spritetorreB.setCenter(pos.x, pos.y);
		//spritetorreB.setSize(1, 1);
		//spritetorreB.draw();
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		//spritetorreN.setCenter(pos.x, pos.y);
		//spritetorreN.setSize(1, 1);
		//spritetorreN.draw();
		glEnable(GL_LIGHTING);
	}

}