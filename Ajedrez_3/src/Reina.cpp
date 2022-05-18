#include "Reina.h"

void Reina::Dibuja()
{
	if (colorPieza == color_p::BLANCO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritereinaB.setCenter(ancho / 2, ancho / 2);
		spritereinaB.setSize(1, 1);
		spritereinaB.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

	if (colorPieza == color_p::NEGRO) {
		glDisable(GL_LIGHTING);
		glTranslatef(glx, -gly - ancho, 0);
		spritereinaN.setCenter(ancho / 2, ancho / 2);
		spritereinaN.setSize(1, 1);
		spritereinaN.draw();
		glTranslatef(-glx, gly + ancho, 0);
		glEnable(GL_LIGHTING);
	}

}


//Queda definir como obtener el color
void Reina::Color()
{
}