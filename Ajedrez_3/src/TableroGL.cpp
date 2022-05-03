#include "TableroGL.h"
#include "herramientasgl.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "freeglut.h"


void TableroGL::init() {
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

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
	float glx, gly;
	switch (m_tablero->getTab()[i][j].getTipo()) {
		case Objeto::REINA_BLANCO:
			casillaCentral(i, j, glx, gly);
			glDisable(GL_LIGHTING);
			GLTools::Color(gltools::GREEN);
			glTranslatef(glx, gly, 0);
			glutSolidSphere((ancho / 2.0f) * 0.9f, 50, 50);
			glTranslatef(-glx, -gly, 0);
			glEnable(GL_LIGHTING);
			break;
		case Objeto::REINA_NEGRO:
			casillaCentral(i, j, glx, gly);
			glDisable(GL_LIGHTING);
			GLTools::Color(gltools::BLACK);
			glTranslatef(glx, gly, 0);
			glutSolidSphere((ancho / 2.0f) * 0.9f, 50, 50);
			glTranslatef(-glx, -gly, 0);
			glEnable(GL_LIGHTING);
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
	gluLookAt(centro_x, centro_y, dist, centro_x, centro_y, centro_z, 0, 1, 0);
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
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GLTools::Color(gltools::WHITE, 1.0f);
	glTranslatef(centro_x, centro_y, centro_z);
	glRectf(N * ancho / 2.0f, N * ancho / 2.0f, -N * ancho / 2.0f, -N * ancho / 2.0f);
	glTranslatef(-centro_x, -centro_y, -centro_z);
	glEnable(GL_LIGHTING);
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
	if (down)
		cout << "(" << xcas_sel << "," << ycas_sel << ")" << endl;
}