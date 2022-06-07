#include "Reina.h"

void Reina::draw()
{
	if (color == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y, -pos.x - 8, 0);
		spritereinaB.setCenter(0, 0);
		spritereinaB.setSize(1, 1);
		spritereinaB.draw();
		glTranslatef(-pos.y, pos.x + 8, 0);
		glEnable(GL_LIGHTING);
	}

	if (color == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(pos.y + 1, -pos.x, 0);
		spritereinaN.setCenter(0, 0);
		spritereinaN.setSize(1, 1);
		spritereinaN.flip(true, true);
		spritereinaN.draw();
		glTranslatef(-pos.y - 1, pos.x, 0);
		glEnable(GL_LIGHTING);
	}
}
bool Reina::mover(Vector pos1, Vector pos2, int color, int color2) {

}