#include "TableroGL.h"
#include "herramientasgl.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "freeglut.h"
#include "ETSIDI.h"
#include "Peon.h"

void TableroGL::init() {
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	spritepeonN.setCenter(ancho/2, ancho/2);
	spritepeonN.setSize(1, 1);
	spritetorreN.setCenter(ancho / 2, ancho / 2);
	spritetorreN.setSize(1, 1);
	spritereinaN.setCenter(ancho / 2, ancho / 2);
	spritereinaN.setSize(1, 1);
	spritealfilN.setCenter(ancho / 2, ancho / 2);
	spritealfilN.setSize(1, 1);
	spritereyN.setCenter(ancho / 2, ancho / 2);
	spritereyN.setSize(1, 1);
	spritecaballoN.setCenter(ancho / 2, ancho / 2);
	spritecaballoN.setSize(1, 1);

	spritepeonB.setCenter(ancho / 2, ancho / 2);
	spritepeonB.setSize(1, 1);
	spritetorreB.setCenter(ancho / 2, ancho / 2);
	spritetorreB.setSize(1, 1);
	spritereinaB.setCenter(ancho / 2, ancho / 2);
	spritereinaB.setSize(1, 1);
	spritealfilB.setCenter(ancho / 2, ancho / 2);
	spritealfilB.setSize(1, 1);
	spritereyB.setCenter(ancho / 2, ancho / 2);
	spritereyB.setSize(1, 1);
	spritecaballoB.setCenter(ancho / 2, ancho / 2);
	spritecaballoB.setSize(1, 1);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
}
void TableroGL::drawMatriz() {
	GLTools::Color(gltools::BLACK);
	float dist = N * ancho;
	for (int i = 0; i <= N; i++) {
		if (i % N == 0) glLineWidth(4);
		else glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(i * ancho, 0, 0);
		glVertex3f(i * ancho, -dist, 0);
		glVertex3f(0, -i * ancho, 0);
		glVertex3f(dist, -i * ancho, 0);
		glEnd();
	}
}
void TableroGL::drawCasilla(int i, int j) {
	//Dibuja el contenido de las celdas
	//Empieza a contar por la esquina superior izquierda del tablero
	//(i, j) son coordenadas, (0, 0) es la esquina superior izquierda
	float glx, gly;
	switch (m_tablero->getTab()[i][j].getColor()) {
		case Objeto::NEGRO:
			switch (m_tablero->getTab()[i][j].getTipo())
			{
			case Objeto::PEON:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				glTranslatef(glx, -gly - ancho, 0);
				spritepeonN.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::REINA:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				glTranslatef(glx, -gly - ancho, 0);
				spritereinaN.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::TORRE:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				glTranslatef(glx, -gly - ancho, 0);
				spritetorreN.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::ALFIL:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				glTranslatef(glx, -gly - ancho, 0);
				spritealfilN.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::REY:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				glTranslatef(glx, -gly - ancho, 0);
				spritereyN.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::CABALLO:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				glTranslatef(glx, -gly - ancho, 0);
				spritecaballoN.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			default:
				;
			}
			break;
		case Objeto::BLANCO:
			switch (m_tablero->getTab()[i][j].getTipo())
			{
			case Objeto::PEON:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				glTranslatef(glx, -gly - ancho, 0);
				spritepeonB.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::REINA:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				//GLTools::Color(gltools::BLACK);
				glTranslatef(glx, -gly - ancho, 0);
				spritereinaB.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::TORRE:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				//GLTools::Color(gltools::YELLOW);
				glTranslatef(glx, -gly - ancho, 0);
				spritetorreB.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::ALFIL:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				//GLTools::Color(gltools::RED);
				glTranslatef(glx, -gly - ancho, 0);
				spritealfilB.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::REY:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				//GLTools::Color(gltools::RED);
				glTranslatef(glx, -gly - ancho, 0);
				spritereyB.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			case Objeto::CABALLO:
				casillaCentral(i, j, glx, gly);
				glDisable(GL_LIGHTING);
				//GLTools::Color(gltools::RED);
				glTranslatef(glx, -gly - ancho, 0);
				spritecaballoB.draw();
				glTranslatef(-glx, gly + ancho, 0);
				glEnable(GL_LIGHTING);
				break;
			default:
				;
			}
			break;
		case Objeto::CASILLA_VACIA:
			
		default:
			;
	}
}
void TableroGL::draw() {
	centro_x = N * ancho / 2;
	centro_y = -N * ancho / 2;
	centro_z = 0;

	//Borrado de la pantalla	
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(centro_x, centro_y, -15, centro_x, centro_y, centro_z, 0, 1, 0);
	glEnable(GL_LIGHTING);

	//Pinta las celdas y el tablero
	drawMatriz();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			drawCasilla(i, j);
		}
	}

	//Dibuja un rectangulo transparente sobre el tablero para capturar el raton
	//con gluUnProject
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.png").id);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GLTools::Color(gltools::WHITE, 1.0f);
	glTranslatef(centro_x, centro_y, centro_z);
	glRectf(N * ancho / 2.0f, N * ancho / 2.0f, -N * ancho / 2.0f, -N * ancho / 2.0f);
	glTranslatef(-centro_x, -centro_y, -centro_z);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void TableroGL::MouseButton(int x, int y, int button, bool down, bool sKey, bool ctrlKey) {
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//finally cell coordinates
	casillaMundo(posX, posY, xcas_sel, ycas_sel);

	///////////////////////////	
	//capture other mouse events

	if (down) {
		controlKey = ctrlKey;
		shiftKey = sKey;
	}
	else {
		controlKey = shiftKey = false;
	}

	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;
	else if (button == MOUSE_MIDDLE_BUTTON)
		midButton = down;
	///////////////////////////

		//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

		//print cell coordinates after click
	if (down) {
		int tipo = m_tablero->getTab()[xcas_sel][ycas_sel].getTipo();
		int color = m_tablero->getTab()[xcas_sel][ycas_sel].getColor();

		if (tipo == Objeto::REINA) {
			if (color == Objeto::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "RB" << endl;
			if (color == Objeto::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "RN" << endl;

		}
		if (tipo == Objeto::PEON) {
			if (color == Objeto::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "PB" << endl;
			if (color == Objeto::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "PN" << endl;
		}
		if (tipo == Objeto::REY) {
			if (color == Objeto::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "KB" << endl;
			if (color == Objeto::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "KN" << endl;
		}
		if (tipo == Objeto::CABALLO) {
			if (color == Objeto::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "CB" << endl;
			if (color == Objeto::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "CN" << endl;
		}
		if (tipo == Objeto::ALFIL) {
			if (color == Objeto::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "AB" << endl;
			if (color == Objeto::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "AN" << endl;
		}
		if (tipo == Objeto::TORRE) {
			if (color == Objeto::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "TB" << endl;
			if (color == Objeto::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "TN" << endl;
		}
		if (tipo == Objeto::CASILLA_VACIA) {
			
		}
		else{}
	}
}