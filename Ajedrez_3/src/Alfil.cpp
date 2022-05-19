#include "Alfil.h"

void Alfil::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		//spritealfilB.setCenter(pos.x, pos.y);
		//spritealfilB.setSize(1, 1);
		//spritealfilB.draw();
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		//spritealfilN.setCenter(pos.x, pos.y);
		//spritealfilN.setSize(1, 1);
		//spritealfilN.draw();
		glEnable(GL_LIGHTING);
	}

}