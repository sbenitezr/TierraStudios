#include "Peon.h"

void Peon::draw()
{
	if (color == BLANCO) {
		glDisable(GL_LIGHTING);
		//spritepeonB.setCenter(pos.x, pos.y);
		//spritepeonB.setSize(1, 1);
		//spritepeonB.draw();
		glEnable(GL_LIGHTING);
	}

	if (color == NEGRO) {
		glDisable(GL_LIGHTING);
		//spritepeonN.setCenter(pos.x, pos.y);
		//spritepeonN.setSize(1, 1);
		//spritepeonN.draw();
		glEnable(GL_LIGHTING);
	}
}
