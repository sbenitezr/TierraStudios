#include "Reina.h"

void Reina::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		//spritereinaB.setCenter(pos.x, pos.y);
		//spritereinaB.setSize(1, 1);
		//spritereinaB.draw();
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		//spritereinaN.setCenter(pos.x,pos.y);
		//spritereinaN.setSize(1, 1);
		//spritereinaN.draw();
		glEnable(GL_LIGHTING);
	}
}