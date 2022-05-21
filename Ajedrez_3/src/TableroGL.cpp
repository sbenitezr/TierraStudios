#include "TableroGL.h"
#include "herramientasgl.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "freeglut.h"
#include "ETSIDI.h"
using namespace std;

TableroGL::TableroGL(Tablero* t) :m_tablero(t) {
	ancho = 1;
	N = t->getTamanio();
	dist = 2;
	centro_z = 0;
	modo = INICIO;
}

void TableroGL::selCasilla(Vector p) {
	m_tablero->getCas()[p.x][p.y].selCas();
}

bool TableroGL::enable(int x1, int x2, int y1, int y2) {
	if (((x2 || y2) < 0) || ((x2 || y2) > 7) || (x2 == x1) && (y2 == y1))
		return FALSE;
	else { return TRUE; }
}

bool TableroGL::movalfil(int x1, int x2, int y1, int y2) {
	int dif = abs(x2 - x1);
	if (abs(y2 - y1) != dif) return FALSE;
	else { return TRUE; }
}
bool TableroGL::movtorre(int x1, int x2, int y1, int y2) {
	if ((abs(x2 - x1) != 0) && abs(y2 - y1) != 0)
		return FALSE;
	else { return TRUE; }
}
bool TableroGL::movcaballo(int x1, int x2, int y1, int y2) {
	int dif = abs(x2 - x1);
	if ((dif > 3) || (dif < 1))
		return FALSE;
	else if ((dif == 1) && (abs(y2 - y1) != 2) || (dif == 2) && (abs(y2 - y1) != 1))
		return FALSE;
	else { return TRUE; }
}
bool TableroGL::movrey(int x1, int x2, int y1, int y2) {
	if (abs(x2 - x1) > 1 || abs(y2 - y1) > 1)
		return FALSE;
	else { return TRUE; }
}
bool TableroGL::movpeon(int x1, int x2, int y1, int y2, int color,int color2) {
	if ((x1 == 1) || (x1 == 6)) {
		if (color == Pieza::BLANCO) {
			if ((color2 == Pieza::NO_COLOR) && ((y2 - y1) == 0) && (((x2 - x1) == -2) || (x2 - x1) == -1))
				return TRUE;
			else if ((color2 == 1) && ((x2 - x1) == -1) && abs(y2 - y1) == 1)
				return TRUE;
			else
				return FALSE;
		}
		else if (color == Pieza::NEGRO) {
			if ((color2 == Pieza::NO_COLOR) && ((y2 - y1) == 0) && (((x2 - x1) == 2) || (x2 - x1) == 1))
				return TRUE;
			else if ((color2 == Pieza::BLANCO) && ((x2 - x1) == 1) && abs(y2 - y1) == 1)
				return TRUE;
			else
				return FALSE;
		}
		else
			return FALSE;
	}
	else {
		if (color == 0) {
			if ((color2 == -1) && ((y2 - y1) == 0) && ((x2 - x1) == -1))
				return TRUE;
			else
				return FALSE;
		}
		else if (color == 1) {
			if ((color2 == -1) && ((y2 - y1) == 0) && ((x2 - x1) == 1))
				return TRUE;
			else
				return FALSE;
		}
	}
}
void TableroGL::init() {
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	m_tablero->tableroInicio();
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
}

void TableroGL::tecla(unsigned char key)
{
	if (modo == INICIO) {
		if (key == 'j') {
			modo = JUGAR;
		}
		if (key == 's') {
			modo = FINAL;
		}
	}

	if (modo == JUGAR) {
		ETSIDI::stopMusica();
		
		if (key == 's') {
			modo = FINAL;
		}
		//ETSIDI::stopMusica();
		ETSIDI::play("sonidos/mola mucho este modo de juego.wav");
		ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
	}

	if (modo == FINAL) {
		ETSIDI::stopMusica();
		if (key == 'e') {
			exit(0);
		}
		if (key == 's') {
			exit(0);
		}
	}
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

void TableroGL::draw() {
	
	// PANTALLA DE INICIO

	if (modo == INICIO) {
		centro_x = 0;
		centro_y = 7.5;
		centro_z = 0;
		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(centro_x, centro_y, -20, centro_x, centro_y, centro_z, 0, 1, 0);
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//EL CENTRO DE LA IMAGEN ES EL (0, 7.5)
		//TIENE DIMENSIONES DE 20 ANCHO X 15 ALTO
		glTexCoord2d(0, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 0); glVertex2f(-10, 15);
		glTexCoord2d(0, 0); glVertex2f(10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::playMusica("sonidos/Musica Intro.mp3", true);

	}

	//PANTALLA DE JUEGO

	else if (modo == JUGAR) {

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

		//PINTADO DE PIEZAS
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				m_tablero->getCas()[i][j].getPieza()->draw();
			}
		}

		//Pinta el tablero (casillas)
		drawMatriz();
		if (inicio == TRUE)
		{
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					glTranslatef(i, -j, 0);
					if (i % 2 == 0 && j % 2 == 0)
					{
						m_tablero->getCas()[i][j].setColor(1);
						m_tablero->getCas()[i][j].draw();
					}
					if (i % 2 != 0 && j % 2 != 0)
					{
						m_tablero->getCas()[i][j].setColor(1);
						m_tablero->getCas()[i][j].draw();
					}
					else{ 
						m_tablero->getCas()[i][j].setColor(0);
						m_tablero->getCas()[i][j].draw(); }
					glTranslatef(-i, j, 0);
				}
			}
		}
		
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//EL CENTRO DE LA IMAGEN ES EL (0, 7.5)
		
	
		//TIENE DIMENSIONES DE 20 ANCHO X 15 ALTO
		glTexCoord2d(0, 1); glVertex2f(N * ancho + 4, -N * ancho - 4);
		glTexCoord2d(1, 1); glVertex2f(N * ancho + 4, 4);
		glTexCoord2d(1, 0); glVertex2f(-4, 4);
		glTexCoord2d(0, 0); glVertex2f(-4, -N * ancho - 4);
		glEnd();
		//Dibuja un rectangulo transparente sobre el tablero para capturar el raton
		//con gluUnProject
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		GLTools::Color(gltools::WHITE, 1.0f);
		glTranslatef(centro_x, centro_y, centro_z);
		glRectf(N * ancho / 2.0f, N * ancho / 2.0f, -N * ancho / 2.0f, -N * ancho / 2.0f);
		glTranslatef(-centro_x, -centro_y, -centro_z);
		glEnable(GL_LIGHTING);

		glDisable(GL_TEXTURE_2D);
	}

	//PANTALLA DE SALIDA

	else if (modo == FINAL) {

		//NO USADO AUN

	}
	
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
	///////////////////////////

		//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

		//print cell coordinates after click
	if (down) 
	{
		ETSIDI::play("sonidos/click.wav");
		switch (seleccion)
		{
			case FALSE: 
			{	
				seleccion = TRUE;	//para la alternancia de clicks
				cout << "Primer Click" << endl;

				//selCasilla(Vector(xcas_sel,ycas_sel));

				int tipo = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();
				int color = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();

				//QUEDA MUY FEO PERO ES POR POBAR
				xorig = xcas_sel;
				yorig = ycas_sel;

				if (tipo == Pieza::REINA)
				{
					ETSIDI::play("sonidos/la reina.wav");
					if (color == Pieza::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "RB" << endl;
					if (color == Pieza::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "RN" << endl;

				}
				if (tipo == Pieza::PEON)
				{
					if (color == Pieza::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "PB" << endl;
					if (color == Pieza::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "PN" << endl;
				}
				if (tipo == Pieza::REY)
				{
					if (color == Pieza::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "KB" << endl;
					if (color == Pieza::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "KN" << endl;
				}
				if (tipo == Pieza::CABALLO)
				{
					if (color == Pieza::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "CB" << endl;
					if (color == Pieza::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "CN" << endl;
				}
				if (tipo == Pieza::ALFIL)
				{
					if (color == Pieza::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "AB" << endl;
					if (color == Pieza::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "AN" << endl;
				}
				if (tipo == Pieza::TORRE)
				{
					if (color == Pieza::BLANCO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "TB" << endl;
					if (color == Pieza::NEGRO) cout << "(" << xcas_sel << "," << ycas_sel << ")" << "TN" << endl;
				}
				if (tipo == Pieza::CASILLA_VACIA)
				{
					cout << "vacio" << endl;
				}
				break;
			}

			case TRUE:
			{
				seleccion = FALSE;	//para la alternancia de clicks
				cout << "segundo click:" << endl;
				int tipo = m_tablero->getCas()[xorig][yorig].getPieza()->getTipo();
				int color = m_tablero->getCas()[xorig][yorig].getPieza()->getColor();
				int color2 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();

				if (tipo == Pieza::REINA)
				{
					if (((movalfil(xorig, xcas_sel, yorig, ycas_sel) == TRUE) || (movtorre(xorig, xcas_sel, yorig, ycas_sel) == TRUE)) && (enable(xorig, xcas_sel, yorig, ycas_sel) == TRUE)) {
						if (color == Pieza::BLANCO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::BLANCO));
						if (color == Pieza::NEGRO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					}
					else { break; }
				}
				if (tipo == Pieza::PEON)
				{
					if ((movpeon(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (enable(xorig, xcas_sel, yorig, ycas_sel) == TRUE)) {
						if (color == Pieza::BLANCO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::BLANCO));
						if (color == Pieza::NEGRO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					}
					else
						break;
				}
				if (tipo == Pieza::REY)
				{
					if ((movrey(xorig, xcas_sel, yorig, ycas_sel) == TRUE) && (enable(xorig, xcas_sel, yorig, ycas_sel) == TRUE)) {
						if (color == Pieza::BLANCO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Rey(Vector(xcas_sel, ycas_sel), Pieza::BLANCO));
						if (color == Pieza::NEGRO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Rey(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					}
					else { break; }
				}
				if (tipo == Pieza::CABALLO)
				{
					
					if ((movcaballo(xorig, xcas_sel, yorig, ycas_sel) == TRUE) && (enable(xorig, xcas_sel, yorig, ycas_sel) == TRUE)) {
						if (color == Pieza::BLANCO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::BLANCO));
						if (color == Pieza::NEGRO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					}
					else
						break;
				}
				if (tipo == Pieza::ALFIL)
				{
					if ((movalfil(xorig, xcas_sel, yorig, ycas_sel) == TRUE) && (enable(xorig, xcas_sel, yorig, ycas_sel) == TRUE)) {
						if (color == Pieza::BLANCO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::BLANCO));
						if (color == Pieza::NEGRO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					}
					else { break; }
				}
				if (tipo == Pieza::TORRE)
				{	
					if ((movtorre(xorig, xcas_sel, yorig, ycas_sel) == TRUE) && (enable(xorig, xcas_sel, yorig, ycas_sel) == TRUE)) {
						if (color == Pieza::BLANCO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::BLANCO));
						if (color == Pieza::NEGRO) m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					}
					else { break; }
				}
				if (tipo == Pieza::CASILLA_VACIA)
				{
					cout << "vacio" << endl;
				}

				//Pieza anterior a NoPieza
				m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
				xorig = 0;
				yorig = 0;
				break;
			}
			default:
				;
		}
	}
}