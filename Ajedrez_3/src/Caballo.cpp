#include "Caballo.h"

void Caballo::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		//spritecaballoB.setCenter(pos.x, pos.y);
		//spritecaballoB.setSize(1, 1);
		//spritecaballoB.draw();
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		//spritecaballoN.setCenter(pos.x, pos.y);
		//spritecaballoN.setSize(1, 1);
		//spritecaballoN.draw();
		glEnable(GL_LIGHTING);
	}
}